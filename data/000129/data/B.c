#include <stdio.h>
#include <math.h>

double lat[1000], lng[1000], x[1000], y[1000], z[1000];
double d, bestcos = -1, mincos;
int n, besti;

main(){
   int i,j,k;
   scanf("%d",&n);
   for (i=0;i<n;i++) {
      scanf("%lf%lf",&lat[i],&lng[i]);
      z[i] = sin(lat[i]*M_PI/180);
      x[i] = cos(lng[i]*M_PI/180) * cos(lat[i]*M_PI/180);
      y[i] = sin(lng[i]*M_PI/180) * cos(lat[i]*M_PI/180);
   }
   for (i=0;i<n;i++){
      mincos = 1;
      for (j=0;j<n;j++){
         d = x[i]*x[j] + y[i]*y[j] + z[i]*z[j];
         if (d < mincos) mincos = d;
      }
      if (mincos > bestcos) {
         bestcos = mincos;
         besti = i;
      }
   }
   printf("%0.2lf %0.2lf\n",lat[besti],lng[besti]);
} 
      
