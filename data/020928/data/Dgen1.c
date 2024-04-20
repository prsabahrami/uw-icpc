#include <stdio.h>
#include <stdlib.h>

main(){
   int i,j,k,n;
   printf("1000");
   for (i=0;i<1000;i++) printf(" %d",i != 333);
   printf("\n");
   printf("1000");
   for (i=0;i<1000;i++) printf(" %d",i == 333);
   printf("\n");
}
