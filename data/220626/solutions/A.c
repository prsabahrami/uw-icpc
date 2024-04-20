#include <math.h>
#include <stdio.h>

int n,k; 
double p,win,thresh;

main(){
   while (2 == scanf("%d%lf",&n,&p)) {
      if (!n) break;
      win = 1<<n;
      for (k=n-1;k>=0;k--) {
         thresh = (1<<k)/win;
         if (p >= thresh) win = (p+1)/2*win;
         else win = (1<<k) * (thresh-p)/(1-p) 
                     + win * (thresh+1)/2 * (1-thresh)/(1-p);
      }
      printf("%0.3lf\n",win);
   }
   if (n || p) printf("extraneous input %d %d\n",n,p);
}
