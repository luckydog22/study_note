#include "msg.h"
#include <time.h>

sqlite3 *db = NULL;

void do_register(int connfd, MSG msg)
{
	char sql[1024];
	char *errmsg = NULL;
	sprintf(sql, "insert into user values('%s', '%s')", msg.name, msg.data);
	if (0 != sqlite3_exec(db, sql, NULL, NULL, &errmsg)) {
		fprintf(stderr, "register insert: %s\n", errmsg);
		strcpy(msg.data, errmsg);
	} else
		strcpy(msg.data, "OK");

	if (0 > send(connfd, (char*)&msg, sizeof(msg), 0)) {
		perror("register send");
		return;
	}
}

void do_login(int connfd, MSG msg)
{
	char sql[1024];
	char *errmsg = NULL;
	char **resultp = NULL;
	int nrow, ncolumn;
		
	sprintf(sql, "select * from user where name = '%s'", msg.name);	
	if (0 != sqlite3_get_table(db, sql, &resultp, &nrow, &ncolumn, &errmsg)) {
		fprintf(stderr, "login usrname: %s\n", errmsg);
		strcpy(msg.data, errmsg);
	} else {
		if (0 == nrow) {   //usrname select failed!
			strcpy(msg.data, "No such usrname!");
		} else {   //usrname select success!
			sprintf(sql, "select * from user where name ='%s' and passwd = '%s'", msg.name, msg.data);
			if (0 != sqlite3_get_table(db, sql, &resultp, &nrow, &ncolumn, &errmsg)) {
				fprintf(stderr, "login passwd: %s\n", errmsg);
				strcpy(msg.data, errmsg);
			} else {
				if (0 == nrow) {
					strcpy(msg.data, "passwd is error!");				
				} else
					strcpy(msg.data, "OK");
			}
		}
	}

	if (0 > send(connfd, (char*)&msg, sizeof(msg), 0)) {
		perror("send");
		return;
	}
}

void do_query(int connfd, MSG msg)
{
#if 0
	time_t t;
	char sql[1024];
	char *errmsg = NULL;
	int nrow, ncolumn;
	char **resultp = NULL;
	sprintf(sql, "select * from dict where word = '%s'", msg.data);
	if (0 != sqlite3_get_table(db, sql, &resultp, &nrow, &ncolumn, &errmsg)) {
		fprintf(stderr, "word query: %s\n", errmsg);
		strcpy(msg.data, errmsg);
	} else {
		if (0 == nrow) 
			strcpy(msg.data, "No such word!");
		else {
			time(&t);
			sprintf(sql, "insert into history values('%s', '%s', '%s')", msg.name, msg.data, ctime(&t));
			strcpy(msg.data, resultp[3]);
			if (0 != sqlite3_exec(db, sql, NULL, NULL, &errmsg)) {
				fprintf(stderr, "insert history: %s\n", errmsg);
			}
		}			
	}

#else
	FILE *fp;
	time_t t;
	char sql[1024];
	char *errmsg = NULL;
	char buf[1024];
	char word[N];
	char explain[SIZE];
	int i;
	char *p;
	int j = 0;
	if (NULL == (fp = fopen("dict.txt", "r"))) {
		perror("fopen dict");
		strcpy(msg.data, "dict open failed");
		goto err;
	}
	while (1) {
		if ((NULL == fgets(buf, sizeof(buf), fp)) || (buf[0] > msg.data[0])) {
			strcpy(msg.data, "No such word");
			break;
		}
		i = 0;
		p = buf;
		while (' ' != *p) {
			word[i++] = *p;
			p++;
		}
		word[i] = '\0';
		//printf("word = %s, %s\n", word, msg.data);
		
		if (strcmp(word, msg.data) == 0) {
			while (' ' == *p)
				p++;
			strcpy(explain, p);
			explain[strlen(explain)-2] = '\0';
			time(&t);
			sprintf(sql, "insert into history values('%s', '%s', '%s')", msg.name, msg.data, ctime(&t));
			sqlite3_exec(db, sql, NULL, NULL, &errmsg);
			strcpy(msg.data, explain);
			break;
		}
	}
#endif

err:
	if (0 > send(connfd, (char*)&msg, sizeof(msg), 0)) {
		perror("query send");
	}
}

