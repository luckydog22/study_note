

一、随堂小测验
1. tcp/ip 协议的四个层次 ？     应用层、传输层、网络层、网络接口层。 
2. udp 通信步骤 ？ 
		发送： socket();  toaddr   sendto();   close();    // sendto(sockfd,buf,sizeof(buf),0,(struct sockaddr *)&toaddr,16);      
		接收： socket();  bind();  recvfrom(); close();    // recvfrom(sockfd,buf,sizeof(buf),0,(struct sockaddr *)&youaddr,&len);
 
3. 路由器为数据包选择路由是根据哪一层的协议 ？   网络层、 IP协议  
4. 哪个协议用于通过域名得到IP地址 ？             DNS 
5. 哪个协议用于动态分配ip地址 ？                 DHCP
6. tcp 与 udp 属于协议模型中的哪一层 ？ 异同点 ？    传输层   
不同： 
tcp : 面向连接的、可靠的传输协议。 
udp : 无连接的、不可靠的传输协议。 

7. 什么是 大端字节序？ 小端字节序？ 如何检测字节序是大端还是小端（代码实现）
大端： 高位地址保存低位字节。  
小端： 高 高   低  低   。  



二、 作业： 
//////////////////////
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>

int sockfd;
struct sockaddr_in myaddr, toaddr;
int len = sizeof(struct sockaddr);

// 接收消息的线程。 
void *fun()
{
	char buf[128] = {0};
	while(1)
	{
		bzero(buf,sizeof(buf));
		recvfrom(sockfd,buf,sizeof(buf),0,NULL,NULL);    // 循环接收即可。 
		printf("%s",buf);
		fflush(stdout);
	}
}
// 主程序  
int main(int argc,char *argv[])
{
	if(argc < 3)
	{
		printf("%s my-port  your-port\n",argv[0]);     // 传参指定双方端口  
		return -1;
	}
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);     // 创建套接字描述符   
	if(sockfd < 0)
	{
		perror("socket");
		return -1;
	}

	myaddr.sin_family = AF_INET; 
	myaddr.sin_port = htons(atoi(argv[1]));
	myaddr.sin_addr.s_addr = htonl(INADDR_ANY);  // INADDR_ANY : 跟随系统。（自动使用当前主机ip值）  

	if(bind(sockfd, (struct sockaddr *)&myaddr, len) < 0)    // 因为要接收消息，所以要绑定 
	{
		perror("bind");
		return -1;
	}
	
	toaddr.sin_family = AF_INET;
	toaddr.sin_port = htons(atoi(argv[2]));
	toaddr.sin_addr.s_addr = inet_addr("127.0.0.1");    // 指定对方ip和端口。 

	pthread_t id;
	pthread_create(&id,NULL,fun,NULL);    // 创建接收线程。 

	char buf[128];
	while(1)
	{
		bzero(buf,sizeof(buf));
		fgets(buf,sizeof(buf),stdin);      // 输入  
		sendto(sockfd, buf,strlen(buf)+1,0,(struct sockaddr *)&toaddr,len);  // 发送线程。 
	}

	pthread_join(id,NULL);
	close(sockfd);
	return -1;
}
执行过程： 
gcc chat.c -o chat -lpthread 
./chat 12345 9999 
./chat 9999  12345 




三、 练习： UDP实现：局域网聊天室 

服务器端：  中转消息  
客户端： 
1. 用户端启动：给服务器发送上线消息
2. 用户端输入：logout  下线
3. 用户端输入其他，都是聊天内容

建议：构建消息结构。  
struct msg
{
	int type;         // 1. 上线。 2. 下线  3. 聊天信息。
	char buf[100];    //    消息 
};

