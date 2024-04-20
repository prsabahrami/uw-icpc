/*

  NOTE:  These results for these cases have ben verified using SPSS

   -1.4978 0.0075
   -2.5156 0.0262
   1.7702 -0.0308

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int i;
gen(int n, double a, double b){
   printf("%d\n",n);
   for (i=0;i<100;i++) {
      int n = random()%100;
      double logit = a + b * n;
      double p = exp(logit)/(1+exp(logit)); 
      int m = random()%10000;
      printf("%d %d\n",n,m < 10000*p);
   }
}

main(){
   gen(100,-2,.01);
   gen(100,-2,.02);
   gen(100,2,-.03);
   printf("0\n");
}