void do_history(int connfd, MSG msg)
{
	char sql[1024];
	char *errmsg = NULL;
	char **resultp = NULL;
	int nrow, ncolumn;
	int i, j;
	int index;
	sprintf(sql, "select word,time from history where name = '%s'", msg.name);
	if (0 != sqlite3_get_table(db, sql, &resultp, &nrow, &ncolumn, &errmsg)) {
		fprintf(stderr, "history select: %s\n", errmsg);
	} else {
		index = 2;
		printf("nrow = %d\n", nrow);
		for (i = 1; i < nrow+1; i++) {
			sprintf(msg.data, "%d %-15s %s", index, resultp[index], resultp[index+1]);
			puts(msg.data);
			index += 2;
			send(connfd, (char*)&msg, sizeof(msg), 0);
		}
	}
	strcpy(msg.data, "###end###");
	if (0 > send(connfd, (char*)&msg, sizeof(msg), 0)) {
		perror("send");
		return;
	}
}

void do_client(int connfd)
{
	//1.接收客户端的请求，根据请求执行的不同的动作
	MSG msg;
	while (1) {
		if (0 >= recv(connfd, (char *)&msg, sizeof(msg), 0)) {
			perror("recv msg");
			break;
		}
		switch (msg.type) {
			case R:
				do_register(connfd, msg);
				break;
			case L:
				do_login(connfd, msg);
				break;
			case Q:
				do_query(connfd, msg);
				break;
			case H:
				do_history(connfd, msg);
				break;
		}
	}
}

void handler(int sigo)
{
	while (waitpid(-1, NULL, WNOHANG) > 0);
}

int main()
{
	pid_t pid;
	int on = 1;
	char *errmsg = NULL;
	char sql[1024];
	int sockfd, connfd;
	SAI myaddr, cliaddr;
	int addrlen = sizeof(cliaddr);

	//创建并打开数据库
	if (0 != sqlite3_open("dict.db", &db)) {
		fprintf(stderr, "sqlite3_open: %s\n", sqlite3_errmsg(db));
		return -1;
	}

	//创建库中需要的表: dict user history  
	sprintf(sql, "create table if not exists user(name text primary key, passwd text)");
	if (0 != sqlite3_exec(db, sql, NULL, NULL, &errmsg)) {
		fprintf(stderr, "create user: %s\n", errmsg);
		return -1;
	}

	sprintf(sql, "create table if not exists history(name text, word text, time text)");
	if (0 != sqlite3_exec(db, sql, NULL, NULL, &errmsg)) {
		fprintf(stderr, "create history: %s\n", errmsg);
		return -1;
	}

	//接收客户端的连接
	if (0 > (sockfd = socket(AF_INET, SOCK_STREAM, 0))) {
		perror("socket");
		return -1;
	}
	
	//设置允许重用本地地址和端口
	if (0 > setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on))) {   
		perror("setsockopt");
		return -1;
	}

	memset(&myaddr, 0, sizeof(myaddr));
	myaddr.sin_family 		= AF_INET;
	myaddr.sin_port 		= htons(8888);
	myaddr.sin_addr.s_addr 	= htonl(INADDR_ANY);
	
	if (0 > bind(sockfd, (SA*)&myaddr, sizeof(myaddr))) {
		perror("bind");
		return -1;
	}

	if (0 > listen(sockfd, 1024)) {
		perror("listen");
		return -1;
	}

	signal(SIGCHLD, handler);    //设置信号处理方式

	while (1) {
		connfd = accept(sockfd, (SA *)&cliaddr, &addrlen);
		if (connfd < 0) {
			perror("accept");
			break;
		}
		printf("accept client: %s\n", inet_ntoa(cliaddr.sin_addr));

		pid = fork();	    //并发服务器	
		if (pid < 0) {
			perror("fork");
			break;
		} else if (0 == pid) {  //子进程
			close(sockfd);
			do_client(connfd);
			close(connfd);	
			exit(0);
		}
		close(connfd);
	}

	return 0;
}