demo 
///// server.c ///////
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
typedef struct         // 客户列表结构（ 顺序表 ）  
{
	struct sockaddr_in client[100];     // 保存 在线客户 的 网络地址结构 
	int last;                           // 保存 在线客户 的 数量
}client_t;
typedef struct         // 消息结构   
{
	long type;         // 消息类型： 1.上线  2.下线   3.聊天 
	char data[128];    // 消息正文。
}msg_t;
// 创建客户列表  
client_t *create_client_list()
{
	 client_t *p = (client_t *)malloc(sizeof(client_t));
	 p->last = 0;
	 return p;
}
// 将上线的客户添加到数组中
void add_client(client_t *L,struct sockaddr_in youaddr)
{
	L->client[L->last++] = youaddr; 
	return ;
}
// 即将离线的客户，从列表中删除。
void delete_client(client_t *L,struct sockaddr_in youaddr)
{
	int i,j;
	for(i=0; i<L->last; i++)
	{
		if( L->client[i].sin_port == youaddr.sin_port  && L->client[i].sin_addr.s_addr == youaddr.sin_addr.s_addr)     
		{
			for(j=i; j<L->last-1; j++)
				L->client[j] = L->client[j+1];     // 循环移位，将下线客户信息覆盖掉。 
			L->last --;				             // 在线数量 -1 
			break; 
		}
	}
	return ;
}
// 中转。 server群发消息。 
void send_info(client_t *L,struct sockaddr_in youaddr,int sockfd,msg_t *m)
{
	int i;
	for(i=0; i<L->last; i++)
	{
		if(L->client[i].sin_addr.s_addr == youaddr.sin_addr.s_addr && L->client[i].sin_port == youaddr.sin_port) 
			continue;
		sendto(sockfd, m, sizeof(msg_t), 0, (struct sockaddr *)&L->client[i],16);
	}
}
// 主程序 
int main()
{
	client_t *L = create_client_list();    // 创建 空 客户列表  

	int sockfd = socket(AF_INET, SOCK_DGRAM, 0);   // 1. 创建 socket 套接字
	if(sockfd < 0)
	{
		perror("socket");
		return -1;
	}
	
	struct sockaddr_in myaddr, youaddr; 
	myaddr.sin_family = AF_INET; 
	myaddr.sin_port = htons(9999);
	myaddr.sin_addr.s_addr = htonl(INADDR_ANY);

	int len = sizeof(struct sockaddr );
	if(bind(sockfd, (struct sockaddr *)&myaddr, len))    // 2. 绑定 ip、端口
	{
		perror("bind");
		return -1;
	}
	
	msg_t msg;
	while(1)
	{
		bzero(&msg,sizeof(msg));
		recvfrom(sockfd, &msg, sizeof(msg), 0, (struct sockaddr *)&youaddr, &len);   // 3. 收消息  
		printf("%d    type: %ld\n",ntohs(youaddr.sin_port),msg.type);
		if(msg.type == 1 )                                                 // 4. 根据不同类型，分发消息  
		{
			sprintf(msg.data,"%d  login\n",ntohs(youaddr.sin_port));
			add_client(L,youaddr);
		}
		else if(msg.type == 2)
		{
			sprintf(msg.data,"%d  logout\n",ntohs(youaddr.sin_port));
			delete_client(L,youaddr);   
		}
		else if(msg.type == 3)
		{
			char buf[128]; 
			strcpy(buf,msg.data);
			sprintf(msg.data,"%d: %s\n",ntohs(youaddr.sin_port),buf);
		}
		send_info(L,youaddr,sockfd,&msg);
	}
}


///// client.c ///////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>
typedef struct             // 消息结构  
{
	long type;
	char data[128];
}msg_t;

// 收消息线程。 
void *recv_info(void *p)
{
	int sockfd = *(int *)p;
	msg_t buf;
	while(1)
	{
		bzero(&buf,sizeof(buf));
		recvfrom(sockfd,&buf,sizeof(buf),0,NULL,NULL);
		printf("%s",buf.data);
		fflush(stdout);
	}
}
// 主线程  
int main(int argc,char *argv[])
{
	if(argc < 2)
	{
		printf("%s my-port \n",argv[0]);     // 指定自己端口  
		return -1;
	}
	int sockfd = socket(AF_INET, SOCK_DGRAM, 0);   // 1. 创建 socket 套接字  
	if(sockfd < 0)
	{
		perror("socket");
		return -1;
	}
	
	struct sockaddr_in myaddr, server_addr;
	int len = sizeof(struct sockaddr);

	myaddr.sin_family = AF_INET; 
	myaddr.sin_port = htons(atoi(argv[1]));
	myaddr.sin_addr.s_addr = htonl(INADDR_ANY);

	if(bind(sockfd, (struct sockaddr *)&myaddr, len) < 0)     // 2. 绑定。  ip/端口 和 套接字 进行绑定
	{
		perror("bind");
		return -1;
	}
	
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(9999);
	server_addr.sin_addr.s_addr = inet_addr("192.168.1.12");   // 此 ip,一定要写服务器 ip 

	pthread_t id;
	pthread_create(&id,NULL,recv_info,(void *)&sockfd);        // 开 收消息 线程。 

	msg_t buf = {1,"login"};
	sendto(sockfd,&buf,sizeof(buf),0,(struct sockaddr *)&server_addr,len);   // 向服务器发送上线通知  
	
	while(1)
	{
		bzero(&buf,sizeof(buf));
		fgets(buf.data,sizeof(buf.data),stdin);     // 根据输入内容，决定消息类型。 
		if( !strncmp(buf.data,"logout",6) )         // 如果是退出，则消息类型 为 2 。 
		{
			buf.type = 2;
			sendto(sockfd,&buf,sizeof(buf),0,(struct sockaddr *)&server_addr,len);   // 发送消息。 然后下线。 
			exit(0);
		}
		else                // 否则，认定为聊天，则消息类型为3. 
		{
			buf.type = 3;
			sendto(sockfd,&buf,sizeof(buf),0,(struct sockaddr *)&server_addr,len);   // 发送消息给服务器，等待服务器群发。 
		}
	}
}




