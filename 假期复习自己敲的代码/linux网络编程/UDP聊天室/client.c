#include<stdio.h>
#include<sys/socket.h>//套接字
#include<netinet/in.h>//字节序转换
#include<arpa/inet.h>//字节序转换 
#include<string.h>//strncmp  bzero
#include<pthread.h>//线程
#include<stdlib.h>//bzero
#include<unistd.h>//bzero
//定义消息结构
typedef struct chat_client
{
    int type;
    char data[128];
}msg;
//收消息的线程
void *rec_info(void *p)
{
    int sockfd = *(int *)p;
    msg buf;
    while(1)
    {
        bzero(&buf,sizeof(buf));
        recvfrom(sockfd,&buf,sizeof(buf),0,NULL,NULL);
        printf("%s",buf.data);
        fflush(stdout);
    }
}
//主线程(发送)
int main()
{
    //创捷套接字
    int sockfd = socket(AF_INET,SOCK_DGRAM,0);
    if(sockfd<0)
    {
        perror("sockfd");
        return -1;
    }
    //因为需要接收，则需绑定
    struct sockaddr_in myaddr,seraddr;
    myaddr.sin_family = AF_INET;
    myaddr.sin_port = htons(22330);
    myaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    if( bind(sockfd,(struct sockaddr*)&myaddr,sizeof(myaddr))<0 )
    {
        perror("bind");
        return -1;
    }
    //
    seraddr.sin_family = AF_INET;
    seraddr.sin_port = htons(33660);
    seraddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    //定义线程id，创建收消息线程，阻塞
    int len = sizeof(seraddr);
    pthread_t id;
    pthread_create(&id,NULL,rec_info,(void *)&sockfd);

    //告诉服务器上线了
    msg buf = {1,"login"};
    sendto(sockfd,&buf,sizeof(buf),0,(struct sockaddr*)&seraddr,len);
    //发送消息
    while(1)
    {
        //发之前先清空
        bzero(&buf,sizeof(buf));
        //将输入的内容到data中
        fgets(buf.data,sizeof(buf),stdin);
        if( !strncmp(buf.data,"logout",6) )//相等返回0，取非真假对调
        {
            buf.type = 2;
            sendto(sockfd,&buf,sizeof(buf),0,(struct sockaddr *)&seraddr,len); 
            //将缓冲区的内容弹出，同时推出
            exit(0);
        }
        else
        {
            buf.type = 3;
            sendto(sockfd,&buf,sizeof(buf),0,(struct sockaddr *)&seraddr,len);
        }
    }
}