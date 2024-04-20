#include <stdio.h>
#include <stdlib.h>

int i,j,k,c,d;

main(){
   printf("1\n20\n");
   for (i=0;i<20;i++) {
      c = 'A' + random()%26;
      printf("20 %2d:%02d %c",random()%24, random()%60, c);
      for (j=0;j<19;j++) {
         d = 'A' + random()%25;
         if (d >= c) d += 1;
         c = d;
         printf(" %d:%02d %c",random()%6,random()%60, d);
      }
      printf("\n");
   }
   printf("A B\n");
}
