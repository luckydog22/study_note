#include "msg.h"

void do_register(int sockfd)
{

}

int do_login(int sockfd)
{

	return 0;
}

void do_query(int sockfd)
{

}

void do_history(int sockfd)
{

} 

int main(int argc, char *argv[])
{
	char order[N];
	int sockfd;
	SAI srvaddr;

	if (argc < 2) {
		fprintf(stderr, "Usage: <%s> <SRVIP>\n", argv[0]);
		return -1;
	}

	if (0 > (sockfd = socket(AF_INET, SOCK_STREAM, 0))) {
		perror("socket");
		return -1;
	}
	
	memset(&srvaddr, 0, sizeof(srvaddr));
	srvaddr.sin_family 		= AF_INET;
	srvaddr.sin_port   		= htons(8888);
	srvaddr.sin_addr.s_addr = inet_addr(argv[1]);
	
	if (0 > connect(sockfd, (SA *)&srvaddr, sizeof(srvaddr))) {
		perror("connect");
		return -1;
	}

	while (1) {
		printf("**********************************\n");
		printf("1.register   2.login    3.exit\n");
		printf("**********************************\n");
		printf("Please choose(1-3): ");
		fgets(order, sizeof(order), stdin);
		
		switch (order[0]) {
			case '1':
				do_register(sockfd);   //注册
				break;
			case '2':
				if (1 == do_login(sockfd)) //当返回值等于1，表示登录成功
					goto next;
				break;
			case '3':
				close(sockfd);
				exit(0);
				break;
			default:
				fprintf(stderr, "Input num error, again!");
				break;
		}
	}

next:
	while (1) {
		printf("*****************************************\n");
		printf("1.query word   2.history record   3.exit\n");
		printf("*****************************************\n");
		printf("Please choose num(1-3): ");
		fgets(order, sizeof(order), stdin);
		
		switch (order[0]) {
			case '1':
				do_query(sockfd);
				break;
			case '2':
				do_history(sockfd);
				break;
			case '3':
				close(sockfd);
				exit(0);
				break;
			default:
				fprintf(stderr, "Input error, again!\n");
				break;
		}
	}

	return 0;
}
