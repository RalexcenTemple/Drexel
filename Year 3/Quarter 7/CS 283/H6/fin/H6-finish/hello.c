#include "csapp.h"

void *thread(void *vargs);

int main(int argc, char* argv[])
{
	
	if(argc == 2)
	{
	
		pthread_t tid;
	
		long numT = atoi(argv[1]);
		int n = 0;
	
		for(n; n < numT; n++)
		{
		
			Pthread_create(%tid, NULL, thread, NULL);
			Pthread_join(tid, NULL);
		
		}
	
	}else
	{
		
		fprint("Incorrect Number of Command-line Arguments");
		
	}
	exit(0);
	
}

void *thread(void *vargp) /*thread routine */
{
	
	printf("Hello,World!\n");
	return NULL;
	
}