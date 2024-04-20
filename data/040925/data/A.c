#include <stdio.h>
#include <math.h>

int n[100], w[100], i,j,k,m,t;

double a,b,delta,p,q;

double like(double a, double b){
   int i,j,k;
   double r = 1;
   for (i=0;i<t;i++) {
      double odds = exp(a + b * n[i]);
      double p = odds / (1 + odds);
      if (w[i]) r *= p; else r *= (1-p);
   }
   //printf("like %lg %lg: %lg\n",a,b,r);
   return r;
}

double alike(double a){
   double p,q,delta;
   b = p = 0;
   for (delta=1;delta > 1e-9;) {
      if ((q=like(a,b+delta)) > p) {
         b += delta;
         p = q;
      } else if ((q = like(a,b-delta)) > p) {
         b -= delta;
         p = q;
      } else delta *= .5;
   }
   return p;
}

main(){
   while (1 == scanf("%d",&t) && t) {
      for (i=0;i<t;i++) scanf("%d%d",&n[i],&w[i]);
      a = p = 0;
      for (delta = 1;delta > 1e-9;) {
         if ((q=alike(a+delta)) > p) {
            a += delta;
            p = q;
         } else if ((q = alike(a-delta)) > p) {
            a -= delta;
            p = q;
         } else delta *= .5;
      }
      printf("%0.4lf %0.4lf\n",a,b);
   }
   if (t) printf("missing end delimiter\n");
}
