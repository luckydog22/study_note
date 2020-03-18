#ifndef _MSG_H_
#define _MSG_H_

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <strings.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sqlite3.h>
#include <sys/wait.h>
#include <signal.h>

#define N 64
#define SIZE 256
#define R  1        //register
#define L  2		//login
#define Q  3		//query word
#define H  4		//history record

typedef struct {
	int type;        //R/L/Q/H
	char name[N];    //usrname
	char data[SIZE]; //passwd/word/explain/message
}MSG;

typedef struct sockaddr SA;
typedef struct sockaddr_in SAI;

#endif
