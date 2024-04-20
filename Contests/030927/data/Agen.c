#include <stdio.h>
#include <stdlib.h>

int i,j,k,n;

main(){
   for (i=0;i<100;i++) {
      k = random()%100;
      while (k--) {
         n = 100;
         for (j=0;j<5;j++) {
            switch (random()%3) {
            case 0: printf("%dg",random()%1000); break;
            case 1: printf("%dC",random()%1000); break;
            case 2: 
               {
                  int z = random()%n;
                  n -= z;
                  printf("%d%%",z); break;
               }
            }
            if (j == 4) printf("\n"); else printf(" ");
         }
      }
      printf("-\n");
   }
   printf("-\n");
}
