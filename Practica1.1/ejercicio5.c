
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/utsname.h>


int main(){

   struct utsname buf;

   if(uname(&buf) == -1){
      printf("Error: %s",  strerror(errno));
      return -1;
   }
   else{
      printf("Sysname: %s\n", buf.sysname);
      printf("Nodename: %s\n", buf.nodename);
      printf("Release: %s\n", buf.release);
      printf("Version: %s\n", buf.version);
      printf("Machine: %s\n", buf.machine);
   }
   return 0;
}


