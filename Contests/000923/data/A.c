#include <stdio.h>
#include <math.h>

#define hypot(a,b) sqrt((a)*(a)+(b)*(b))

double x[100], y[100], bestd, totd;
char in[100];
int n,nin,best;

main(){
   int i,j,k;
   scanf("%d",&n);
   for (i=0;i<n;i++) scanf("%lf%lf",&x[i],&y[i]);
   in[0] = 1;
   for (nin=1;nin<n;nin++){
      bestd = 1e100;
      for (i=0;i<n;i++) {
         if (!in[i]) continue;
         for (j=0;j<n;j++) {
            if (i==j || in[j]) continue;
            if (bestd == 1e100 || hypot(x[i]-x[j],y[i]-y[j]) < bestd){
               best = j;
               bestd = hypot(x[i]-x[j],y[i]-y[j]);
            }
         }
      }
      in[best]=1;
      totd += bestd;
   }
   printf("%0.2lf\n",totd);
}
