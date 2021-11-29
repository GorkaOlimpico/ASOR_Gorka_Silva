include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>


int main(int argc, char **argv) {

   int p_h[2];
   int h_p[2];

   int p1 = pipe(p_h);
   int p2 = pipe(h_p);

   pid_t pid = fork();

   switch(pid){
      case -1:
         perror("Error en fork\n");
         return -1;
         break;

      case 0:
         close(p_h[1]);
         close(h_p[0]);
         int i;
         char *f = malloc(sizeof(char)*1);
         char *mensaje_recibido = malloc(sizeof(char)*255);

         for(i = 0; i < 9; i++){
            ssize_t bytes = read(p_h[0], mensaje_recibido, 255);
            mensaje_recibido[bytes] = '\0';
            printf("El hijo ha recibido el mensaje: %s\n", mensaje_recibido);
            sleep(1);
            f[0] = 'l';
            write(h_p[1], f, 1);
         }
         ssize_t bytes = read(p_h[0], mensaje_recibido, 255);
         mensaje_recibido[bytes] = '\0';
         printf("El hijo ha recibido el ultimo mensaje: %s\n", mensaje_recibido$
         sleep(1);
         f[0] = 'q';
         write(h_p[1], f, 1);
         break;

       default:
         close(p_h[0]);
         close(h_p[1]);
         char *flag = malloc(sizeof(char)*1);
         flag[0] = 'l';
         while (flag[0] != 'q'){
            printf("Introduce el mensaje del padre: \n");
            char *mensaje = malloc(sizeof(char)*255);
            ssize_t bytes = read(1, mensaje, 255);
            mensaje[bytes] = '\0';
            write(p_h[1], mensaje, 255);
            read(h_p[0], &flag, 1);
         }
         wait(NULL);
         break;
   }

   return 0;
}


