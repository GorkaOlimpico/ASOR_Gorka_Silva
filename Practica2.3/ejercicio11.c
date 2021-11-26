#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>

int main(int argc, char **argv) {

   sigset_t set;
   sigemptyset(&set);
   sigaddset(&set, SIGINT);
   sigaddset(&set, SIGTSTP);

   sigprocmask(SIG_BLOCK, &set, NULL);

   char *sleep_secs = getenv("SLEEP_SECS");
   int s = atoi(sleep_secs);
   printf("El proceso duerme durante %d segundos\n", s);
   sleep(s);

   sigset_t pending;
   sigpending(&pending);

   if(sigismember(&pending, SIGINT)==1){
      printf("Ha recibido la señal SIGINT\n");
      sigdelset(&set, SIGINT);
   }
   else printf("No se ha recibido la señal SIGINT\n");

   if(sigismember(&pending, SIGTSTP) == 1){
      printf("Ha recibido la señal SIGINT\n");
      sigdelset(&set, SIGINT);
   }
   else printf("No se ha recibido la señal SIGINT\n");

   if(sigismember(&pending, SIGTSTP) == 1){
      printf("Ha recibido la señal SIGTSTP\n");
      sigdelset(&set, SIGTSTP);
   }
   else printf("No se ha recibido la señal SIGTSTP\n");

   sigprocmask(SIG_UNBLOCK, &set, NULL);

   return 0;
}
