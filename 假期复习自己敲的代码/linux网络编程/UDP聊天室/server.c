#include<stdio.h>//printf
#include<stdlib.h>//malloc
#include<sys/socket.h>//创建套接字
#include<netinet/in.h>//字节序转换
#include<arpa/inet.h>//字节序转换
#include<string.h>//strcpy
//创建用户列表
typedef struct client
{
    struct sockaddr_in client[100];
    int last;
}client;
//创建收消息结构
typedef struct msg
{
    int type;
    char data[1024];
}msg;
//创建用户表
client* create_table()
{
    client *c = (client *)malloc(sizeof(client));
    c->last = 0;
    return c;
}
//上线用户入表
void enter_table(client* p,struct sockaddr_in clientaddr)
{
    p->client[p->last++] = clientaddr;
    return;
}
//离线用户出表
void delete_client(client *p,struct sockaddr_in clientaddr)
{
    int i,j;
    for( i = 0; i<p->last; i++)
    {
        if( p->client[i].sin_addr.s_addr == clientaddr.sin_addr.s_addr &&
        p->client[i].sin_port == clientaddr.sin_port)
        {
            //让后面的逐渐覆盖掉
            for( j = i;j<p->last-1;j++ )
            {
                p->client[j] = p->client[j+1];
            }
            //数量减一
            p->last--;
            break;
        }
    }
    return;
}
//转发给所有人消息
void send_info(client *p,struct sockaddr_in clientaddr,int sockfd,msg *m)
{
    int i;
    for( i = 0;i<p->last;i++ )
    {
        //不将自己的信息发给自己
        if( p->client[i].sin_addr.s_addr == clientaddr.sin_addr.s_addr &&
        p->client[i].sin_port == clientaddr.sin_port)
        {
            continue;
        }
        sendto(sockfd,m,sizeof(*m),0,(struct sockaddr*)&(p->client[i]),16);
    }
}
//发消息
int main()
{
    //创建用户列表
    client *p = create_table();
    //创建套接字
    int sockfd = socket(AF_INET,SOCK_DGRAM,0);
    if( sockfd<0 )
    {
        perror("sockfd");
        return -1;
    }
    //绑定
    struct sockaddr_in myaddr,clientaddr;
    myaddr.sin_family = AF_INET;
    myaddr.sin_port = htons(33660);
    myaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    if ( bind(sockfd,(struct sockaddr*)&myaddr,sizeof(myaddr) )<0 )
    {
        perror("sockfd");
        return -1;
    }

    msg buf;
    int len = sizeof(clientaddr);
    while(1)
    {
        bzero(&buf,sizeof(buf));
        recvfrom(sockfd,&buf,sizeof(buf),0,(struct sockaddr*)&clientaddr,&len);
        printf("%d               type:%d\n",ntohs(clientaddr.sin_port),buf.type);
        if( buf.type == 1 )
        {
            sprintf(buf.data,"%d              login\n",ntohs(clientaddr.sin_port));
            enter_table(p,clientaddr);
        }
        else if(buf.type == 2)
        {
            sprintf(buf.data,"%d              login\n",ntohs(clientaddr.sin_port));
            delete_client(p,clientaddr);     
        }
        else if( buf.type == 3)
        {
            char a[1024];
            strcpy(a,buf.data);
            sprintf(buf.data,"%d:%s\n",ntohs(clientaddr.sin_port),a);
        }
        send_info(p,clientaddr,sockfd,&buf);
    }
}



