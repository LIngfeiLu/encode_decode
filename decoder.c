/* First partner's name: Lingfei Lu, A91046735
 * Second partner's name: Junxi Li, A91105747
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "decoder.h"

/**
 * Takes a char c and int index as input. 
 * Extracts the bit at the input index from the char c. The 0 index
 * refers to the LSB, so for example, index 2 should extract the 3rd
 * least significant bit.
 *
 * @param c the char to extract a bit from
 * @param index the index of the bit to extract
 * @returns the value of the bit at index in c
 */
int extractBit(char c, int index){
    int clear = 1;
    //shift 1 by index
    clear = clear << index;
    //add clear and input character
    int output = clear & c;
    //shift output to right by index
    output = (unsigned int)output >> index;
    return output;
}

/**
 * Takes a 6 character array b as input and returns the corresponding
 * char from MAPPING that is indexed by the binary ASCII string b.
 * For example, if b = "010101", then the char that is mapped to it is 
 * in MAPPING, index 1*16 + 1*4 + 1*1 = 21.
 *
 * @param b a pointer to a 6 character array, with ASCII '1's and '0's
 * @returns the corresponding character from MAPPING
 */
char decodeChar(char *b){
    if(b == NULL)
        return 0;
    int i, num = 0, count = 1;
    //loop 6 times
    for(i = 5; i >= 0; i--){
        //if character arry at index i is 1 increase by 1
        if(*(b+i) == '1')
            num += count;
        //times count by 2
        count *= 2;
    }
    return MAPPING[num];
}

/**
 * Takes a FILE handle in as input (corresponding to
 * an encoded file) and reads the file, char by char. The
 * bit at the input index of each char is extracted (by calling
 * extractBit). The least significant bit is in index 0.
 *
 * For each character, if the extracted bit is 0, output ASCII '0' to
 * the output file. If the extracted bit is 1, output ASCII
 * '1' to the output file.
 *
 * @param in the input file handle to read from
 * @param out the output file to write the extracted ASCII binary into
 * @param index the index of the bit to extract from each char
 */
void codeToBinary(FILE *in, FILE *out, int index){
    //if in file or out file are null, end the function
    if(in == NULL || out == NULL)
        return;
    while(1)
    {
        //get the char in file in
        char temp = fgetc(in);
        //if reach the end of file, break
        if(feof(in))
        {
            break;
        }

        //write the output to the out file
        //'0' is the offset
        fprintf(out, "%c", extractBit(temp, index)+'0');
    }
}

/**
 * Takes a FILE handle in as input (corresponding to a
 * "binary" decoded file) and reads the file, 6 chars at a
 * time. Each 6 chars (all ASCII 0's and 1's) should be read into a
 * char array and decoded into its corresponding char (by calling
 * decodeChar). The resulting chars would be output to the FILE handle
 * pointed to by out.
 *
 * @param in the input file, encoded as ASCII '1's and '0's
 * @Param out the decoded output file (ASCII)
 */
void binaryToText(FILE *in, FILE *out){
    //if the in file or the out file is null, end the function
    if(in == NULL || out == NULL)
        return;
    char *arr = (char*)malloc(6*sizeof(char));
    //if malloc fails, end the function
    if(arr == NULL)
        return;
    while(1)
    {
        //read the file 1 byte at a time, iterate 6 times
        //we get a array with 6 bytes
        int check = fread(arr, 1, 6, in);
        //if check is less than 6, there is no enough information to be read
        if(check < 6)
        {
            break;
        }
        //decode the array, then get a char
        char test = decodeChar(arr);
        //if test is null, return
        if(test == 0)
            return;
        //write that char into the out file
        fprintf(out, "%c", test);
    }
    if(arr != NULL)
        free(arr);
}

/**
 * Reads in a file from the specified input path and outputs a a binary decoding to
 * specified bin path and a fully decoded version to specified output path.
 * This should simply open the necessary files, call the above helper functions
 * in the correct sequence, and close the necessary files.
 *
 * @param input the path to the input file
 * @param bin the path to the decoded ASCII binary output file
 * @param output the path to the decoded output file
 * @param index The index of the bit from which binary values should be extracted
 */
void decodeFile(char* input, char* bin, char* output, int index){
    //if the input array or bin array or output array is null, end function
    if(input == NULL || bin == NULL || output == NULL)
    {
        return;
    }

    //open the in file in read mode
    FILE *in = fopen(input, "r");
    //open the binary file in write mode
    FILE *binary = fopen(bin, "w");
    //if in or binary file is null, means fopen fails, end the function
    if(in == NULL || binary == NULL)
        return;


    //translate the encoded message into the bianry file
    codeToBinary(in, binary, index);
    fclose(binary);

    //open binary file in read mode
    binary = fopen(bin, "r");
    //open output file in write mode
    FILE *character = fopen(output, "w");
    //if binary file or output file is null, means fopen fail, end function
    if(binary == NULL || character == NULL)
        return;

    //translate the binary message into deocded message
    binaryToText(binary, character);

    //close all files
    fclose(in);
    fclose(binary);
    fclose(character);
}
