#include <stdlib.h>
#include <sys/socket.h>
#include "csapp.h"
#define LEN 256
//Reed Ceniviva
int main(int argc, char* argv[])
{
	
	if(argc < 4)
	{
		
		printf("not enough argument passed \n");
		exit();
		
	}else if(argc > 4)
	{
		
		printf("too many arguments \n");
		exit();
		
	}else
	{
		
		char* host = argv[1];
		char* port = argv[2];
		char* file = argv[3];
		char head[LEN];
		char buff[LEN];
		rio_t rio;
		int cfd;
		int fd;
		int outs;
		
		sprintf(header,"GET /%s HTTP/1.1 \r \n \n Host: %s:%d \r \n %s \n \0",file,host,atoi(port),head);
		
		cfd = Open_clientfd(host,atoi(port));
		Rio_readinitb(&rio,cfd);
		
		Rio_writen(cfd,head,strlen((const char*)head));
		
		while((outs = Rio_readlineb(&rio,&buff,HEADERLEN))>0)
		{
			
			Rio_writen(STDOUT_FILENO,&buff,outs
			
		}
		close(cfd);
		return(0);
		
	}
}