四、 tcp        -- 面向连接的、可靠的传输协议

1.特点：
a.发送数据之前，先确认对方在不在线 
b. 发送过程中，如果有数据出错，重传 
c. 3次握手、 4次挥手


2.服务器端：  
（1）步骤： 
	创建socket套接字    socket 
	绑定       			bind 
	监听       			listen 
	等待连接   			accept 
	收发消息   			recv/send
	关闭       			close 

（2）具体实现： 
(1)  int sockfd = socket(...);
(2)  bind();

(3)*  listen();
函数原型：  int listen(int sockfd, int backlog);
参数：		sockfd       套接字描述符
			backlog      指定了正在等待连接的最大队列长度，它的作用在于处理可能同时出现的几个连接请求。
返回值：成功： 0     失败： -1 

(4)*  accept();
函数原型： int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
参数：      sockfd   ： 套接字描述符 
			addr     :  对方地址。 
			addrlen  :  地址长度
返回值： 成功： 连接套接字。 
		 失败：-1 
示例：   int connfd = accept(sockfd, &addr, &len);

(5)  recv()/send() 
函数原型：
	ssize_t send(int sockfd, const void *buf, size_t len, int flags);
	ssize_t recv(int sockfd, void *buf, size_t len, int flags);

(6)  close(connfd);



3.客户端：  
（1）步骤：  
	创建 socket 套接字    socket 
	主动建立连接          connect 
	收发消息              recv/send 
	关闭                  close 

（2）具体过程： 
(1)  socket(...);
(2)* connect();
函数原型：  int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
参数：      sockfd  : 套接字描述符 
			addr    : 对方地址（server_ip）
			addrlen : 地址长度 
返回值： 成功：0   失败：-1 

(3)  recv()/send();
(4)  close();

示例代码： 
/////// server.c ///////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>
int main()
{
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);    // 注意！ 是流式套接字    1. 创建描述符  
	if(sockfd < 0)
	{
		perror("socket");
		return -1;
	}
	
	struct sockaddr_in myaddr,youaddr;
	int len = sizeof(struct sockaddr);

	myaddr.sin_family = AF_INET; 
	myaddr.sin_port = htons(9999);
	myaddr.sin_addr.s_addr = htonl(INADDR_ANY);

	if(bind(sockfd, (struct sockaddr *)&myaddr, len) < 0)    // 2. 绑定 
	{
		perror("bind");
		return -1;
	}
	listen(sockfd, 5);       // 3. 监听  

	int connfd = accept(sockfd, (struct sockaddr *)&youaddr,&len);  
	// 4. 建立连接。 注意！！此处创建了新的描述符！！！连接描述符。 
	if(connfd < 0)
	{
		perror("accept");
		return -1;
	}

	char buf[128] = {0};
	recv(connfd, buf, sizeof(buf), 0);     // 5. 收发消息  
	send(connfd, buf, sizeof(buf), 0);

	close(connfd);
	close(sockfd);
	return 0;
}


/////////// client.c /////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>
int main(int argc,char *argv[])
{
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);      // 1. 创建描述符  
	if(sockfd < 0)
	{
		perror("socket");
		return -1;
	}
	
	struct sockaddr_in myaddr,youaddr;
	int len = sizeof(struct sockaddr);

	myaddr.sin_family = AF_INET; 
	myaddr.sin_port = htons(7777);
	myaddr.sin_addr.s_addr = htonl(INADDR_ANY);

	if(bind(sockfd, (struct sockaddr *)&myaddr, len) < 0)     // 2. 绑定  
	{
		perror("bind");
		return -1;
	}

	youaddr.sin_family = AF_INET; 
	youaddr.sin_port = htons(9999);
	youaddr.sin_addr.s_addr = inet_addr("127.0.0.1");   // 注：此位置要写 server 端 ip 
	int n = connect(sockfd, (struct sockaddr *)&youaddr,16);     //3. 发起连接请求    
	if(n < 0)
	{
		perror("connect");
		return -1;
	}

	char buf[128] = "hello server";
	char buf1[128] = {0};
	send(sockfd, buf, sizeof(buf), 0);    // 4. 收发消息   
	sleep(1);
	recv(sockfd, buf1, sizeof(buf), 0);
	printf("recv : %s\n",buf1);

	close(sockfd);
	return 0;
}


//思考： 如果服务器连接多个客户端，如何连接不丢数据，也不影响其他客户连接？
//预习： 循环服务器、并发服务器、IO多路复用、网络超时检测函数  

// 作业： 做好复习、预习工作。 及时复习！不要掉队！！




