#include <stdio.h>
#include <stdlib.h>

int i,j,b,n;

main(){
   for (j=0;j<1000;j++) {
      b = random()%9+2;
      printf("%d ",b);
      printf("%d",random()%(b-1)+1);
      n = random()%1000;
      for (i=0;i<n;i++) printf("%d",random()%b);
      printf(" %d",random()%(b-1)+1);
      n = random()%8;
      for (i=0;i<n;i++) printf("%d",random()%b);
      printf("\n");
   }
   printf("0\n");
}
