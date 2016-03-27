CC=gcc
SOURCES=main.c common.c encoder.c decoder.c
HEADERS=decoder.h encoder.h common.h
CFLAGS=-g -Wall -std=c99


encode:main.c encoder.c decoder.c
	gcc main.c encoder.c decoder.c common.c -o encode
	

decode:main1.c encoder.c decoder.c 
	gcc main1.c decoder.c encoder.c common.c -o decode
	
decodeARM: main1.c encoder.c extractBit.s decodeChar.s codeToBinary.s binaryToText.s decodeFile.s
	gcc -g -O0 extractBit.s decodeChar.s codeToBinary.s binaryToText.s decodeFile.s common.c main1.c encoder.c -o decodeARM
	
all: mains

main: $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) $(SOURCES) -o main

clean:
	rm -f main
