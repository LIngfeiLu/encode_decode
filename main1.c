/**
 * THIS FILE MAY BE USED FOR TEST CODE. IT WILL NOT BE COLLECTED
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "common.h"
#include "encoder.h"
#include "decoder.h"

int main(int argc, char *argv[]){
    //createReverseMapping();
    decodeFile(argv[1], argv[2], argv[3], 2);
    //printf("%d\n", extractBit('a', 0));
    //char arr[6] = {'0', '0', '0', '0', '0', '0'};
    //printf("%c\n", decodeChar(arr)); 
}