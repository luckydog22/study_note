ipc 通信：信号量  共享内存  消息队列
一.线程  
*创建
#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet.h>
#include<arpa/inet.h>
#include<pthread.h>
void *fun(void *)
{
	
}
int main()
{
	pthread_t id;
	pthread_create(&id,NULL,fun,NULL);
	pthread_join(id,NULL);
}

void *fun(void *)
1./头  <pthread.h>
2./pthread_creata(&id,NULL,fun,NULL);  2/属性  4./fun的参数  void *
3./gcc name -lpthread    /链接第三方库
4./void *fun(void *)   ***先强转然后进行操作 

**等待 退出
1./pthread_join(id,NULL);    2/fun的返回值
2./Pthread_exit(0);

同步互斥机制
*互斥锁
1./定义全局变量锁，pthread_mutex_t mutex;
2./pthread_mutex_init(&mutex,NULL)
  /pthread_mutex_lock(&mutex);
  /pthread_mutex_unlock(&mutex);

**信号量
  1./头文件：<semaphore.h>
  2./全局变量sem_t sem;
  sem_init(&sem,0,1);  2/线程间通信  3/小于等于线程数
  sem_wait(&sem);  p
  sem_post(&sem);  v
  等待资源，开始工作，
  结束工作，通知下家
***
  
  
  