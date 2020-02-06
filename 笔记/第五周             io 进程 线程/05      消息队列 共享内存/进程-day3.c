
进程间通信      ipc通信： 消息队列/共享内存/信号量 



一 消息队列  

1. 步骤： 
key_t key = ftok("路径",int);  //该处放一个1-255之间的数字
创建 ipc 对象   msgget  
发送消息        msgsnd 
接收消息        msgrcv 
删除ipc对象     msgctl 

2. 查看消息队列的命令： ipcs -q     
   删除消息队列的命令： ipcrm -q msqid 

3. 系统调用
(0) 创建key值的函数   ftok  
函数原型：key_t ftok(const char *pathname, int proj_id);
参数：    pathname   已经存在的，不经常修改的 一个文件（带路径的就行）
		  proj_id    一个  1~255 的整数。 
返回值：  成功： key 值 
		  失败： -1 

(1) 创建消息队列   
头文件：   	#include <sys/types.h>
			#include <sys/ipc.h>
			#include <sys/msg.h>
函数原型： int msgget(key_t key, int msgflg);
参数：     参数1 ： key 值。    ftok 的返回值。   IPC_PRIVATE 
		   参数2 ： 权限。 同 open 权限位。 创建的权限： IPC_CREAT 
返回值：   成功： 消息队列id    
		   失败： -1 
示例：  int msgid = msgget(key,IPC_CREAT|0777);

(2) 发送消息  
函数原型：  int msgsnd(int msqid, const void *msgp, size_t msgsz, int msgflg);
参数    ：  参数1： 消息队列 id  
			参数2： 发送的消息（包括正文和类型）。
					struct msg 
					{
						long type;       // 消息类型。 
						char data[256];  // 消息正文 
					};					
			参数3： 消息正文的大小  
			参数4： 是否阻塞。 
				IPC_NOWAIT  非阻塞   
				0 阻塞

(3)接收消息  
函数原型：  ssize_t msgrcv(int msqid, void *msgp, size_t msgsz, long msgtyp, int msgflg);
参数    ：  参数1： 消息队列 id  
			参数2： 存放消息的位置。 
			参数3： 消息正文的大小  
			参数4： 指定消息类型
			参数5： 是否阻塞。 
				IPC_NOWAIT  非阻塞   
				0 阻塞

(4)消息队列控制函数   
函数原型：  int msgctl(int msqid, int cmd, struct msqid_ds *buf);
参数    ：  参数1 ： 消息队列id   
			参数2 ： 控制选项     
					IPC_RMID    删除ipc 对象。 
					IPC_SET     设置属性 
					IPC_STAT    获取状态  

			参数3 ： The msqid_ds data structure is defined in <sys/msg.h> as follows:
           struct msqid_ds {             // 消息队列的属性结构 
               struct ipc_perm msg_perm;     /* Ownership and permissions */
               time_t          msg_stime;    /* Time of last msgsnd(2) */
               time_t          msg_rtime;    /* Time of last msgrcv(2) */
               time_t          msg_ctime;    /* Time of last change */
               unsigned long   __msg_cbytes; /* Current number of bytes in queue (nonstandard) */
               msgqnum_t       msg_qnum;     /* Current number of messages in queue */
               msglen_t        msg_qbytes;   /* Maximum number of bytes allowed in queue */
               pid_t           msg_lspid;    /* PID of last msgsnd(2) */
               pid_t           msg_lrpid;    /* PID of last msgrcv(2) */
           };
			
		The ipc_perm structure is defined as follows (the highlighted fields are settable using IPC_SET):
           struct ipc_perm {        // ipc 对象的通用结构 
               key_t          __key;       /* Key supplied to msgget(2) */
               uid_t          uid;         /* Effective UID of owner */
               gid_t          gid;         /* Effective GID of owner */
               uid_t          cuid;        /* Effective UID of creator */
               gid_t          cgid;        /* Effective GID of creator */
               unsigned short mode;        /* Permissions */
               unsigned short __seq;       /* Sequence number */
           };

使用示例： 
key_t key  = ftok("/",'a');
int msgid = msgget(key,IPC_CREAT|0777);
struct msg buf;
msgsnd(id, &buf, sizeof(buf)-sizeof(long),0);
msgrcv(id,&buf,sizeof(buf)-sizeof(long),234,0);
msgctl(id,IPC_RMID,NULL);

