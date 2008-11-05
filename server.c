/* 

3-11-08 programmazione rete, prova con bind 

   -aggiunto listen
   -aggiunto accept
*/
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>

#define BACKLOG 15

int main(){

  int sockfd, be, lis, newfd; // socket file descriptor && bind result && listen && new file descriptor

  struct sockaddr_in local, remote ; // local && remote information


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
  
  if((lis = listen(sockfd, BACKLOG)) == -1){

    fprintf(stderr, "ERROR listening on the socket: %s", gai_strerror(sockfd));
    exit(1);


  };
  
  if((newfd = accept(sockfd, (struct sockaddr *)&remote, sizeof(remote))) == -1){
      
      fprintf(stderr, "ERROR in accept: %s", gai_strerror(sockfd));
    exit(1);
    }
    
  puts("ALL COMPLETE");

  return 0;
}
