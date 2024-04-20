#include <stdio.h>
#include <stdlib.h>

int i,j,k;

main(){
   printf("50\n");
   for (i=0;i<50;i++) {
      printf("%d,%d%c %d,%d%c %d,%d%c %d,%d%c\n",
        random()%89+1, random()%60, "NS"[random()%2], 
        random()%179+1, random()%60, "EW"[random()%2], 
        random()%89+1, random()%60, "NS"[random()%2], 
        random()%179+1, random()%60, "EW"[random()%2]);
   }
}