示例代码： 
/////////   send.c   
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
typedef struct 
{
	long type;
	char buf[128];
}msg_t;
int main()
{
	key_t key = ftok("/etc",'t');
	int msgid = msgget(key,IPC_CREAT|0777);     // 创建 ipc 对象 
	if(msgid < 0)
	{
		perror("msgget");
		return -1;
	}
	msg_t msg = {123,"Welcome to Shenyang"};      // 要发送的消息 
	msgsnd(msgid, &msg, sizeof(msg)-sizeof(long),0);     // 发送消息   
	return 0;
}
///////////// recv.c 
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
typedef struct 
{
	long type;
	char buf[128];
}msg_t;
int main()
{
	key_t key = ftok("/etc",'t');        // 相同的路径和数值  
	int msgid = msgget(key,0);           // 打开消息队列 
	if(msgid < 0)
	{
		perror("msgget");
		return -1;
	}
	msg_t msg = {0,0};      // 接收的消息要存放的位置  
	msgrcv(msgid, &msg, sizeof(msg)-sizeof(long),1,IPC_NOWAIT);     // 接收消息，要标明参数4，接收的类型。 
	printf("%s\n",msg.buf);
//	msgctl(msgid,IPC_RMID,NULL);
	return 0;
}
// 练习1： 进程1负责发送，进程2负责接收。    
// 练习2： 互相发送和接收。  
//////////////send.c   
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
typedef struct 
{
	long type;
	char buf[128];
}msg_t;
int main()
{
	int msgid = msgget(12345,IPC_CREAT|0777);
	if(msgid < 0)
	{
		perror("msgget");
		return -1;
	}
	msg_t msg = {123,"Welcome to Shenyang"};
	msgsnd(msgid, &msg, sizeof(msg)-sizeof(long),0);
	
	sleep(1);
	msgrcv(msgid, &msg, sizeof(msg)-sizeof(long),1,0);
	printf("%s",msg.buf);
	return 0;
}
/////////////recv.c 
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
typedef struct 
{
	long type;
	char buf[128];
}msg_t;
int main()
{
	int msgid = msgget(12345,0);
	if(msgid < 0)
	{
		perror("msgget");
		return -1;
	}
	msg_t msg = {0,0};
	msgrcv(msgid, &msg, sizeof(msg)-sizeof(long),123,IPC_NOWAIT);
	printf("%s\n",msg.buf);

	msg.type = 1;
	strcpy(msg.buf,"Byebye~");
	msgsnd(msgid, &msg, sizeof(msg)-sizeof(long),0);
//	msgctl(msgid,IPC_RMID,NULL);
	return 0;
}
执行过程： 
gcc send.c -o s 
gcc recv.c -o r 
./s 
./r 

// 练习3： 实现消息队列版本的 cat 功能。 
具体过程： 进程a : 发送文件名  ，然后从消息队列中，接收文件的内容（进程b 发送回来的内容）
		   进程b : 收到文件名后，将文件的内容，传回给进程a . 
建议： 可以设置不同的消息类型。 a ---> b 类型设为1 
.                               b ---> a 类型设为2

///////////a.c ////
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
typedef struct 
{
	long type;
	char buf[128];
}msg_t;
int main(int argc,char *argv[])
{
	if(argc < 2)
	{
		printf("%s file-name\n",argv[0]);
		return -1;
	}
	key_t key = ftok("/boot",'i');
	int msgid = msgget(key,IPC_CREAT|0777);      // 创建消息队列  
	if(msgid < 0)
	{
		perror("msgget");
		return -1;
	}
	msg_t msg;
	msg.type = 666;
	strcpy(msg.buf,argv[1]);        // 准备数据  
	msgsnd(msgid, &msg, sizeof(msg)-sizeof(long),0);      // 发送文件名  
	
	sleep(1);
	while(1)      // 循环接收消息   
	{
		bzero(msg.buf,sizeof(msg.buf));
		ssize_t x = msgrcv(msgid, &msg, sizeof(msg)-sizeof(long),123,IPC_NOWAIT);    // 接收时采用非阻塞的方式。
		if (x < 0)     // 如果接收失败，返回-1. 则结束接收即可。 
			break;
		printf("%s",msg.buf);
	}
	msgctl(msgid,IPC_RMID,NULL);    // 最后，删除消息队列。 
	return 0;
}

