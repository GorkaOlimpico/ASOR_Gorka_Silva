#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv){

   struct stat info;

   if(stat(argv[1], &info) == -1){
      printf("Error: No existe el fichero.\n");
   }

   if(S_ISREG(info.st_mode)){
       char *dir_sym = malloc(sizeof(char)*(5+ strlen(argv[1])));
       char *dir_hard = malloc(sizeof(char)*(5+ strlen(argv[1])));
       strcpy(dir_sym, argv[1]);
       dir_sym = strcat(dir_sym, ".sym");

       strcpy(dir_hard, argv[1]);
       dir_hard = strcat(dir_hard, ".hard");

       symlink(argv[1], dir_sym);
       link(argv[1], dir_hard);
   }
   else{
       printf("Error: el archivo no es un fichero ordinario");
   }
   return 0;
}


