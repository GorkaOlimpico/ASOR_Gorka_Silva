#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(int argc, char **argv) {

   char *tuberia1 ="tuberia1";

   mkfifo(tuberia1, 0777);
   int fd1 = open(tuberia1, O_RDONLY | O_NONBLOCK);

   char *tuberia2 = "tuberia2";

   mkfifo(tuberia2, 0777);
   int fd2 = open(tuberia2, O_RDONLY | O_NONBLOCK);

   char buffer[256];

   while(1){

      fd_set fds;
      FD_ZERO(&fds);
      FD_SET(fd1,&fds);
      FD_SET(fd2, &fds);

      int rc;
      if(fd1 > fd2){
         rc = select(fd1 + 1, &fds, 0, 0, 0);
      }
      else{
         rc = select(fd2 + 1, &fds, 0, 0, 0);
      }

      if (rc == -1){
         perror("Error en el select\n");
         return -1;
      }

      int bytes;
      if(FD_ISSET(fd1, &fds)){
         bytes = read(fd1, buffer, 255);
         buffer[bytes] = '\0';
         if (bytes == 0){
            fd1 = open(tuberia1, O_RDONLY | O_NONBLOCK);
         }
         else printf("[Tuberia1]: %s\n", buffer);
      }

      if(FD_ISSET(fd2, &fds)){
         bytes = read(fd2, buffer, 255);
         buffer[bytes] = '\0';
         if (bytes == 0){
            fd2 = open(tuberia2, O_RDONLY | O_NONBLOCK);
         }
         else printf("[Tuberia2]: %s\n", buffer);

      }

   }


   return 0;
}


