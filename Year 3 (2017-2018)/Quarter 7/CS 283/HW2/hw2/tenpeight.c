//reed ceniviva
//cs283
//Assignment H2
#include "csapp.h"

int main(int argc, char **argv){

	   struct fstat fstat;
		int *type, *readok;

		Stat(argv[1], &fstat);
		if(S_ISREG(fstat.st_mode))
		{
			type = "regular";
		}
		else if (S_ISDIR(fstat.st_mode))
		{
			type = "directory"
		}
		else
		{
			type = "other";
		}

		if((stat.st_mode & S_IRUSR))
		{
			readok = "yes";
		}
		else
		{
			readok = "no";
		}

		printf("type: %s,read: %s\n",type, readok);
		
		exit(0);
}
