#include "msg.h"

sqlite3 *db = NULL;

void do_register(int connfd, MSG msg)
{

}

void do_login(int connfd, MSG msg)
{

}

void do_query(int connfd, MSG msg)
{

}

void do_history(int connfd, MSG msg)
{

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
