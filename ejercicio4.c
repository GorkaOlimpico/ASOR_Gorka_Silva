#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/utsname.h>
#include <sys/types.h>

int main(){

   struct utsname info;

   if (uname (&info) == -1){
      printf("ERROR(%d): %s\n", errno, strerror(errno));
      return -1;
   }


   else {
    printf("Sysname: %s\n", info.sysname);
    printf("Nodename: %s\n", info.nodename);
    printf("Release: %s\n", info.release);
    printf("Version: %s\n", info.version);
    printf("Machine: %s\n", info.machine);
  }

  return 0;
}
