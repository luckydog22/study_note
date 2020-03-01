
c基础 - linux - 数据结构 - IO - 进程线程 - 网络编程 - c++ - qt - opencv 

进程课程安排： 4天   
1.   进程基础、 守护进程 
2 3. 进程间通信  
4.   线程


一、 进程基础   

什么是进程： 进程是程序的一次动态执行过程，包括了进程的创建、执行、消亡。 

进程和程序的区别： 
程序： 是一个静态的概念。 数据段、正文段。 
进程： 程序的执行过程。   数据段、正文段、堆栈段。 
进程不仅包括程序的指令和数据，而且包括程序计数器值、CPU的所有寄存器值以及存储临时数据的进程堆栈。

进程的状态：  执行态、等待态、暂停态、消亡态、僵死态。 
进程的分类： 交互式进程、 批处理进程、守护进程。 

进程是程序执行和资源分配的最小单位。 

进程的内存结构： linux 采用虚拟内存管理技术，使得每个进程都有独立的地址空间。 



二、 进程系统调用  

1. fork();
功能    ： 创建子进程 
头文件  ： #include <unistd.h>
函数原型： pid_t fork(void);
返回值  ： 失败： -1 （父进程得到返回值 -1. 子进程创建失败）
		   成功： 0   : 子进程得到的返回值。 
				  >0  ：父进程得到的返回值（子进程的进程号）       
-------------------------------------
	父                    子 
x = fork();            x = fork();
x > 0                  x = 0

示例： 
/////////////
#include <stdio.h>
#include <unistd.h>
int main()
{
	pid_t id = fork();
	if(id < 0)
	{
		perror("fork");
		return -1;
	}
	if(id == 0)   // child
	{
		printf("I'm child   %d\n",id);
	}
	else 
	{
		sleep(1);
		printf("I'm parent %d\n",id);
	}
	return 0;
}

// 练习： 请尝试使用父子进程，分别循环输出自己是哪个进程。 
#include <stdio.h>
#include <unistd.h>
int main()
{
	pid_t id = fork();
	if(id < 0)
	{
		perror("fork");
		return -1;
	}
	if (id > 0)    // parent
	{
		while(1)
		{
			printf("I'm parent\n");
			sleep(1);
		}
	}
	else 
	{
		while(1)
		{
			printf("I'm child\n");
			sleep(2);
		}
	}
}

2. getpid();  getppid();
函数原型：  pid_t getpid(void);
			pid_t getppid(void);
返回值  ：getpid 获取自己的pid  getppid 获取自己的父进程id  
示例  ： 
////////////
#include <stdio.h>
#include <unistd.h>
int main()
{
	printf("pid : %d\n",getpid());
	printf("ppid: %d\n",getppid());
	return 0;
}

// 使用 fork 创建新进程。 这两个进程，分别输出自己的 pid 和 ppid.
#include <stdio.h>
#include <unistd.h>
int main()
{
	pid_t id = fork();
	if(id < 0)
	{
		perror("fork");
		return -1;
	}
	if(id == 0)   // child
	{
		printf("I'm child:%d pid:%d   ppid:%d \n",id,getpid(),getppid());
	}
	else 
	{
		sleep(1);
		printf("I'm parent:%d pid:%d   ppid:%d \n",id,getpid(),getppid());
	}
	return 0;
}

3. exit();     _exit();
功能： 退出进程。  
头文件  ：  #include <stdlib.h>
函数原型：  void exit(int status);

头文件  ：  #include <unistd.h>
函数原型：  void _exit(int status);

两函数间的区别：         （将缓存区的内容输出）
exit  :  调用退出处理函数 --> 清理IO缓冲 -->  调用exit系统调用 --> 进程终止运行。 
_exit :         --------       --------- -->  调用exit系统调用 --> 进程终止运行。 


4. 收尸函数  wait();   waitpid();
4.1  wait 
头文件：   #include <sys/types.h>    #include <sys/wait.h>
函数原型： int wait(int *status);
参数：     获取子进程的结束状态。 
返回值：   成功： 子进程id .  失败： -1 
示例：     wait(&status);
带参宏：    作用是判定子进程的结束状态。 
WIFEXITED(status)   ： 判定子进程是否正常结束。如果是，返回真。 
WIFSIGNALED(status) ： 判定子进程是否是被信号终止。 如果是，返回真。
WTERMSIG(status))   ： 返回 杀死子进程的信号的 编号。 

