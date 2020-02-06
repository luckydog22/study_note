
一。tcp/ip模型
1.模型
osi模型：
应表会 传 网 数物

tcp/ip模型
应 传 网 网

2. 边界特性
1.）地址
2.）操作系统

3.协议的选择
1.）可靠性
2.）时延
3.）网不好

4.套接字类型

5.端口的选用 原则

6.ip地址分类

7.






低行 /。。。 查找。。。
vi /usr/include/netinet/in.h
有几个二进制0，二的几次方


套接字
类型：

1./socket
<sys/types.h>
<sys/socket.h>
int sockfd=socket(AF_INET,SOCK_DGRAM,0); 
参1：协议族，（ipv4）
参2：套接字类型()
参3：0  (原始套接字除外)

2./ip 转换
<sys/socket.h>
<netinet/in.h>
<arpa/inet.h>
(1)/10->16
struct in_addr a;
inet_aton("192.168.1.1",&a);

printf("%#x\n",inet_addr("192.168.1.1"));

(2)/16->10
3.
/ipv4地址结构
struct in_addr{
in_addr_t s_addr;	
}

/internet协议地址结构
struct sockaddr_in 
{
	unsigned short sin_family;  /
	unsigned short sin_port     /ip地址
	struct in_addr sin_addr;    /
	unsigned char size_zero[8];	
}

4./字节序
4.1/大小端
4.2/
网络字节序： 大端字节序。 
主机字节序： 大部分是小端字节序。 
4.3/
htons();      // 主机序 转 网络序  （端口）

5./udp
******双方写的ip地址，都是接收方的地址
******接收方的最后一个是长度的地址
(1)发送
创建套接字描述符   
指定对方ip 和 端口  
发送消息   
关闭 socket  

int sockfd=socket(AF_INET,SOCK_DGRAM,0);

struct sockaddr_in  toaddr;
toaddr.sin_family = AF_INET; 
toaddr.sin_port = htons(23456);
toaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
 
char buf[100] = "Hello xiaoming~";
sendto(sockfd, buf, sizeof(buf),0, (struct sockaddr *)&toaddr,16);    
	
(2)接受
创建套接字描述符   
绑定自己地址和 端口   
接收消息 
关闭 socket

int sockfd = socket(AF_INET, SOCK_DGRAM, 0);    // 创建套接字描述符

struct sockaddr_in myaddr,youaddr;    
myaddr.sin_family = AF_INET;                
myaddr.sin_port = htons(23456);
myaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
if(bind(sockfd, (struct sockaddr *)&myaddr,16) < 0 )      // 绑定自己 地址结构 和 套接字
	{
		perror("bind");
		return -1;
	}

int len = sizeof(struct sockaddr);
char buf[100] = {0};
recvfrom(sockfd,buf,sizeof(buf),0, (struct sockaddr *)&youaddr, &len);      //接收   











