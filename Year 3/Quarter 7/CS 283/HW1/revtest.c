#include <stdio.h>
#include <string.h>
#define SIZE 128

int main(int argc, char *argv[])
{

	printf("given file name: ");
	printf("%s",argv[1]);
	printf("\n");

	if(argc < 2)
	{
		printf("\n please include file name \n");
		return(1);
	}

	int count = 1;
	int i = 0;
	int j;
	char line[SIZE];
	FILE * fp = fopen(argv[1], "r");
	FILE * temp = fopen(argv[1],"r");

	if(fp == NULL)
	{
		printf("\n file not found \n");
		return(2);
	}

	while(fgets(line,SIZE,temp))
	{
		count++;
	}

	char *Lines[count][128];

	printf("\n load \n");
	while(fgets(line,SIZE,fp))
	{
		if(i < count)
		{
			printf("%d",i);
			printf(" :");
			Lines[i][0] = line;
			printf("%s",Lines[i][0]);
			i++;
		}
	}
	printf("\n Lines[1][0]: ");
	printf("%s",Lines[1][0]);
	printf("\n print \n");
//	j = (count - 1);
//	for(j; j >= 0; j--)
//	{
//		printf("%s",Lines[j][0]);	
//	}
	
	
	j = 0;
	for(j;j < count;j++)
	{
	
		printf("%s",Lines[j][0]);

	}
}
