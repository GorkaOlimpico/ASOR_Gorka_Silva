#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <sys/resource.h>


int main() {

   int pid = getpid();
   int pid_padre = getppid();
   int id_grupo = getgid();
   int id_sesion = getsid(pid);

   printf("ID proceso: %i\n", pid);
   printf("ID padre: %i\n", pid_padre);
   printf("ID grupo: %i\n", id_grupo);
   printf("ID sesion: %i\n", id_sesion);

   struct rlimit limit;

   if(getrlimit(RLIMIT_NOFILE, &limit) == -1){
      perror("Error con el limite de ficheros");
      return -1;
   }

   printf("Limite de ficheros: %i\n", limit.rlim_max);
 
   char *path = malloc(sizeof(char)*(4096+1));
   getcwd(path, 4096 + 1);
   printf("Directorio: %s\n", path);
   free(path);


   return 0;
}





