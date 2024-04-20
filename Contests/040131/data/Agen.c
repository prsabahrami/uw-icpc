#include <stdio.h>
#include <stdlib.h>

int i,j,k,m,n;

main(){
   for (i=0;i<100;i++) {
      j = 1+random()%70;
      for (k=0;k<j;k++) {
         printf("%c","LLRRUUDD."[random()%9]);
      }
      printf("\n");
   }
   printf("#\n");
}
