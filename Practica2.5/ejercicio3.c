include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <errno.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <time.h>

int main(int argc, char **argv) {

   struct addrinfo hints;
   struct addrinfo *resultado, *iterator;
   
   memset(&hints, 0, sizeof(struct addrinfo));

   hints.ai_flags = AI_PASSIVE;
   hints.ai_family = AF_UNSPEC;
   hints.ai_socktype = SOCK_DGRAM;
   hints.ai_protocol = 0;
   hints.ai_addrlen = NULL;
   hints.ai_addr = NULL;
   hints.ai_canonname = NULL;
   hints.ai_next = NULL;
   
  if(getaddrinfo(argv[1], argv[2], &hints, &resultado) != 0){
      printf("Error al ejecutar addrinfo\n");
      return -1;
   }

   int socketUDP = socket(resultado->ai_family, resultado->ai_socktype, resultado->ai_protocol);


   freeaddrinfo(resultado);
   char buf[2];
   char host[NI_MAXHOST];
   char serv[NI_MAXSERV];

   struct sockaddr_storage client_addr;
   socklen_t client_addrlen = sizeof(client_addr);

   sendto(socketUDP, argv[3], 2, 0, resultado->ai_addr, resultado->ai_addrlen);

   printf("%s\n", argv[3]);
   
   if(*argv[3] == 'd' || *argv[3] == 't'){
      char s[50];
      ssize_t bytes = recvfrom(socketUDP, s, 50, 0, (struct sockaddr *) &client_addr,&client_addrlen);
      s[bytes] = '\0';

      printf("%s\n", s);
   }

   return 0;
}







