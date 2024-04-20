#include <stdio.h>
#include <math.h>

char reach[1<<24];

double w[24], x[24], len, wt, sumw, sumx, cg;
int n;

int solve(int m, double sx, double sw) {
   int i;
   double sumt1, sumt2;
   if (reach[m]) return 0;
   reach[m] = 1;
   cg = sx / sw;
   if (cg < -1.5 || cg > 1.5) return 0;
   if (m == (1<<n)-1) return 1;
   for (i=0;i<n;i++) {
      if (!(m & (1<<i)) && solve(m|(1<<i),sx+x[i]*w[i],sw+w[i])) {
         printf("%lg %lg\n",x[i],w[i]);
         return 1;
      }
   }
   return 0;
}

main(){
   int cc,i;
   for (cc=1; 3 == scanf("%lf%lf%d",&len,&wt,&n) && n; cc++) {
      memset(reach,0,1<<n);
      for (i=0;i<n;i++) scanf("%lf%lf",&x[i],&w[i]);
      printf("Case %d:\n",cc);
      if (!solve(0,0,wt)) printf("Impossible\n");
   }
}
