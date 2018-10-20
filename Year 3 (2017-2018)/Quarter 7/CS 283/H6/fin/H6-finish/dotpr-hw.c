#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
//Reed Ceniviva CS283 3/15/2018
// looking at "Example: Using Mutexes" from given text "POSIX Threads Programming (from LLNL)"

//The data is made available through this global structure
typedef struct 
{
	double      *a;
	double      *b;
	double     sum; 
	int     veclen; 
} dData;

#define NUMTHRDS 4
	// using mutex variables to complete the dot product computation
	pthread_mutex_t mutexsum;
#define VECLEN 100000
	dData dotstr;
   
   
pthread_t callThd[NUMTHRDS];
double *array_a;
double *array_b;
double big_sum;
int veclen;

void *dotprod(void *arg)
{
		
	/* ... */
	int i;
	int start;
	int end;
	int len;
	long offset;
	double mysum;
	double *x;
	double *y;
	offset = (long)arg;   
	len = dotstr.veclen;
	start = offset*len;
	end   = start + len;
	
	x = array_a;
	y = array_b;
	/* ... */
	 
	mysum = 0;
	for (i=start; i<end ; i++)
	{
		mysum += (x[i] * y[i]);
	}
	  
	/* ... */
	//lock mutex before updating value
	pthread_mutex_lock (&mutexsum);
	dotstr.sum += mysum;
	//unlock after updating
	pthread_mutex_unlock (&mutexsum);
	pthread_exit((void*) 0);
	/* ... */
	
}

//waits for all other threads to complete and then prints the sum
int main (int argc, char *argv[])
{
	long i;
	double *a, *b;
	void *status;
	pthread_attr_t attr;
	a = (double*) malloc (NUMTHRDS*VECLEN*sizeof(double));
	b = (double*) malloc (NUMTHRDS*VECLEN*sizeof(double));
	for (i=0; i<VECLEN*NUMTHRDS; i++)
	{
		a[i]=1;
		b[i]=a[i];
	}
	veclen = VECLEN;
	array_a = a;
	array_b = b;
	big_sum = 0;
	 
	/* ... */
	/* create threads */
	pthread_mutex_init(&mutexsum, NULL);
	//threads to perform the dot product calculation
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
	/* ... */
	 
	for(i=0;i<NUMTHRDS;i++)
	{
		  
		/* Each thread works on a different set of data.
		The offset is specified by 'i'. The size of
		the data for each thread is indicated by VECLEN.
		*/
		pthread_create(&callThd[i], &attr, dotprod, (void *)i);
	}
	
	pthread_attr_destroy(&attr);
	
	/* Wait on the other threads */
	for(i=0;i<NUMTHRDS;i++)
    {
        pthread_join(callThd[i],&status);
        big_sum+=args[i].sum;   // Combine partial sums
    }
	/* ... */
	//join and print result
	printf ("Sum = %f \n", big_sum);
	//cleanup
	free (a);
	free (b);
	pthread_mutex_destroy(&mutexsum);
    pthread_exit(NULL);
}
