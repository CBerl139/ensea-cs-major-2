#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define BYEBYE_MESSAGE "test 123 12\n"

int main (int argc, char ** argv){
	if (argc != 3){
		printf("usage : ./enseatftp <host> <file>\n");
	}
		
	if (!strcmp(argv[1],"hello")){
		printf("it works\n");
		return EXIT_SUCCESS;
	}
	
	return EXIT_FAILURE;
}
