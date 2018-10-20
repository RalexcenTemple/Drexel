#include <stdio.h>
#include <stdlib.h>
#include "csapp.h" 
#include <ftw.h>

char* da, *db;

int checkA(const char *fp, const struct stat *stB,int flg);
int checkB(const char *fp, const struct stat *stB,int flg);

//Reed Ceniviva
//CS283 Lab2
//2/22/2018

int main(int argc, char* argv[])
{
	
	//make sure the correct number of arguments were passed
	if(argc !=3)
	{
		
		return -1;
		
		
	}
	
	//get directories from arguments
	da=argv[1];
	db=argv[2];
	
	//walking the items in the directory "a" to the checkA function
	int cf=ftw(da,&checkA,1);
	
	if(cf !=0)
	{
		
		printf("Error with first directory\n");
		exit(-1);
	
		
	}
	
	//walking the intems in directory "b" to the checkB function
	cf=ftw(db,&checkB,1);
	
	if(cf !=0)
	{
			
		printf("Error with second directory\n");
		exit(-1);
	
		
	}
	
	
	return 0;
}

int checkB(const char *fp, const struct stat *stB,int flg)
{
	
	if(memcmp(fp,"./b\0",4)==0)
	{
		
		 return 0;
		 
		 
	}
	
	//create path of expected file using malloc and iteration from position
	char *ap=malloc(512);
	char *i=ap;
	strcpy(ap,fp);
	
	while(*i !='b')
	{
		
		i++;
		
		
	}
	//replace the second with the first
	*i='a';
	
	//existence test
	if(access(ap,F_OK)==-1)
	{
		//if not in a remove from b
		remove(fp);
		printf("file in second database not found in first, file removed from second directory\n");
	
		
	}
	
}

int checkA(const char *fp, const struct stat *stB,int flg)
{
	
    if(memcmp(fp,"./a\0",4)==0)
	{
		
		return 0;
		

	}
	
	//creat file path for a file from the second directory
	char *bp=malloc(512);
	strcpy(bp,fp);
	char *i=bp;
	
	while(*i !='a')
	{
		
		i++;
		
		
	}
	//replacing the first with the second
	*i='b';
	
	//if the file exists in the second directory
	if(access(bp,F_OK) !=-1)
	{
		//open both current locations
		int cfdb=open(bp,O_RDWR);
		int cfda=open(fp,O_RDWR);
		struct stat bs;
		Stat(bp, &bs);
		
		//check modification time
		if(bs.st_mtim.tv_sec < stB->st_mtim.tv_sec)
		{
			
			close(cfdb);
			//reopens with truncation to clear it so the file can be written to it
			cfdb=open(bp, O_TRUNC|O_RDWR);   
			size_t cnt=1;
			char buff[100];
			
			//write the from the first directory file to the second directory file
			while((cnt=rio_readn(cfda,buff,100)) !=0)
			{
				
				rio_writen(cfdb,buff,cnt);
				
				
			}
			//close locations
			close(cfdb);
			close(cfda);
			//print to console what happened
			printf("older file in second directory updated with newer file in first directory\n");
			
			
		}
		else
		{           
			//reopens with truncation to clear it so the file can be written to it
			close(cfda);
			cfda=open(fp, O_TRUNC|O_RDWR);
			int cnt=1;
			char buff[100];
			
			//wrtie from file from first directory to file in second directory
			while((cnt=rio_readn(cfdb,buff,100)) !=0)
			{
				
				rio_writen(cfda,buff,cnt);
				
				
			}
			
			//close locations
			close(cfdb);
			close(cfda);
			//print to console what happened
			printf("older file in first directory updated by newer file in second directory\n");
			
			
		}
		
	}
	else
	{
		//creat the file since it was not found in the second directory
		int cfdb=open(bp,O_CREAT|O_TRUNC|O_RDWR);
		int cfda=open(fp,O_RDWR);
		size_t cnt=1;
		char buff[100];
		
		//write from file in first directory to the new file in the second directory
		while((cnt=Rio_readn(cfda,buff,100-1)) !=0)
		{
			
			Rio_writen(cfdb,buff,cnt);
		
		
		}
		//make file permissions identical between the two files
		chmod(bp,stB->st_mode);
		
		//close locations
		close(cfdb);
		close(cfda);
		
		//print what happened to console
		printf("a file in the first directory is not found in the second\n");
		printf("placed file from the first directory into the second directory\n");
		
		
	}
	
	return 0;
	
}
