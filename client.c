
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>


int main(){

  int sock ;
  struct sockaddr_in server;

  server.sin_family = AF_INET;
  server.sin_port = htons(6000);
  server.sin_addr.s_addr =  inet_addr("127.0.0.1");
  memset(server.sin_zero, "\0", sizeof server.sin_zero);
  

  sock = socket(AF_INET, SOCK_STREAM, 0);
  
  if(connect(sock, (struct sockaddr *)&server, sizeof server) == -1){

    perror("connect");
    exit(1);

  } else{
    printf("connect");
    char buf[100] = { 0 };
    recv(sock, buf, sizeof buf, 0);
    printf("%s", buf);

  };
  
  
}
