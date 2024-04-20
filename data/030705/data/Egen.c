#include <stdio.h>
#include <stdlib.h>

int p,i,j,k,stan,n;

main(){
   for (p=0;p<200;p++){
      stan = random()%10+1;
      n = random()%20+1;
      for (i=1;i<n;i++) {
         if (random()%30 == 1) stan = random()%10+1;
         k = random()%10+1;
         printf("%d\n",k);
         if (k < stan) printf("too low\n");
         else if (k > stan) printf("too high\n");
         else if (random()%2) printf("too low\n");
         else printf("too high\n");
      }
      printf("%d\nright on\n",stan);
   }
   printf("0\n");
}
