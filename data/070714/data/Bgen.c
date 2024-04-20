#include <stdio.h>
#include <stdlib.h>

int i,j,k,t,m,e[30000];
main(){
   printf("30\n");
   for (i=1;i<=30;i++) {
      j = i * 1000;
      printf("%d",j);
      for (k=0;k<j;k++) e[k] = k+1;
      for (k=0;k<j;k++) {
         m = random()%j;
         t = e[m];
         e[m] = e[k];
         e[k] = t;
      }
      for (k=0;k<j;k++) printf(" %d",e[k]);
      printf("\n");
   }
}
