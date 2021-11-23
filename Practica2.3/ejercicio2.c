#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <sys/types.h>
#include <unistd.h>

int main() {

   int pid = getpid();

   int planificacion = sched_getscheduler(pid);
   if(planificacion == SCHED_OTHER){
      printf("Planificacion: OTHER\n");
   }
   else if (planificacion == SCHED_FIFO){
      printf("Planificacion: FIFO\n");
   }
   else if (planificacion == SCHED_RR){
      printf("Planificacion: RR\n");
   }
   else
      printf("Error\n");

   struct sched_param param;
   sched_getparam(pid,&param);
   printf("Prioridad: %i\n", param.sched_priority);
   
   int max = sched_get_priority_max(planificacion);
   int min = sched_get_priority_min(planificacion);

   printf("Max: %i\nMin: %i\n", max, min);

   return 0;
}



