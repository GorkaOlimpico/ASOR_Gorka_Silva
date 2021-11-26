#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main(int argc, char **argv) {

   int cmdLen = 1;
   int i;
   for (i = 1; i < argc; i++){
      cmdLen += strlen(argv[i]) + 1;
   }
   char *cmd = malloc(sizeof(char)*cmdLen);
   strcpy(cmd, "");

   for (i = 1; i < argc; i++) {
      strcat(cmd, argv[i]);
      strcat(cmd, " ");
  }

   if(system(cmd) == -1){
      perror("Error en system\n");
   }

   printf("El comando termino de ejecutarse\n");
   return 0;
}