////////// b.c /// 
#include <stdio.h>
#include <strings.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/msg.h>
typedef struct         // 消息结构  
{
	long type;       // 类型。 
	char buf[128];   // 正文   
}msg_t;
int main()
{
	key_t key = ftok("/boot",'i');
	int msgid = msgget(key,IPC_CREAT|0777);    // 创建或打开消息队列。 
	if(msgid < 0)
	{
		perror("msgget");
		return -1;
	}
	msg_t msg = {0,0};
	msgrcv(msgid, &msg, sizeof(msg)-sizeof(long),666,0);   // 接收文件名  
	printf("file-name : %s\n",msg.buf);
	int fd = open(msg.buf,O_RDONLY);    // 打开文件。 
	if(fd < 0)
	{
		msg.type = 123;
		strcpy(msg.buf,strerror(errno));	// 如果打开文件失败。 
		msgsnd(msgid, &msg, sizeof(msg)-sizeof(long),0);    // 则将失败消息发送会请求端。 
		return -1;
	}

	while(1)
	{	
		bzero(&msg,sizeof(msg));
		msg.type = 123;
		int x = read(fd,msg.buf,sizeof(msg.buf));     // 循环从文件中读取内容。
		if(x <= 0)
			break;
		msgsnd(msgid, &msg, sizeof(msg)-sizeof(long),0);   // 将读到的内容，发送给请求端。 
	}
	close(fd);   // 发送完毕，则关闭文件。 
	return 0;
}
执行过程： 
gcc a.c -o a 
gcc b.c -o b 
./b 
./a a.c 



二  共享内存  

1. 步骤  
创建ipc对象    shmget 
*映射          shmat 
解除映射       shmdt 
删除ipc对象    shmctl 

2. 查看共享内存命令： ipcs -m 
   删除对象   ipcrm -m shmid 

3. 特点 
(1) 共享内存是进程间最为高效的进程见通信方式  
(2) 共享内存是内核空间区域。 
(3) 如果多个进程使用同一块共享内存区，则需要同步和互斥机制。 

3. 相关系统调用  
1)   shmget
头文件：    #include <sys/ipc.h>
			#include <sys/shm.h>
函数原型：  int shmget(key_t key, size_t size, int shmflg); 
参数：      参数1： key       （1）IPC_PRIVATE     （2） ftok 的返回值
			参数2： size  要设定的共享内存的大小  
			参数3： 共享内存的使用权限
返回值：成功： 共享内存 id      失败：-1
示例：  int shmid = shmget(IPC_PRIVATE,128, IPC_CREAT|O_RDWR|0777);

2)  shmat   
头文件：    #include <sys/types.h>
            #include <sys/shm.h>
函数原型：  void *shmat(int shmid, const void *shmaddr, int shmflg);
参数：   参数1： 共享内存id 
		 参数2： 映射的空间地址     NULL (一般写成NULL，由操作系统自动分配)
		 参数3： SHM_RDONLY   只读。 0 :读写 
返回值： 成功： 返回映射空间首地址。 失败： NULL 
示例：   char *p = shmat(shmid, NULL, 0);

3) shmdt  
函数原型： int shmdt(const void *shmaddr);
参数：     shmat 的返回值。 
返回值：   成功： 0     失败： -1.
示例：     shmdt(p);

4) shmctl    
功能： 设置或者获取 ipc 对象的属性。 
函数原型：  int shmctl(int shmid, int cmd, struct shmid_ds *buf);
参数：     参数1： 共享内存 id 
		   参数2/3 ：  同 msgctl  
  
示例代码：
/////// vi wr.c ////////
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
int main()
{
	key_t key = ftok("/",'x');
	int shmid = shmget(key,1024,IPC_CREAT|0777);    //创建共享内存  
	if(shmid < 0)
	{
		perror("shmget");
		return -1;
	}
	char *p = shmat(shmid,NULL,0);   //映射   
	strcpy(p,"hello world");         //写入数据  
	shmdt(p);           // 解除映射   
	return 0;
}

//////// vi re.c  ///////
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
int main()
{
	key_t key = ftok("/",'x');
	int shmid = shmget(key,1024,IPC_CREAT|0777);    // 打开  
	if(shmid < 0)
	{
		perror("shmget");
		return -1;
	}
	char *p = shmat(shmid,NULL,SHM_RDONLY);     // 映射   
	printf("%s",p);     // 读取   
	shmdt(p);      // 解除映射   
	return 0;
}

// 练习： 创建一块共享内存区，一个进程负责写入整型数据，一个进程负责读出数据。 
参见上例。 



// 作业： 复习 消息队列 / 共享内存  （各版本 cat 都如何实现） 




//作业1：创建子进程代表售票员 父进程代表司机 
售票员捕捉信号SIGINT（代表开车） 发SIGUSR1给司机 司机打印"ready-go!"
售票员捕捉SIGQUIT(代表停车) 发SIGUSR2给司机	 司机打印 "stop..."
售票员捕捉SIGTSTP（代表车到总站）发SIGUSR1给售票员 售票员打印 "get off!"




//作业2：实现有名管道版本的cat：   
服务端：
1. 收到客户端发来的请求（收到文件名）  
2. 对文件进行处理（open  read  发送回客户端）    
客户端： 
1. 发送文件名给服务器。 
2. 从服务端接收文件内容，打印到屏幕。 



// 预习： 信号量  线程  








