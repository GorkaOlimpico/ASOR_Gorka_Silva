#include <stdio.h>
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

   if (bind(socketUDP, resultado->ai_addr, resultado->ai_addrlen) != 0) {
     printf("Error al ejecutar el bind.");
     exit(EXIT_FAILURE);
   }

   freeaddrinfo(resultado);

   char buf[2];
   char host[NI_MAXHOST];
   char serv[NI_MAXSERV];

   struct sockaddr_storage client_addr;
   socklen_t client_addrlen = sizeof(client_addr);

   while(1){
      ssize_t bytes = recvfrom(socketUDP, buf, 2, 0, (struct sockaddr *) &client_adrr, &client_addrlen);
      buf[1] = '\0';

      getnameinfo((struct sockaddr *) &client_addr, client_addrlen, host, NI_MAXHOST, serv, NI_MAXSERV, NI_NUMERICHOST|NI_NUMERICSERV);

      printf("%i byte(s) de %s:%s\n", bytes, host, serv);

      time_t tiempo = time(NULL);
      struct tm *tm = localtime(&tiempo);
      size_t max;
      char s[50];

      if (buf[0] == 't'){
         size_t bytesT = strftime(s, max, "%I:%M:%S %p", tm);
         s[bytesT] = '\0';
         sendto(socketUDP, s, bytesT, 0, (struct sockaddr *) &client_addr, client_addrlen);
      }
      else if (buf[0] == 'd'){
         size_t bytesT = strftime(s, max, "%Y-%m-%d", tm);
         s[bytesT] = '\0';
         sendto(socketUDP, s, bytesT, 0, (struct sockaddr *) &client_addr, client_addrlen);
      }
      else if (buf[0] == 'q'){
         printf("Saliendo...\n");
         exit(0);
      }
      else {
         printf("Comando %c no soportado.\n", buf[0]);
      }
   }


   return 0;
}



