/* 3-11-08 programmazione rete, prova con bind */

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>

int main(){

  int sockfd, be; // socket file descriptor && bind result

  struct sockaddr_in local; // local information


  local.sin_family = AF_INET;
  local.sin_port = htons(8000);
  local.sin_addr.s_addr = INADDR_ANY;
  memset(local.sin_zero,"\0" , sizeof local.sin_zero );
  if((sockfd = socket(PF_INET, SOCK_STREAM, 0)) == -1){
    
    fprintf(stderr, "ERROR initialize socket: %s", gai_strerror(sockfd));
    exit(1);
  };

  if((be = bind(sockfd, (struct sockaddr *)&local, sizeof local)) == -1){
    
    fprintf(stderr, "ERROR binding socket: %s", gai_strerror(sockfd));
    exit(1);

  };
  
  puts("ALL COMPLETE");

  return 0;
}
