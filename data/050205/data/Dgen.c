#include <stdio.h>
#include <stdlib.h>

int i;
main(){
   printf("100\n");
   for (i=0;i<100;i++){
      printf("%d %d\n",random()%1000,random()%1000);
   }
}
