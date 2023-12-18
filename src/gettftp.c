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
	char service[NI_MAXSERV];
	//struct sockaddr_in * ip = (struct sockaddr_in *)res->ai_addr;
	
	getnameinfo(res->ai_addr,res->ai_addrlen,host,NI_MAXHOST,service,NI_MAXSERV,NI_NUMERICHOST | NI_NUMERICSERV);
	printf("ip : %s\n",host);
	//inet_ntop(res->ai_family,&(ip->sin_addr),ipstr,strlen(ipstr));
	
	return EXIT_SUCCESS;	
}

int createRRQmsg(char * file, char * mode, char * buffer){
	int file_size = strlen(file);
	int msg_size = 2 + strlen(file) + 1 +  strlen(mode) + 1;	
	
	buffer[0] = 0;
	buffer[1] = 1;
	strcpy(buffer + 2, file);	
	buffer[2 + file_size] = 0;
	strcpy(buffer + 2 + file_size + 1, mode);	
	buffer[msg_size - 1] = 0;	
	
	return EXIT_SUCCESS;
}

int main (int argc, char ** argv){
	if (argc != 4){
		printf("usage : ./gettftp <host> <port> <file>\n");
		return EXIT_FAILURE;
	}

	struct addrinfo hints;
	// asign all values of hints to 0  (except for family and socktype)
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_DGRAM;
	
	struct addrinfo *res;
	
	getaddrinfo(argv[1],argv[2],&hints,&res);
	
	displayIPaddress(res);
	
	printf("port : %s\n",argv[2]);
	printf("file : %s\n",argv[3]);	
	
	int socket_fd;
	char mode[] = "octet";
	int msg_size = 2 + strlen(argv[3]) + 1 +  strlen(mode) + 1;
	char RRQ_msg[msg_size];
	
	createRRQmsg(argv[3], mode, RRQ_msg);

	if ((socket_fd = socket(res->ai_family, res->ai_socktype, res->ai_protocol)) == -1){
		perror("socket failure");
		return 1;
	}

	printf("socket_fd = %d\n",socket_fd);
	sendto(socket_fd,RRQ_msg,msg_size,0,res->ai_addr,res->ai_addrlen);
	perror("sendto");

	return EXIT_SUCCESS;
}

