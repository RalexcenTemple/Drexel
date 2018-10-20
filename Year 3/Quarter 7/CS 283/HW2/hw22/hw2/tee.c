//Reed Ceniviva
//CS283
//H2
//Q4

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

static int check = 0;


int main(int argc, char *argv[])
{

	char car;
	char buff[128];
	size_t len;
	char *fa;
	int temp, num;
	FILE *fin[5];

	while((car = getopt(argc,argv, "a")) != -1)
	{		
		if (car == "a")
		{
			check = 1;		
		}
		else
		{
		printf("unknown option \n");
		abort();
		}
	}

	if( car == "a")
	{
		fa = "a";
	}
	else
	{
		fa = "w";
	}

	num = argc - optind;

	if(num > 0)
	{
		if(fin == NULL)
		{
			return 1;
		}
	}
	
	for(temp = optind; temp < argc; temp++)
	{

		FILE file = fopen(argv[temp], fa);

		if(file == NULL)
		{
			if(fa > 0)
			{
				for( temp = 0; temp < files; temp++)
				{
					fclose(fin[temp]);
				}
			}
		}
		fin[temp = optind] = file;
	}
	
	FILE *out = fopen("tee.c", "r");
	
	while((len = fread(&buff[0], 1 , sizeof(buff), out)) > 0)
	{
		fwrite(&buff[0], 1, len, stdout);
		
		for( temp = 0; temp < files; temp++) 
		{
			fwrite(&buff[0], 1, len, in[temp]);
		}
	}

}
