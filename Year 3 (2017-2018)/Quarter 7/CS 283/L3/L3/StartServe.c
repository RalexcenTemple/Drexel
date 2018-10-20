#include <stdio.h>
#include <stdlib.h>
#include "csapp.h"

#define LEN 256
//Reed Ceniviva
void work(int cfd);
char* crtHead(char* fn, int fLen);

int main(int argc, char* argv[])
{
	
	int s;
	int cfd; 
	int port = atoi(argv[1]);
	int cLen;
	struct sockaddr_in addr;
	

	//check input
	if(argc < 2)
	{
		
		printf("Too few arguments \n");
		exit();
	
	}else if(argc > 2)
	{
		
		printf("too many arguments \n");
		exit();
		
	}else
	{
		//set s to a listening socket on port
		s = Open_listenfd(port);
		
		//connect, send cfd to work, close connection
		while(1)
			{
				
				cLen = sizeof(addr);
				cfd = Accept(s, (SA *) &addr, &cLEN);
				work(cfd);
				Close(cfd);
				
			}
		
	}
	
}

void work (int cfd)
{
	
	rio_t rio;
	Rio_readinitb(&rio,cfd);
	int readi;
	char buf[LEN];
	int lim = 0;
	char* headP = buf;
	int end = 1;
	int beg	= 0;
	char reqP[LEN];
	char RPptr = reqP;
	int pfd;
	struct stat fStat;
	
	//receive line from server and check for errors
	while((readi = Rio_readlineb(&rio,&buf,LEN)) == 0)
	{
		if(readi < 0)
		{
			
			printf("Error: Header \n");
			return();
			
		}
		if(lim > LEN)
		{
				
			printf("Error: Header \n");
			return();
				
		}
		
		lim = lim + 1;
		
	}
	//while the end has not been reached indicated by ' ' or '\0'
	while(end == 1)
	{
		//look for beginning 
		if(*headP == '/')
		{
			
			beg = 1;
			headP = headP + 1;
			
		}
		if(beg == 1)
		{
			//check for end of header pointer
			if(*headP == ' ' || *headP == '\0')
			{
				
				end = end + 1;
				
			}else
			{
				//copy character from header pointer to the request page pointer
				//move request page pointer
				memcpy(RPptr,headP,1);
				RPptr = RPptr + 1;
				
			}
			
		}
		
		headP = headP + 1;
		
	}
	//store pfd data in fStat
	if(fstat(pfd, &fStat) < 0)
	{
		
		return();
		
	}
	//accosiate the page file descriptor with rio
	Rio_readinitb(&rio,pfd);
	//write header response
	char* header = crtHead(&reqP,fStat.st_size);
	int headLen = strlen(header);
	//send header to cfd
	Rio_writen(cfd,header,headLen);
	
	while((readi = Rio_readnb(&rio,&buf,LEN)) > 0)
	{
		
		Rio_writen(cfd,&buf,readi);
		
	}
	
}

//create header
char* crtHead(char* fn, int fLen)
{
	
    char fType[32];
    
    if(strstr(fn,".html"))
	{
	
		strcpy(&fType,"text/html");
		
		
	}else
	{
		
		strcpy(&fType,"text/plain\0");
		
	}
    char* head = malloc(LEN);
    sprintf(head,"%s %s\r\n","HTTP/1.1","200 OK");
	sprintf(head,"Content-Type: %s; charset=%s\r\n",fType,"utf-8");
	sprintf(head,"Content-Length: %d\r\n\r\n", fLen);
    return header;
	
}







































