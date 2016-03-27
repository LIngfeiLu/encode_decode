/* First partner's name: Lingfei Lu, A91046735
 * Second partner's name: Junxi Li, A91105747
 */
#include <stdio.h>
#include <stdlib.h>
#include "warmup.h"

 int main(int argc, char** argv){
      //open input and output file in read binary and write binary mode
      FILE *infile = fopen(argv[1], "rb");
      FILE *outfile = fopen(argv[2], "wb");

      //loop until file reach the end
      while(1)
      {
      	int num;
            //read input 4 bytes at a time and store the value in num, if
            //less than 4 bytes left, then break the loop
            int check = fread(&num, 4, 1, infile);
            if(check < 1){
                  break;
            }
            //call reorder_bytes to reversed each 4 bytes value
            int reverse = reorder_bytes(num);
            //write the reversed number into output file
            fwrite(&reverse, 4, 1, outfile);
      }
      //change line
      fprintf(outfile, "\n");
      //close files
      fclose(infile);
      fclose(outfile);
}
