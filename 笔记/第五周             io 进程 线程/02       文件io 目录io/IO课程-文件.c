
复习：  
FILE *fp = fopen("a.c","a+");
fclose(fp);
int c = fgetc(fp);
int x = fputc(c,fp);
char *p = fgets(s,sizeof(s),fp);
fputs(s,fp);
int x = fread(s,4,25,fp);    // 返回的是元素的个数，不是字节数！！！！
fwrite(s,1,x,fp);
fseek(fp,0,SEEK_CUR);
long x = ftell(fp);    // 当前的读写位置，距文件开头，相距多远（以字节为单位）
perror("fopen");
printf("%s",strerror(errno));
bzero(buf,sizeof(buf));
memset(buf,0,sizeof(buf));



一、标准IO 与 文件IO 的对比：
.		    	   标准IO                      文件IO  

缓冲区：     全缓冲、行缓冲、无缓冲           没有缓冲区
操作对象：        流(FILE *)              文件描述符 ( int )
标准输入：         stdin                          0
标准输出：         stdout                         1 
标准错误输出：     stderr                         2 
遵从的标准：	 ANSIC 标准 				  POSIX 标准   
操作函数：                                      
打开：           fopen                          open   
关闭：           fclose                         close 
读：         fgetc/fgets/fread                  read 
写：         fputc/fputs/fwrite                 write 
定位：         fseek/ftell                      lseek  



二、 基本操作 
1.  打开     open 
头文件  ： #include <sys/types.h>
		   #include <sys/stat.h>
		   #include <fcntl.h>
函数原型： int open(const char *pathname, int flags);
		   int open(const char *pathname, int flags, mode_t mode);
参数：     参数1： 文件名（要打开的文件）
		   参数2： 打开方式 
				O_RDONLY   以只读的方式，打开已经存在的文件。  
				O_RDWR     读写方式打开文件  
				O_WRONLY   以只写的方式，打开文件。 
				O_CREAT    创建文件 
				O_EXCL     一般，打开文件的权限使用 O_CREAT 时，O_EXCL 会配合使用。用来检测文件是否存在。如果文件存在，则报错。
				O_TRUNC    清空文件（将文件大小置为0）
				O_APPEND   以追加方式打开
				
		   参数3：文件本身具有的权限属性。 参数3只有在创建文件时，才使用。
示例： int fd = open("a.c",O_CREAT|O_WRONLY, 0664);

*标准IO 与 文件IO 的打开权限的等价表达： 
"r"    O_RDONLY 
"r+"   O_RDWR
"w"    O_WRONLY|O_CREAT|O_TRUNC
"w+"   O_RDWR|O_CREAT|O_TRUNC
"a"    O_APPEND|O_CREAT|O_WRONLY
"a+"   O_APPEND|O_CREAT|O_RDWR


2. 关闭   close 
头文件：   #include <unistd.h>
函数原型： int close(int fd);
示例： 
/////////////
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc,char *argv[])
{
	if(argc < 2)       // 文件名由传参决定。 
	{
		printf("%s filename\n",argv[0]);
		return -1;
	}
	int fd = open(argv[1],O_RDWR|O_CREAT|O_APPEND,0664);   // 追加的方式，打开读写文件。如果文件不在，则创建文件。被创建的文件，属性为 0664.
	if(fd < 0) {
		perror("open");
		return -1;
	}
	printf("open success\n");
	close(fd);        // 关闭。
}


3. 读写   read     write   

函数原型： ssize_t read(int fd, void *buf, size_t count);
参数    ： 参数1 ： fd  文件描述符。(从 fd 中读取数据)  
		   参数2 ： 将读到的内容，放在 buf 中。 
		   参数3 ： 预计读取的字节数。
返回值  ： 成功： 实际读到的字节数！！！     失败： -1

函数原型： ssize_t write(int fd,const void *buf, size_t count);
参数    ： 参数1： fd 描述符。 （向 fd 中写入数据）
		   参数2： 将 buf 中的数据，写入到 fd 中。 
		   参数3： 预计写入的字节数。 
返回值  ： 成功： 实际写入的字节数！！！     失败：-1 

示例代码： 
////// write.c //////
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <strings.h>
#include <string.h>
int main()
{
	int fd = open("./a.c",O_WRONLY|O_CREAT|O_EXCL,0664);     // 打开
	if(fd < 0)	{
		perror("open");
		return -1;
	}
	char buf[] = "Welcome to Shenyang";
	int x = write(fd,buf,strlen(buf));     // 写入 
	printf("x = %d\n",x);
	close(fd);             // 关闭  
	return 0;
}

///////// read.c ////////
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <strings.h>
int main()
{
	int fd = open("./a.c",O_RDONLY);   // 打开 
	if(fd < 0)	{
		perror("open");
		return -1;
	}
	char buf[100];
	bzero(buf,sizeof(buf));
	int x = read(fd,buf,sizeof(buf));   // 读取   
	printf("x = %d\n",x);
	printf("recv: %s\n",buf);   // 读到的内容 
	close(fd);       // 关闭   
	return 0;
}
////////
执行过程： 
gcc read.c -o read  
gcc write.c -o write  
./write 
./read 

