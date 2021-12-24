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



int main(int argc, char **argv) {


   struct addrinfo hints;
   struct addrinfo *resultado, *iterator;

   memset(&hints, 0, sizeof(struct addrinfo));

   hints.ai_flags = AI_PASSIVE;
   hints.ai_family = AF_UNSPEC;
   hints.ai_socktype = 0;
   hints.ai_protocol = 0;
   hints.ai_addrlen = NULL;
   hints.ai_addr = NULL;
   hints.ai_canonname = NULL;
   hints.ai_next = NULL;

   if(getaddrinfo(argv[1], NULL, &hints, &resultado) != 0){
      printf("Error al ejecutar addrinfo\n");
      return -1;
   }

   for(iterator = resultado; iterator != NULL; iterator = iterator->ai_next){
      switch(iterator->ai_family){
         case AF_INET:;
            struct sockaddr_in *info = iterator->ai_addr;
            char ip[INET_ADDRSTRLEN + 1]="";
            inet_ntop(AF_INET, &(info->sin_addr), ip, INET_ADDRSTRLEN + 1);
            printf("%s\t", ip);
         break;

         case AF_INET6:;
            struct sockaddr_in6 *info6 = iterator->ai_addr;
            char ipv6[INET6_ADDRSTRLEN + 1]="";
            inet_ntop(AF_INET, &(info->sin_addr), ip, INET_ADDRSTRLEN + 1);
            printf("%s\t", ip);
         break;

         case AF_INET6:;
            struct sockaddr_in6 *info6 = iterator->ai_addr;
            char ipv6[INET6_ADDRSTRLEN + 1]="";
            inet_ntop(AF_INET6, &(info6->sin6_addr), ipv6, INET_ADDRSTRLEN + 1);
            printf("%s\t", ipv6);
         break;

         default:
            printf("Error: ai_family no definida.\n");
         break;
      }

       printf("%i\t%i\t\n", iterator->ai_family, iterator->ai_socktype);
   }

   freeaddrinfo(resultado);

   return 0;
}


