#include <stdio.h>
#include <stdlib.h>

int i,j,k,lhs,rhs,var,coef;

main(){
   printf("50\n");
   for (i=0;i<100;i++) {
      if (i && i%2==0) printf("\n");
      lhs = 1+random()%5;
      rhs = 1+random()%5;
      for (j=0;j<lhs+rhs;j++) {
         if (j) {
            if (j == lhs) printf(" = ");
            else if (random()%2) printf(" + ");
            else printf(" - ");
         }
         coef = random()%200-100;
         var = (coef != 0) * random()%3;
         if (var && coef == -1) printf("-");
         else if (var && coef == 1) printf("");
         else printf("%d",coef);
         if (var) printf("%c"," xy"[var]);
      }
      printf("\n");
   }
}
