#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>

int main(){

   mode_t prev = umask(0027);

   if (open("fichero7", O_CREAT | O_TRUNC | O_RDWR, 0645)== -1){
      printf("%s\n", strerror(errno));
   }

   return 0;
}
