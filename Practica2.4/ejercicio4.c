#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {

   char *tuberia = "tuberia";

   mkfifo(tuberia, 0777);
   int fd = open(tuberia, O_WRONLY);

   write(fd, argv[1], strlen(argv[1]));
   close(fd);

   return 0;
}
