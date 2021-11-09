#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <time.h>


int main(int argc, char **argv){

   struct stat info;

   if(stat(argv[1], &info) == -1){
      printf("Error: No existe el directorio.\n");
   }

   printf("Major: %i\n", major(info.st_dev));
   printf("Minor: %i\n", minor(info.st_dev));
   printf("I-Node: %li\n", info.st_ino);
   
   if(S_ISLNK(info.st_mode)){
       printf("Modo: enlace simbólico\n");
   }
   else if(S_ISREG(info.st_mode)){
       printf("Modo: fichero ordinario\n");
   }
   else if(S_ISDIR(info.st_mode)){
       printf("Modo: directorio\n");
   }

   time_t a_time = info.st_atime;
   time_t m_time = info.st_mtime;
   time_t c_time = info.st_ctime;

   struct tm *tm2 = localtime(&m_time);
   printf("Fecha de último acceso: %d/%d/%d, %d:%d\n", tm2->tm_mday, tm2->tm_mo$

   return 0;
 }
