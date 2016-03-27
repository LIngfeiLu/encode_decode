/* First partner's name: Lingfei Lu, A91046735
 * Second partner's name: Junxi Li, A91105747
 */
#include <stdio.h>
#include <stdlib.h>
#include "warmup.h"

/*
 * char_freqs takes one parameter which takes one parameter which is the input
 * file. The function will count the frequency of every element in the file
 */
 unsigned int *char_freqs(FILE *fp){
  int i;
  // if the pointer points to null, just return null
  if(fp == NULL)
  {
    return NULL;
  }

  //create a int arr
  unsigned int *arr = malloc(256*sizeof(int));
  //set every element of arr[i] to 0
  for(i =0; i < 256; i++ )
  {
    arr[i] = 0;
  }

  //loop until reach the end of the file
  while(1)
  {
    //read 1 byte at a time
    unsigned int nextByte = fgetc(fp);

    //if reach the end of the file then break
    if(feof(fp))
      break;
    //increase the count of character by 1
    arr[nextByte]++;
  }

  //return the int pointer
  return arr;
}

/*
 * reorder_bytes takes one int number, that will be reversed order
 */
 int reorder_bytes(int num){
  //initial each local varible to 0
  int i, temp, output = 0;

  //create a int arr size of 4
  int arr[4];

  // shift the input num 4 times and then and with 0xFF
  for(i = 0; i < 4; i++)
  {
    //The folloewing code will only keep least significant 1 bytes
    arr[i] = num >> (8*i);
    arr[i] = arr[i] & 0xFF;
  }

  //right shift input number and then or with output, which equvalent to add
  for(i = 0; i < 4; i++)
  {
    temp = 0;
    temp = arr[i] << ((3-i)*8);
    output = output | temp;
  }
  //return the reversed number
  return output;

}
