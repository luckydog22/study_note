

一、基础知识
1. 什么是IO  ： linux 下读写文件的方式。 
2. 什么是流  ： 标准IO操作的操作对象。 （是描述文件信息的结构体）
3. 缓冲区种类： 全缓冲（存放在磁盘中的普通文件默认为全缓冲）、 
				行缓冲（标准输入流stdin、标准输出流stdout）、
				无缓冲（标准出错流strerr）
刷新缓存示例： 
/////////////
#include <stdio.h> 
int main()
{
	while(1)
	{
		printf("1234567890");
		fflush(stdout);      // 刷新缓存的函数。
		sleep(1);
	}
	return 0;
}

4. 标准IO的基本操作：  打开、 关闭、 读写、 定位

 
 
二、 标准IO操作 
1. 打开   fopen  
函数原型：  FILE *fopen(const char *path, const char *mode);
参数：      path : 包含路径的文件名。   "./a.c" 
			mode : 打开方式。 
				"r"  : 只读打开。 要求文件必须存在。 
				"r+" : 读写打开。 同上。
				"w"  : 只写打开。 如果文件不存在，则创建一个文件。如果文件存在，则，先清空、再写入。 
				"w+" : 读写打开。 其余同 "w". 
				"a"  : 以追加、只写的方式打开文件。如果文件不在，则创建文件，如果文件存在，则以追加的方式写入内容。
				"a+" : ...     读写 .... 其余同  "a"		
返回值： 成功： 返回流指针。 失败： NULL
使用示例：  FILE *fp = fopen("./a.c","r");

2. 关闭   fclose
函数原型 ：  int fclose(FILE *fp);
参数     ：  fp： 打开的流指针。
返回值   ：  成功：0    失败：-1. 

示例： 
///////////////
#include <stdio.h>
int main()
{
	FILE *fp = fopen("./arr.c","r");
	if(fp == NULL)
	{
		printf("error : fopen ...\n");
		return -1;
	}
	printf("open : success\n");
	fclose(fp);
	return 0;
}

3. 打印出错信息     perror   strerror 
3.1 perror   
函数原型：   void perror(const char *s); 
参数    ：   s : 一般存放一个功能函数名  
返回值  ：   无
功能    ：   打印出错原因
示例： 
/////////////////////
#include <stdio.h>
int main(int argc,char *argv[])
{
	if(argc < 2)
	{
		printf("%s argv[1]\n",argv[0]);
		return -1;
	}
	FILE *fp = fopen(argv[1],"r");
	if(fp == NULL)
	{
		perror("fopen");    // No such file or directory ...  等信息  
		return -1;
	}
	printf("open : success\n");
	fclose(fp);
	return 0;
}

3.2    strerror 
头文件  ：   #include <string.h>
			 #include <errno.h>
函数原型：   char *strerror(int errnum);
参数    ：   错误码。 直接写 errno 即可。 
返回值  ：   错误信息字符串。 
功能    ：   打印出错信息  

使用示例： 	 printf("%s\n",strerror(errno));


4. 读写  
4.1  按字节读写     读： fgetc     写：fputc 

函数原型 ： int fgetc(FILE *stream); 
参数     ： FILE *fp 
返回值   ： 读到的字节。（实际上是 unsigned char 类型） 

函数原型 ： int fputc(int c, FILE *stream);
参数     ： 将 c 写入到 stream 中。 
返回值   ： 成功：写入的 c    失败： EOF( end of file 文件结束标志)

使用示例： 
/////////////////
#include <stdio.h>
int main(int argc,char *argv[])
{
	if(argc < 2)     // 确定传参
	{
		printf("%s argv[1]\n",argv[0]);
		return -1;
	}
	FILE *fp = fopen(argv[1],"r");   // 确定 open 
	if( NULL == fp)
	{
		perror("fopen");
		return -1;
	}
	printf("%c \n",fgetc(fp));    // 读取内容 
	int x = fgetc(fp);
	printf("x = %c\n",x);

	fclose(fp);   // 关闭文件。 步骤就是：打开、读取、关闭   
}

// 练习： 将文件内容输出到终端。  
//////////////
#include <stdio.h>
int main(int argc,char *argv[])
{
	if(argc < 2)
	{
		printf("%s argv[1]\n",argv[0]);
		return -1;
	}

	FILE *fp = fopen(argv[1],"r");  // 打开  
	if(fp == NULL)
	{
		perror("fopen");
		return -1;
	}

	int x; 
	while( (x=fgetc(fp))!=EOF )    // 循环读取  
		printf("%c",x);

	fclose(fp);      // 关闭  
	return 0;
}

// 练习： 实现 cp 功能。 
//////////////////////
#include <stdio.h>
int main(int argc,char *argv[])
{
	if(argc < 3)
	{
		printf("%s src dest \n",argv[0]);
		return -1;
	}
	FILE *fp_src = fopen(argv[1],"r");
	FILE *fp_dest = fopen(argv[2],"w");
	if(fp_src == NULL || fp_dest == NULL)
	{
		perror("fopen");
		return -1;
	}
	
	int x;
	while( (x = fgetc(fp_src))!=EOF )
		fputc(x,fp_dest);

	fclose(fp_src);
	fclose(fp_dest);
	return 0;
}


