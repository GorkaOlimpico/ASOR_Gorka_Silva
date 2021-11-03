#include <errno.h>
#include <stdio.h>
#include <string.h>


int main() {
   char *error;
  
   if(setuid(0)== -1){
      error = strerror(errno);
   }
   return 1;
}