// 练习： 实现 cat 功能。 
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <strings.h>
int main(int argc,char *argv[])
{
	if(argc < 2){
		printf("%s filename\n",argv[0]);
		return -1;
	}
	int fd = open(argv[1],O_RDONLY);
	if(fd < 0){
		perror("open");
		return -1;
	}
	int x;
	char buf[100] = {0};
	while(1){
		x = read(fd,buf,sizeof(buf));
		printf("%s",buf);
		if(x < sizeof(buf))
			break;
		bzero(buf,sizeof(buf));
	}
	close(fd);
	return 0;
}

// 练习： 实现拷贝功能。 
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <strings.h>
int main(int argc,char *argv[])
{
	if(argc < 3)
	{
		printf("%s src  dest\n",argv[0]);
		return -1;
	}
	int fd_src = open(argv[1],O_RDONLY);        // 读文件  
	int fd_dest = open(argv[2],O_WRONLY|O_CREAT|O_TRUNC, 0666);    // 写文件    
	if(fd_src < 0 || fd_dest < 0)
	{
		perror("open");
		return -1;
	}
	int x;
	char buf[100];
	do{
		x = read(fd_src,buf,sizeof(buf));     // 循环读写  
		write(fd_dest,buf,x);
	}while(x == sizeof(buf));

	close(fd_src);    // 关闭  
	close(fd_dest);
	return 0;
}


4. 定位     lseek   
函数原型：  off_t lseek(int fd, off_t offset, int whence);
参数    ：  参数1 ： fd 文件描述符   
			参数2 ： 偏移量 
			参数3 ： 基准位置。  SEEK_SET    SEEK_CUR    SEEK_END 
返回值  :   成功: 返回的是，当前定位好的读写位置距文件开头的偏移量。 

// 练习： 请向文件中写入数据，然后读出。 
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <strings.h>
#include <string.h>
int main()
{
	int fd = open("./a.c",O_RDWR|O_CREAT|O_EXCL,0664);

	char buf[] = "Welcome to Shenyang";
	char s[20] = {0};

	int x = write(fd,buf,strlen(buf));	
	lseek(fd, -4, SEEK_CUR);

	read(fd,s,sizeof(s));
	printf("s : %s\n",s);

	close(fd);
	return 0;
}

总结：  
文件IO 系统调用： 
int fd = open("a.c",O_WRONLY|O_CREAT,0664); 
int x = close(fd); 
ssize_t x = read(fd,buf,sizeof(buf)); 
write(fd,buf,x);
off_t t = lseek(fd,-2,SEEK_SET);



三、目录IO 

1. 打开   opendir 
头文件：  #include <dirent.h>
		  #include <sys/types.h>
函数原型：DIR *opendir(const char *name);
参数    ：目录文件名 
返回值  ：成功： 流指针     失败： NULL 

2. 关闭   closedir 
函数原型：int closedir(DIR *dirp);
参数    ：打开的流指针。
返回值  ：成功： 0     失败： -1 

示例： 
//////////////
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
int main()
{
	DIR *dirp = opendir(".");
	if( dirp == NULL){
		perror("opendir");
		return -1;
	}
	printf("ok\n");
	closedir(dirp);
	return 0;
}

3. 读取   readdir 
函数原型：struct dirent *readdir(DIR *dirp);
参数    ：文件流指针。 
返回值  ：成功： 结构体指针。(指向的位置保存了当前读到的文件信息)    失败： NULL 
		  结构如下： 
		On Linux, the dirent structure is defined as follows:
           struct dirent {
               ino_t          d_ino;       /* inode number */
               off_t          d_off;       /* offset to the next dirent */
               unsigned short d_reclen;    /* length of this record */
               unsigned char  d_type;      /* type of file; not supported by all file system types */
               char           d_name[256]; /* filename */
           };

//练习： 尝试使用 readdir(), 读取当前目录下的所有文件名和 inode 节点号。 
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
int main()
{
	DIR *dirp = opendir(".");
	if( dirp == NULL){
		perror("opendir");
		return -1;
	}
	
	struct dirent *p ;	
	while ((p = readdir(dirp)) != NULL)
	{
		if( p->d_name[0] != '.')
			printf("inode: %9ld  d_name : %-9s d_type: %o \n",p->d_ino,p->d_name,p->d_type);
	}

	closedir(dirp);
	return 0;
}

4. 获取状态    stat 
头文件  #include <sys/types.h>
            #include <sys/stat.h>
            #include <unistd.h>
函数原型： int stat(const char *path, struct stat *buf);
参数    ： 参数1 ： 文件名
		   参数2 ： 获取得到的状态。 
	struct stat {
               dev_t     st_dev;     /* ID of device containing file */
               ino_t     st_ino;     /* inode number */
               mode_t    st_mode;    /* protection */
               nlink_t   st_nlink;   /* number of hard links */
               uid_t     st_uid;     /* user ID of owner */
               gid_t     st_gid;     /* group ID of owner */ 
               dev_t     st_rdev;    /* device ID (if special file) */
               off_t     st_size;    /* total size, in bytes */
               blksize_t st_blksize; /* blocksize for file system I/O */
               blkcnt_t  st_blocks;  /* number of 512B blocks allocated */
               time_t    st_atime;   /* time of last access */
               time_t    st_mtime;   /* time of last modification */
               time_t    st_ctime;   /* time of last status change */
           };
返回值  ： 成功： 0     失败： -1 

示例： 
///////////
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
	struct stat a;
	
	stat("write.c",&a);
	
	printf("%#o \n",a.st_mode);
	printf("x = %d\n",S_ISREG(a.st_mode));
	return 0;

}

// 作业： 用stat 检测一下 从目录中读到的每个文件，哪个是目录，哪个是普通文件