4.2 按行读写    fgets  fputs

函数原型 ：  char *fgets(char *s, int size, FILE *stream);
参数     ：  参数3 ： stream  . 从流中读取。 
			 参数2 ： 预计读取 size 这么多个字节 
			 参数1 ： 读到的内容，写入到 s 中。 
返回值： 成功： 目标位置的首地址 s     失败： NULL 

函数原型 :  int fputs(const char *s, FILE *stream);
参数     ： 参数1 ： 从 s 中拿取要写入的内容。 
			参数2 ： 写入到 stream 中。  
返回值  :   fputs() return a nonnegative number on success, or EOF on error.

读示例： 
///////////////
#include <stdio.h>
int main(int argc,char *argv[])
{
	if(argc < 2)
	{
		printf("%s argv[1]\n",argv[0]);
		return -1;
	}
	FILE *fp = fopen(argv[1],"r");
	if( NULL == fp)
	{
		perror("fopen");
		return -1;
	}
	
	char s[100] = {0};
	fgets(s,sizeof(s),fp);
	printf("%s",s);

	fclose(fp);
}

写示例： 
////////////////////////////
#include <stdio.h>
int main(int argc,char *argv[])
{
	if(argc < 2)
	{
		printf("%s argv[1]\n",argv[0]);
		return -1;
	}
	FILE *fp = fopen(argv[1],"w");
	if( NULL == fp)
	{
		perror("fopen");
		return -1;
	}
	
	char s[100] = "hello world";
	fputs(s,fp);

	fclose(fp);
}


// 练习： 使用 fgets  fputs 实现 cp 功能。 
///////////////////
#include <stdio.h>
int main(int argc,char *argv[])
{
	if(argc < 3)
	{
		printf("%s src dest \n",argv[0]);
		return -1;
	}
	FILE *fp_src = fopen(argv[1],"r");
	FILE *fp_dest = fopen(argv[2],"w");
	if(fp_src == NULL || fp_dest == NULL)
	{
		perror("fopen");
		return -1;
	}

	char *s;
	char buf[100];
	while( (s=fgets(buf,sizeof(buf),fp_src))!= NULL )
		fputs(buf,fp_dest);

	fclose(fp_src);
	fclose(fp_dest);
	return 0;
}


4.3 按类型读写    fread    fwrite 

函数原型 ： size_t fread(void  *ptr, size_t size, size_t nmemb, FILE *stream);
参数     ： 参数4：从 stream 流中读取数据。 
			参数3：读取的 item 的个数  
			参数2：每个 item 的字节数                         
			参数1：将读到的内容放在当前指针指向的地址中。 
返回值：  fread() return the number of items successfully read (i.e., not the number of characters).  
		fread 返回的是读到的数据的个数，而不是字节数！！！！
		
函数原型 ： size_t fwrite(const void *ptr, size_t siz e, size_t nmemb, FILE *stream);
参数     ： 从 ptr 指向的位置拿取数据，该数据每个item是 size 字节，共 nmemb 个，写入到 stream 流中。   
返回值   ： 实际写入的数据的个数，不是字节数！！！！！

示例： 
/////// write.c /////
#include <stdio.h>
int main()
{
	FILE *fp = fopen("a.c","w");
	if(fp == NULL)
	{
		perror("fopen");
		return -1;
	}	
	int a[] = {1,2,3,4,5,6,7,8,9,10};
	int x = fwrite(a,4,10,fp);
	printf("%d is written\n",x);
	fclose(fp);
	return 0;
}

/////// read.c /////
#include <stdio.h>
int main()
{
	FILE *fp = fopen("a.c","r");
	if(fp == NULL)
	{
		perror("fopen");
		return -1;
	}
	int s[10] = {0};
	fread(s,4,10,fp);    // 从 fp 中读取 4*10 个字节的数据，到s 中。 
	fclose(fp);

	int i;
	for(i=0; i<10; i++)
		printf("%d ",s[i]);
	printf("\n");
	return 0;
}
///////
执行过程： 
gcc write.c -o write  
gcc read.c -o read 
./write 
./read 

/////////////////////
自己写的
#include<stdio.h>
int main(int argc,const char *argv[])
{
	int i;
	if(argc<2)
	{
		printf("frile name ");
		return -1;
	}

	FILE *fp1=fopen(argv[1],"r");
	if(fp1==NULL)
	{
		perror("fopen");
		return -1;
	}
	char a[20];
	
	fread(a,1,sizeof(a)-1,fp1);
	
	puts(a);
	return 0;
}

// 练习： 使用该组函数，实现 cp 功能。 
////////////////
#include <stdio.h>
int main(int argc,char *argv[])
{
	if(argc < 3)
	{
		printf("%s src dest \n",argv[0]);
		return -1;
	}
	FILE *fp_src = fopen(argv[1],"r");
	FILE *fp_dest = fopen(argv[2],"w");
	if(fp_src == NULL || fp_dest == NULL)
	{
		perror("fopen");
		return -1;
	}
	size_t x;
	char buf[100];
	do	{
		x = fread(buf,1,sizeof(buf),fp_src); // 循环读写。 
		fwrite(buf,1,x,fp_dest);  // 注意参数3： 实际写入的个数，取决于读多少。读到 x 个，就写入 x 个。 
	}while( x == sizeof(buf) );  // do-while : 条件为真，则执行循环，条件为假，则结束循环。 

	fclose(fp_src);
	fclose(fp_dest);
	return 0;
}
5. 定位   fseek   ftell 

