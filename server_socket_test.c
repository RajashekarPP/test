/*	File Name	:server_socket_test.c
	Date		:29-Nov-2018
	version		: -
	Description	:create a server such that they should communicate with given client using the socket
*/
#include <unistd.h> 
#include <stdio.h> 
#include <arpa/inet.h>
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 

#define PORT 5555

int main(int argc , char const *argv[])
{
	int server_fd,new_socket_fd, valread;
	struct sockaddr_in address;
	int opt = 1;
	int address_length =sizeof(address);
	char buffer[1024]={0};
	char *hello = "hello from user server";

	// creation of a socket
	server_fd = socket(AF_INET,SOCK_STREAM,0);
	if(server_fd == 0)
	{
		perror("socket creation ");
		return -1;
	}
	perror("server socket ");
	//This helps in reusing the IP address and port address
	if( setsockopt(server_fd,SOL_SOCKET,SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
	{
		perror("setsockopt");
		return -1;
	}
	perror("setsockopt ");
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY; // receive from any client or system
	address.sin_port = htons( PORT );

	//binding the socket to the local host and giev port number
	if( bind( server_fd,(struct sockaddr *)&address,sizeof(address))<0)
	{
		perror("bind ");
		return -1;
	}	
	perror("bind ");
	if( listen(server_fd,3)<0 )
	{
		perror("listen ");
		return -1;
	}
	perror("listen ");
	if ((new_socket_fd = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&address_length))<0)
	{
		perror("accept");
		return -1;
	}
	perror("accept ");
	valread = read(new_socket_fd , buffer ,1024 ); 
	printf("data read is : %s\n",buffer);
	send(new_socket_fd , hello , strlen(hello) , 0 ); 
	puts("data sent to the client by the server");

	return 0;
}
