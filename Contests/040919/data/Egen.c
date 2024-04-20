#include <stdio.h>
#include <stdlib.h>

int i,j;

main(){
   for (i=4;i<=100;i+=24) {
      printf("%d %d\n",i,10-i/11);
      for (j=0;j<i;j++) printf("%d\n",random()%200+1);
      for (j=0;j<10-i/11;j++) printf("%d\n",random()%1200+1);
   }
   printf("0 0\n");
}
