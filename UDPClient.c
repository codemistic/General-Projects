#include<sys/socket.h>

#include<netdb.h>

#include<stdio.h>

#include<stdlib.h>

#include<string.h>

int main(int argc,char* argv[])

{

 struct sockaddr_in server,client;

 if(argc!=3)

 printf("Input format not correct");

 int sockfd=socket(AF_INET,SOCK_DGRAM,0);

 if(sockfd==-1)

 printf("Error in socket ();");

 server.sin_family=AF_INET;

 server.sin_addr.s_addr=INADDR_ANY;

 server.sin_port=htons(atoi(argv[2]));

 char buffer[100];

 printf("Enter message to server=");

 fgets(buffer,100,stdin);

 if(sendto(sockfd,buffer,sizeof(buffer),0,(struct 

sockaddr*)&server,sizeof(server))<0)

 printf("Error in sendto");

 return 0;

}
