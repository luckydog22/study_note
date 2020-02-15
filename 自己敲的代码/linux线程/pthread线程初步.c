#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

typedef struct student
{
    int id;
    int age;
}student;

//线程
void *fun(void *p)
{
	student s = *(student *)p;

    while(1)
    {
        printf("%d\n",s.age);
        printf("%d\n",s.id);
        sleep(1);
    }
}

int main()
{
    //定义id
    pthread_t id;
    student s;
    s.age = 10;
    s.id = 26;
    //创建线程
    pthread_create(&id,NULL,fun,&s);
    //阻塞等待
    pthread_join(id,NULL);
	return 0;
}