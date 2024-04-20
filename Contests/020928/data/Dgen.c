#include <stdio.h>
#include <stdlib.h>

main(){
   int i,j,k,n;
   for (i=0;i<20;i++) {
      n = random()%1000 + 1;
      printf("%d",n);
      for (j=0;j<n;j++) printf(" %d",random()%101);
      printf("\n");
   }
}
