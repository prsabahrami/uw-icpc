#include <stdio.h>
#include <stdlib.h>

int i,j,k;
int n,m;
main(){
   for (i=0;i<3;i++) {
      n = 10000; m = n+1000+i*1000;
      printf("%d %d\n",n,m);
      for (j=0;j<n;j++) {
         printf("%d\n",random()%10000);
      }
      for (j=0;j<m;j++) {
         printf("%d\n",random()%10000);
      }
   }
   printf("0 0\n");
}
