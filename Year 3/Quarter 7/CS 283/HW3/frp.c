//Reed Ceniviva
//CS 283 HW3
//I/O Assignment

//Program is to grab all txt files in the current directory and search for
//a word in them and replace it with a new word
//was not able to get prefix working in time

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <stdbool.h>

//function prototypes
char * rep(int l,char line[512], char word[50], char nword[50], char *fname);

int main (int argc, char *argv[]){

//prepair a bunch of arrays to handle the files as they are broken into substrings and further substrings
char af[512];
char at[512][512];
char al[512][512];
char word[50];
char nword[50];

//get the command line variables passed when called for the word to find and replace 
strcpy(word, argv[1]);
strcpy(nword, argv[2]);
//needed for counting occurences
int count = 0;

//be able to access the current directory
DIR *cd;
struct dirent *dir;
cd = opendir(".");


//directory opened correctly
if (cd)
{
	//there are files in the directory
	while ((dir = readdir(cd)) != NULL)
	{
		//grab all file names and put into an array af (all files)
		strncpy(af, dir->d_name, 511);
		
		af[511] = '\0';
		size_t afnum = strlen(af);
		
		//grab text files from af and put them in a different array at (all text)
		if(afnum > 4 && strcmp(af + afnum - 4, ".txt") == 0)
		{
			
			strncpy(at[count], af, afnum);
			count = count + 1;
		}
	}
	//clear mem foir directory
	closedir(cd);
}
	//for all the filenames in at
	for(int i = 0; i < count; i++)
	{
		//open file based on the strings in at, print filename to stdout for log
		FILE *fp = fopen(at[i], "r+");
		printf("File: %s \n", at[i]);
		//counter2
		int c2 = 0;

		//while the file is loaded into al (all lines) array
		while(fgets(al[c2], 512, fp) != NULL)
		{
			//last character set to end of file
			al[c2][strlen(al[c2])] = '\0';
			//copys the edited line back into the array with a word replaced or not
			strcpy(al[c2],rep(c2, al[c2], word, nword, at[i]));
			c2++;
		}
		//close for reading, open for writing
		fclose(fp);
		fp = fopen(at[i], "w");
		
		//write to file
		for(int j = 0; j <= c2; j++)
		{
			char string[512];
			strcpy(string, al[j]);
			fprintf(fp, "%s", string);
			memset(string,0,sizeof(string));
		}
		//close for writing, clear memory
		fclose(fp);
		memset(al,0,sizeof(al));
	}
	return(0);
}

//function to replace words in a string
char *rep(int l,char str[512], char word[50], char nword[50], char *fname){
//resulting string
char *res;

//various counters and length variables for concatination 
int k, count = 0;
int Rlen = strlen(nword);
int Flen = strlen(word);

//while the character is not null
for (k = 0;str[k] != '\0';k++)
{
	//if the location of the first occurence of word is at str[k]	
	if (strstr(&str[k], word) == &str[k])
	{
		printf("Line:%d= %s changed to %s\n",l+1,word,nword);
		 
		count=count +1;
		k += Rlen - 1;
		 
	}
}

//allocate enough space for the result
res = (char *)malloc(k + count * (Flen - Rlen) + 1);
//reset k to be used again
k = 0;
//while str isnt empty
//copy lines into result, inserting the word to replace, where it should be as it goes
while (*str)
	{
		
	if (strstr(str,word)==str)
		{
			strcpy(&res[k], nword);
			k += Rlen;
			str += Flen;
		}
	else
		{
			res[k++] = *str++;
		}
	}
	//clear result for next file
	res[k] = '\0';


	return res;
}
