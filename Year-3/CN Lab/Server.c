#include<unistd.h>
#include<stdio.h>
#include<winsock.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<string.h>

#define PORT 8080

int main()
{
	int sfd, nsfd, val_read, opt = 1;
	struct sockaddr_in address;
	int addrlen = sizeof(address);
	
	if((sfd = socket(AF_INET, SOCK_STREAM, 0)) != 0)
	{
		perror("Socket creation failed");
		exit(errno);
	}
}
