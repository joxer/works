#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>


int main(){

  struct addrinfo local, *serv;
  struct sockaddr_storage it;
  socklen_t addr_size;
  int addr;

  int sock, bn, ln, acc;

  memset(&local, 0, sizeof local);

  local.ai_family = AF_UNSPEC;
  local.ai_socktype = SOCK_STREAM;
  local.ai_flags = AI_PASSIVE;
  if((addr = getaddrinfo(NULL, "3490", &local, &serv)) == -1){
    perror("error");
    exit(1);
  };

  sock = socket(serv->ai_family, serv->ai_socktype, serv->ai_protocol);

  if((bn = bind(sock, serv->ai_addr, serv->ai_addrlen)) == -1){
    
    perror("error");
    exit(1);
  };

  ln = listen(sock, 10);
  
  
  addr_size = sizeof it;

  if((acc = accept(sock, (struct sockaddr *)&it, &addr_size)) == -1){

    perror("accept");
    

  }else{
    
    puts("CONNECTED");
    

  };
  
  puts("LULZ");

  


  
}
