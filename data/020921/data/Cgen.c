#include <stdio.h>
#include <stdlib.h>

main(){
   int i,j,k,n=0;
   int sum; int len;
   double size;

   for (size=1300;size < 1600;size *=1.01) {
      n++;
   }
  
   printf("%d\n",n);

   for (size=1300;size < 1600;size *=1.01) {
      len = 20;
      printf("%d",len);
      sum = 0;
      for (i=0;i<len;i++) {
         k = 1 + random()%(int)size;
         sum += k;
         if (i==len-1 && sum%4) k += 4 - sum%4;
         printf(" %d",k);
      }
      printf("\n");
   }
}
