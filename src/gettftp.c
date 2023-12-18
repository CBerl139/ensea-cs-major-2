#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

int displayIPaddress(struct addrinfo * res){
	char host[NI_MAXHOST];
	//char service[NI_MAXSERV];
	//struct sockaddr_in * ip = (struct sockaddr_in *)res->ai_addr;
	
	getnameinfo(res->ai_addr,res->ai_addrlen,host,strlen(host),NULL,0,NI_NUMERICHOST | NI_NUMERICSERV);
	printf("ip : %s\n",host);
	//inet_ntop(res->ai_family,&(ip->sin_addr),ipstr,strlen(ipstr));
	
	return EXIT_SUCCESS;	
}

int main (int argc, char ** argv){
	if (argc != 3){
		printf("usage : ./gettftp <host> <file>\n");
		return EXIT_FAILURE;
	}

	struct addrinfo hints;
	// asign all values of hints to 0
	hints.ai_flags = 0;
	hints.ai_family = 0;
	hints.ai_socktype = 0;
	hints.ai_protocol = 0;
	hints.ai_addrlen = 0;
	hints.ai_addr = NULL;
	hints.ai_canonname = NULL;
	hints.ai_next = NULL;
	
	struct addrinfo *res;
	
	getaddrinfo(argv[1],NULL,&hints,&res);
	
	displayIPaddress(res);
	
	printf("file : %s\n",argv[2]);	
	
	int socket_fd;
	if (socket_fd = socket(res->ai_family, res->ai_socktype, res->ai_protocol)){
		printf("socket_fd = %d\n",socket_fd);
	}
	
	return EXIT_SUCCESS;
}

