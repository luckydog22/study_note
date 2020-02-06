#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <unistd.h>

void *rec_thread()
{
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 3)
    {
        perror("socket");
        return;
    }

    struct sockaddr_in myaddr, youaddr;
    myaddr.sin_family = AF_INET;
    myaddr.sin_port = htons(23689);
    myaddr.sin_addr.s_addr = inet_addr(INADDR_ANY);
    if (bind(sockfd, (struct sockaddr *)&myaddr, 16) < 0)
    {
        perror("bind");
        return;
    }

    char buf[1024] = {0};
    int len = sizeof(youaddr);
    while (1)
    {
        for (int i = 0; i < 1024; i++)
        {
            buf[i] = 0;
        }

        recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&youaddr, &len);
        printf("接受：%s\n", buf);
    }

    close(sockfd);
}

void *send_thread()
{
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 3)
    {
        perror("socket");
        return;
    }

    struct sockaddr_in toaddr;
    toaddr.sin_family = AF_INET;
    toaddr.sin_port = htons(23689);
    toaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    char buf[1024] = {0};
    int len = sizeof(toaddr);
    while (1)
    {
        printf("发送：");
        scanf("%s", buf);
        sendto(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&toaddr, len);
        for (int i = 0; i < 1024; i++)
        {
            buf[i] = 0;
        }
        sleep(1);
    }

    close(sockfd);
}

pthread_mutex_t mutex;

void *input1_thread()
{
    while (1)
    {
        char buf[30];
        pthread_mutex_lock(&mutex);
        scanf("%s",buf);
        printf("Input1: %s\n",buf);
        pthread_mutex_unlock(&mutex);
        usleep(10);
    }
}

void *input2_thread()
{
    while (1)
    {
        char buf[30];
        pthread_mutex_lock(&mutex);
        scanf("%s",buf);
        printf("Input2: %s\n",buf);
        pthread_mutex_unlock(&mutex);
        usleep(10);
    }
}

int main(char argc, char argv[])
{
    pthread_t id1;
    pthread_t id2;
    pthread_create(&id1, NULL, input1_thread, NULL);
    pthread_create(&id2, NULL, input2_thread, NULL);
    while (1);
    return 0;
}