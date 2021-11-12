#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv){

   DIR *mi_dir = opendir(argv[1]);
   if(mi_dir == NULL){
      printf("Error: No existe el directorio.\n");
      return -1;
   }

   struct dirent *mi_read = readdir(mi_dir);
   
   struct stat info;
   int totalsize = 0;

   while(mi_read != NULL){
      char *path = malloc(sizeof(char)*(strlen(argv[1]) + strlen(mi_read->d_nam$
      strcpy(path, argv[1]);
      strcat(path, "/");
      strcat(path, mi_read->d_name);

      if(stat(path, &info) == -1){
         printf("Error al leer el archivo\n");
      }
      else{
         if (S_ISDIR(info.st_mode)){
            printf("/ %s \n", mi_read->d_name);
         }
         else if (S_ISLNK(info.st_mode)){
            char *linkname = malloc(info.st_size + 1);
            readlink(path, linkname, info.st_size + 1);
            printf("%s -> %s \n", mi_read->d_name, linkname);
            free(linkname);
         }
         else if(S_ISREG(info.st_mode)){
            printf("* %s\n", mi_read->d_name);
            totalsize = totalsize + ((info.st_blksize/8)*info.st_blocks);
         }

      }

      free(path);
      mi_read = readdir(mi_dir);
   }
   
   printf("Tamaño de los archivos: %d KB\n", totalsize);
   return 0;
}



