   #include <pthread.h>
   #include <stdio.h>
   #define NUM_THREADS 8
   
   //looking at example 2 from POSIX Threads Programming (from LLNL)
   //create structure to hold thread data
	struct threadData
	{
		int  tid;
		int  sum;
		char *message;
   };
   
   char *messages[NUM_THREADS];
   
   struct threadData tDataArray[NUM_THREADS];
   
   void *PrintHello(void *threadarg)
    {
		
		int taskid, sum;
		char *hello_msg;
		
		//looking at example 2 from POSIX Threads Programming (from LLNL)
		//define the structure of threadData and store data into variables
		/* ... */
		struct threadData *tData;
		tData = (struct threadData *) threadarg;
		taskid = tData->tid;
		sum = tData->sum;
		hello_msg = tData->message; 
		/* ... */
	 
		printf("Thread %d %s Sum=%d\n", taskid, hello_msg, sum);
		pthread_exit(NULL);
	 
    }

	int main(int argc, char *argv[])
	{
		
		pthread_t threads[NUM_THREADS];
		int rc, t, sum;
		sum=0;
		messages[0] = "Hello-0";
		messages[1] = "Hello-1";
		messages[2] = "Hello-2";
		messages[3] = "Hello-3";
		messages[4] = "Hello-4";
		messages[5] = "Hello-5";
		messages[6] = "Hello-6";
		messages[7] = "Hello-7";
	 
		for(t = 0; t < NUM_THREADS; t++)
		{
		  
			sum = sum + t;
			//looking at example 2 from POSIX Threads Programming (from LLNL)
			//using the structure to hold the data
			//passing the data to "PrintHello" function within the pthread_create call
			/* ... */
			tDataArray[t].tid = t;
			tDataArray[t].sum = sum;
			tDataArray[t].message = messages[t];
			printf("Creating thread %d\n", t);
			rc = pthread_create(&threads[t], NULL, PrintHello,(void *)&tDataArray[t]);
			/* ... */
	   
		}
	  
		pthread_exit(NULL);
	 
	}
