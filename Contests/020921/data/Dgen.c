#include <stdio.h>
#include <stdlib.h>

main(){
   int i,j,k;
   printf("128\n");
   for (i=1;i<=10;i++) {
      printf("%d\n",i*i*i);
      if (i != 10) printf("%d\n",i*i*i+1);
      if (i != 1) printf("%d\n",i*i*i-1);
   }
   for (i=0;i<100;i++) {
      printf("%d\n",random()%999+1);
   }
}