函数原型：  int fseek(FILE *stream, long offset, int whence);
功能    ：  以某个指定的位置进行偏移。（偏移的是读写文件的位置）
参数    ：  参数1  stream：  流文件。 
			参数2  offset：  偏移量。 
			参数3  whence：  基准位置。
					SEEK_SET   以文件开头为基准。 
					SEEK_CUR   以当前位置为基准。 
					SEEK_END   以文件末尾为基准。 
返回值：成功： 0   失败： -1 
示例：  fseek(fp,-2,SEEK_END);    // 以文件末尾作为基准，向前偏移两个字符的位置。 

函数原型： long ftell(FILE *stream);
参数    ： 文件流 fp 。   
返回值  ： 当前位置距文件开头偏移了多少个字节。 

示例： 
///////////
#include <stdio.h>
int main()
{
	FILE *fp = fopen("a.c","w+");
	if(fp == NULL)
	{
		perror("fopen");
		return -1;
	}
	fwrite("Welcome to Shenyang",1,19,fp);
	long x = ftell(fp);      // 当前读写位置，距文件开头，偏移了多少个字节。 
	printf("x = %ld\n",x);
	fseek(fp,1,SEEK_SET);     // 定位在文件开头。向后偏移 1 个位置。 

	char s[100] = {0};
	fread(s,1,19,fp);   // 一定要将读写位置重新定位在文件开头，才能读到刚才写入的内容。 
	puts(s);

	return 0;
}

6. 关于清零函数     bzero   memset 

6.1   bzero 
头文件  ： #include <strings.h>
函数原型： void bzero(void *s, size_t n);
功能    ： 以 s 为起始位置的连续 n 个字节空间，进行清零操作。 

6.2  memset  
头文件  ： #include <string.h>;
功能    ： 以 s 为起始位置，连续  n 个字节！填充c

示例1： 
//////////////////
#include <stdio.h>
#include <string.h>
int main()
{
	char s[10];
	memset(s,'a',10);    // 以字节为单位填充 'a'
	int i;
	for(i=0; i<10; i++)
		printf("%c",s[i]);
	printf("\n");
	return 0;
}

示例2： 
//////////////////
#include <stdio.h>
#include <string.h>
int main()
{
	int s[10];
	memset(s,0,sizeof(s));    //填充整数时，只能填充0 或者 -1.  以字节！为单位填充。
	int i;
	for(i=0; i<10; i++)
		printf("%d - ",s[i]);
	printf("\n");
	return 0;
}



// 作业： 统计文件行数。 
#include<stdio.h>
int main(int argc,const char *argv[])
{
	int i;
	if(argc<2)
	{
		printf("frile name ");
		return -1;
	}

	FILE *fp1=fopen(argv[1],"r");
	if(fp1==NULL)
	{
		perror("fopen");
	}

	char a[100];
	char *s;
	int count=0;
	
	while((s=fgets(a,sizeof(a),fp1))!=NULL)
	count++;
	printf("%d\n",count);
	fclose(fp1);

	return 0;
}

// 作业： 尝试用多种方式（使用标准IO函数），求出文件的大小。 
#include<stdio.h>
int main(int argc,const char *argv[])
{
	int i;
	if(argc<2)
	{
		printf("frile name ");
		return -1;
	}
	FILE *fp1=fopen(argv[1],"r");

	if(fp1==NULL)
	{
		perror("fopen");
	}
	int x;
	int count=0;
	while(1)
	{
		if((x=fgetc(fp1))==EOF)
		{
			break;
		}
		count++;
	}
	fclose(fp1);
	printf("%d\n",count);
	return 0;
}
#include<stdio.h>
int main(int argc,const char *argv[])
{
	int i;
	if(argc<2)
	{
		printf("frile name ");
		return -1;
	}

	FILE *fp1=fopen(argv[1],"r");
	if(fp1==NULL)
	{
		perror("fopen");
	}

	char a[100];
	char *s;
	int count=0;
	
	while((s=fgets(a,sizeof(a),fp1))!=NULL)
	count++;
	printf("%ld\n",ftell(fp1));
	fclose(fp1);

	return 0;
}
#include<stdio.h>
int main(int argc,const char *argv[])
{
	int i;
	if(argc<2)
	{
		printf("frile name ");
		return -1;
	}

	FILE *fp1=fopen(argv[1],"r");
	if(fp1==NULL)
	{
		perror("fopen");
		return -1;
	}

	int a[100];
	int x;

	do
	{
		x=fread(a,4,sizeof(a),fp1);
	}while(x==sizeof(a));
	
	printf("%ld\n",ftell(fp1));
	fclose(fp1);
	
	
	return 0;
}