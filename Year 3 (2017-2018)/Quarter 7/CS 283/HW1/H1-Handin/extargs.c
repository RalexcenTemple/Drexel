#include <stdio.h>
#include <string.h>
#define SIZE 128

int main(int argc, char *argv[])
{
		//used for debugging
//		printf("given file name: ");
//	   printf("%s",argv[1]);
//		printf("\n");
		
		//declare variable
		int count = 1;
		char line[SIZE];
		FILE * file = fopen(argv[1], "r");
		FILE * temp = fopen(argv[1], "r");		

		//check if arg passed/file viable
		if(argc < 2 || file == NULL)
		{
			printf("error with passed-in data \n");
			return -1;
		
		}
		
//used for testing purposes
		printf("original: \n");
		while(fgets(line,SIZE, temp))
		{
			printf("%s",line);
		}


		//place file pointer at the end of the file
		fseek(file,0,SEEK_END);
		//sets bot to the location of the top element of the pointer
		int bot = ftell(file);
		
		
		printf("reversed: \n");
		//while the offset from the end of the file is less that the distance
		//to the begining
		while(count < bot)
		{
			//store the line at the end of the file offset by count
			fseek(file, -count, SEEK_END);
			//print the line file now points to character by character
			printf("%c",fgetc(file));
			//increment count to move to next line
			count++;
		}

//used for testing purposes
//		printf("\n");
//		printf("count: ");
//		printf("%d",count);
//		printf("\n");

		//close memory
		printf("\n \n");
		fclose(file);
		return 0;
}

