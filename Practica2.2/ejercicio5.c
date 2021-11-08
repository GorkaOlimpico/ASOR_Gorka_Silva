#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>

int main(){

   if (open("fichero5", O_CREAT | O_TRUNC | O_RDWR, 0645)== -1){
      printf("%s\n", strerror(errno));
   }

   return 0;
}
