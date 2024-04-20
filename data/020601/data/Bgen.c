#include <stdio.h>

int i,j,k;

main(){
   printf("14 %d\n",14*13/2);
   for (i=1;i<14;i++) {
      printf("%d %d 1\n",i,i+1);
      for (j=i+2;j<=14;j++) printf("%d %d 2\n",i,j);
   }
   printf("0\n");
}
