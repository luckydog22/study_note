#include "msg.h"

void do_register()
{

}

void do_login()
{

}

void do_query()
{

}

void do_history()
{

}

void do_client(int connfd)
{
	//1.接收客户端的请求，根据请求执行的不同的动作
	MSG msg;
	while (1) {
		recv(msg);
		switch (msg.type) {
			case R:
				do_register();
				break;
			case L:
				do_login();
				break;
			case Q:
				do_query();
				break;
			case H:
				do_history();
				break;
		}
	}
}

int main()
{
	pid_t pid;
	//创建并打开数据库
	sqlite3_open();

	//创建库中需要的表: dict user history  
	sqlite3_exec();

	//接收客户端的连接
	int sockfd = socket();
	setsockopt();   //设置允许重用本地地址和端口
	bind();
	listen();
	signal();    //设置信号处理方式

	while (1) {
		connfd = accept();
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
