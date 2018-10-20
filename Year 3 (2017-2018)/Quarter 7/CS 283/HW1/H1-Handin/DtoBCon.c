#include <stdio.h>
#include <stdlib.h>
#define SIZE 32
//Reed Ceniviva
//CS 283 Thur 630-930
//H1 Binary Converter


int main(int argc, char *argv[]){
	//gets number from command
	//creates array and varaibles for storing needed information
	int num = atoi(argv[1]);
	int arr[SIZE];
	int i;
	int j = (SIZE - 1);
	int t = 0;	
	
	//while num has not been reduced to 0
	while(num > 0) 
	{
//		printf("%d",num);
//		printf("\n");
		//check if div by two and puts 1 or 0 in array
		arr[t] = num % 2;
//		printf("\n");
//		printf("%d",arr[t]);
//		printf("\n");
		//reduce num by half to check next bit
		num = num / 2;
//		printf("%d",num);
//		printf("\n");
		//move up in array as not to overwrite info
		t++;
	}
	//used for easily readable output
	printf("\nNumber passed: ");
	printf("%s",argv[1]);
	printf("\n \n");
	printf("Binary Representation: ");
	for(i = t; i < SIZE; i++)
	{
		//populate array with zeros after previously writing data
		arr[i] = 0;
	}
	
	for(j; j >= 0; j--)
	{
		//print out entire array with result and leading zeros
		printf("%d", arr[j]);
	}
	//output formatting
	printf("\n \n");
}

