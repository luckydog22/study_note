#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include<semaphore.h>

int a[20];
//pthread_mutex_t mute;
sem_t sem;

void *fun1(void *p);
void *fun2(void *p);
int main()
{
    sem_init(&sem,0,1);
	pthread_t id1,id2;
	pthread_create(&id2,NULL,fun2,NULL);
	pthread_create(&id1,NULL,fun1,NULL);
	pthread_join(id1,NULL);
	pthread_join(id2,NULL);
	return 0;
}
void *fun2(void *p)
{
  //  pthread_mutex_lock(&mute);
    sem_wait(&sem);
	int i; 
	for(i=0; i<20; i++)
	{
		a[i] = 77;
		//usleep(200000);
	}
	for(i=0; i<20; i++)
		printf("%d - ",a[i]);
	printf("\n");
    //pthread_mutex_unlock(&mute);
    sem_post(&sem);
}
void *fun1(void *p)
{
    //pthread_mutex_lock(&mute);
    sem_wait(&sem);
	int i;
	for(i=0; i<20; i++)
	{
		a[i] = 10*i;
	//	usleep(100000);
	}
	for(i=0; i<20; i++)
		printf("%d . ",a[i]);
	printf("\n");
    //pthread_mutex_unlock(&mute);
    sem_post(&sem);
}