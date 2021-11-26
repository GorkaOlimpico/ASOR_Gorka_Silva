#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>

volatile int int_c = 0;
volatile int tstp_c = 0;

void handler(int senial){
   if(senial == SIGINT) int_c++;
   if(senial == SIGTSTP) tstp_c++;
}


int main(int argc, char **argv) {

   struct sigaction act;

   sigaction(SIGINT, NULL, &act);
   act.sa_handler = handler;
   sigaction(SIGINT, &act, NULL);

   sigaction(SIGTSTP, NULL, &act);
   act.sa_handler = handler;
   sigaction(SIGTSTP, &act, NULL);

   sigset_t set;
   sigemptyset(&set);

   while((int_c + tstp_c) < 10){
      sigsuspend(&set);
   }

   printf("Señales SIGINT: %i\n", int_c);
   printf("Señales SIGTSTP: %i\n", tstp_c);

   return 0;
}

