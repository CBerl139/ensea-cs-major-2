#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define BYEBYE_MESSAGE "test 123 12\n"

int main (int argc, char ** argv){
	if (argc != 3){
		printf("usage : ./puttftp <host> <file>\n");
		return EXIT_FAILURE;
	}
		
	
	return EXIT_SUCCESS;
}
