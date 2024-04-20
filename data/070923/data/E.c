#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int r,e,i,k,j,n,dun;
int x[300], y[300], z[300];
double a,b,c,d,w;

main(){
   while (1 == scanf("%d",&r) && r >= 0) {
      for (i=0;i<r;i++) scanf("%d%d%d",&x[i],&y[i],&z[i]);
      scanf("%d",&e);
      n = r + e;
      for (i=r;i<n;i++) scanf("%d%d%d",&x[i],&y[i],&z[i]);
      dun = 0;
      for (k=0;k<100000 && !dun;k++) {
         dun=1;
         for (i=0;i<r;i++) {
            if (a*x[i]+b*y[i]+c*z[i]+d > 0) {
               a -= x[i];
               b -= y[i];
               c -= z[i];
               d -= 1;
               dun = 0;
            }
         }
         for (i=r;i<n;i++) {
            if (a*x[i]+b*y[i]+c*z[i]+d <= 0) {
               a += x[i];
               b += y[i];
               c += z[i];
               d += 1;
               dun = 0;
            }
         }
      }
      if (dun) printf("%lg %lg %lg %lg\n",a,b,c,d);
      else printf("no solution\n");
   }
   assert (r == -1);
   assert (1 == scanf("%d",&r) && r == -1);
   assert (1 != scanf(" %c",&c));
}
