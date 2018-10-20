/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   reverse.c
 * Author: Ralex
 *
 * Created on January 24, 2018, 8:05 PM
 */

#include <stdio.h>
#include <string.h>
#define SIZE 128

int main(int argc, char *argv[])
{
      printf("given file name: ");
      printf("%s",argv[1]);
      printf("\n");

      int count = 1;
      char line[SIZE];
      FILE * file = fopen(argv[1], "r");
      FILE * temp = fopen(argv[1], "r");

      if(argc < 2)
      {
         printf("argument not passed \n");
      }
      else
      {

      while(fgets(line,SIZE,file))
      {
//       printf("%s",line);
         count++;
      }

      printf("count: ");
      printf("%d",count);
      printf("\n");
      char *Lines[count];
      Lines[0] = "0";
      printf("before Lines[0] \n");
      printf("%s",Lines[0]);
      printf("\n after Lines[0] \n");
      int i = 0;

      while(fgets(Lines[i],count,temp))
      {
       //       printf("%d",i);
//       printf("\n");
//       printf("%s",line);
         i++;

      }
//    printf("%d",Lines[0]);
      for(int j = 0; j < count;j++)
      {

         printf("%s",Lines[j]);
         printf("\n");
      }

   }
}