4.2  pid_t waitpid(pid_t pid, int *status, int options);
函数原型： pid_t waitpid(pid_t pid, int *status, int options);
参数：   参数1： pid   
				 > 0   . 给进程号为 pid 的进程收尸。 
				 = 0   . 给同组的子进程收尸。 
				 -1    . 给任意子进程收尸。 
				 < -1  . 给同组的 子进程为 pid绝对值 的进程收尸。   
         参数2： 保存被收尸函数的结束状态。（同上） 
		 参数3： 0     ：阻塞等待
				WNOHANG: 非阻塞等待		 		 

示例1： waitpid(pid,NULL,WNOHANG);
示例2： demo.c 
//////////////////
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main()
{
	pid_t id = fork();
	if(id < 0)
	{
		perror("fork");
		return -1;
	}
	if(id == 0)   // child
	{
		int number = 22/0;
		printf("I'm child:%d pid:%d   ppid:%d \n",id,getpid(),getppid());
	}
	else          // parent
	{
		int a;
		waitpid(id,&a,0);
		printf("%d  %d  %d \n",WIFEXITED(a),WIFSIGNALED(a),WTERMSIG(a));
	}
	return 0;
}
//////////////执行结果： 0 1 8   含义： 0 非正常结束    1 是信号终止的子进程    8 由信号8终止的该子进程  


5. exec 函数族 
功能： exec 函数族提供了一个在进程中执行另一个程序的方法。 
说明： 他可以根据指定的文件名或目录名找到对应文件，并用它来取代当前进程的数据段、代码段、堆栈段。
		在执行完之后，除了进程号没变以外，其他内容都被替换掉了。 
使用： 在linux 中使用 exec 函数族只要有以下两种情况： 
(1) 是自己重生。 
(2) 通过调用 fork 创建新进程。让新进程执行其他程序（应用普遍）

成员：    execl  execlp  execle    execv  execvp  execve 
函数原型： #include <unistd.h>
       int execl(const char *path, const char *arg, ...);
       int execlp(const char *file, const char *arg, ...);
       int execle(const char *path, const char *arg, ..., char * const envp[]);
       int execv(const char *path, char *const argv[]);
       int execvp(const char *file, char *const argv[]);
       int execvpe(const char *file, char *const argv[], char *const envp[]);

l ： 以 列表形式写出参数。 
v :  以 字符指针数组的形式保存参数的值。 
p :  可以不写文件的路径，而直接写文件名。（环境变量会去指定的路径下找到该文件）
e :  环境变量相关信息要写入参数中。 

(1) execl     execl("/bin/ls","ls","-a",NULL); 
(2) execlp    execlp("ls","ls","-a",NULL);
(3) execv     char *cmd[] = {"ls","-a",NULL};    execv("/bin/ls",cmd); 

示例： 
//////////////////
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main()
{
	pid_t id = fork();
	if(id < 0)
	{
		perror("fork");
		return -1;
	}
	if(id == 0)   // child
	{
		char *cmd[] = {"ls",NULL};
		execvp("ls",cmd);
		printf("I'm child \n");
	}
	else          // parent
	{
		while(1)
		{
			printf("I'm parent:%d pid:%d   ppid:%d \n",id,getpid(),getppid());
			sleep(1);
		}
	}
	return 0;
}

// 练习： 请编写程序，实现功能： 创建一个文件，创建文件之后，输出 “finished”.
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main()
{
	pid_t id = fork();
	if(id < 0)
	{
		perror("fork");
		return -1;
	}
	if(id == 0)   // child
	{
		execl("/bin/touch","touch","file.txt",NULL);
	}
	else          // parent
	{
		wait(NULL);
		printf("finished\n");
		exit(0);
	}
	return 0;
}



三、 守护进程    

1.步骤： 
（1） 创建子进程、父进程退出。 
（2） 创建新会话。 
（3） 修改文件工作路径。     
（4） 重设文件权限掩码。  
（5） 关闭文件描述符。      

2.示例： 
////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void my_daemon()
{
	pid_t pid = fork();
	if(pid > 0)
		exit(0);
	setsid();
	chdir("/tmp");
	umask(0);
	close(0);
	close(1);
	close(2);
}

int main()
{
	my_daemon();
	time_t t;
	while(1)
	{
		FILE *fp = fopen("/tmp/time.log","a+");

		time(&t);
		fprintf(fp,"Log : %s\n",ctime(&t));

		fclose(fp);
		sleep(2);
	}
}




