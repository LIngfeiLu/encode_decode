/* First partner's name: Lingfei Lu, A91046735
 * Second partner's name: Junxi Li, A91105747
 */
#include <stdio.h>
#include <stdlib.h>
#include "warmup.h"

 int main(int argc, char** argv){
     /* Your main code for counting characters in a file goes here */

     /* To write your output to file use the following statement:
      * fprintf(fp,"%c - %d \n", c, count);
      * fp: file pointer
      * c: Character symbol
      * count: Character count
      */

      //if pass in less than 2 argument, then return main immediately
      if(argc < 2){
        return -1;
      }

      int i;
      //open infile in read mode and outfile in write mode
      FILE *infile = fopen(argv[1], "r");
      FILE *outfile = fopen(argv[2], "w");

      //arr is a int array that record frequency 
      unsigned int *arr  = char_freqs(infile);

      //print the frequency of each character
      for(i = 0; i < 256; i++)
      {
        //print the frequency only if the character appears at least once
      	if(arr[i] != 0)
      		fprintf(outfile, "%c" "%c" "%d\n", i, ':', arr[i]);
      }

      //free the malloc and set arr to null is arr is not null
      if(arr != NULL)
      {
      	free(arr);
        arr = 0;
      }
      
      //close two files
      fclose(infile);
      fclose(outfile);
    }
