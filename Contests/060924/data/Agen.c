#include <stdio.h>
#include <stdlib.h>

int i;
main(){
   printf("10000\n");
   for (i=0;i<10000;i++) {
      printf("%d\n",1+random()%10);
   }
   printf("10000\n");
   for (i=0;i<10000;i++) {
      printf("%d\n",1+random()%1000);
   }
   printf("10000\n");
   for (i=0;i<10000;i++) {
      printf("%d\n",1+random()%10000);
   }
   printf("10000\n");
   for (i=0;i<10000;i++) {
      printf("%d\n",i+1);
   }
   printf("10000\n");
   for (i=0;i<10000;i++){
      printf("7\n");
   }
   printf("0\n");
}
