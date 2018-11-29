/*	File Name	:client_socket_test.c
	Date		:29-Nov-2018
	version		: -
	Description	:create a client such that they should communicate with given server using the socket
*/
#include <stdio.h> 
#include<unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 

#define PORT 5555

int main(int argc, char const *argv[])
{
	int client_socket_fd = 0 ,valread;
	struct sockaddr_in serv_addr;
	char *hello = "hello from user client";
	char buffer[1024]={0};
	if ((client_socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("socket ");
		return -1;
	}
	perror("socket client ");
	// To clear the structure data present in it
	memset(&serv_addr, '0', sizeof(serv_addr));

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);

	// Convert IPv4 and IPv6 addresses from text to binary form
	if( inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
	{
		perror("inet_pton ");
		return -1;
	}
	perror("inet_pton ");
	while( connect(client_socket_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1);
	printf("connected\n");
	perror("connect ");
	send(client_socket_fd , hello , strlen(hello) , 0 ); 
	//puts("data sent to the server by client");
	valread = read(client_socket_fd , buffer , 100 );
	printf("data from server : %s\n",buffer);
	return 0;
}
