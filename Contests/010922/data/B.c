#include <stdio.h>
#include <math.h>

double z, x[203], y[203], d[202][202];
int i,j,k,n;

main(){
   for (i=0;i<202;i++) for (j=0;j<202;j++) d[i][j] = 1e99;
   n=2;
   scanf("%lf%lf",&x[0],&y[0]);
   scanf("%lf%lf",&x[1],&y[1]);

   while(1){
      if (2 != scanf("%lf%lf",&x[n],&y[n])) break;
      n++;
      while(1) {
         scanf("%lf%lf",&x[n],&y[n]);
         if (x[n] < 0) break;
         z = hypot(x[n]-x[n-1],y[n]-y[n-1]);
         if (z < d[n-1][n]) d[n-1][n] = d[n][n-1] = z;
         n++;
      }
   }
   for (i=0;i<n;i++) for (j=0;j<n;j++) {
      if (d[i][j] > 1e98) d[i][j] = 4*hypot(x[i]-x[j], y[i]-y[j]);
   }
   for (i=0;i<n;i++) for (j=0;j<n;j++) for (k=0;k<n;k++) {
      if (d[j][i]+d[i][k] < d[j][k]) d[j][k] = d[j][i]+d[i][k];
   }
   printf("%0.0lf\n",d[0][1]/40000*60);
}
