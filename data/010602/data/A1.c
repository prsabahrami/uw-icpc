#include <stdio.h>
#include <math.h>

char reach[1<<24];

double w[24], x[24], len, wt;
int n, nans, ans[24];

int solve(int m) {
   int i;
   double sumt1, sumt2;
   if (reach[m]) return 0;
   reach[m] = 1;
   sumt1 = 1.5 * wt;
   sumt2 = -1.5 * wt;
   for (i=0;i<n;i++) {
      if (m & (1<<i)) {
         sumt1 += w[i] * (x[i]+1.5);
         sumt2 += w[i] * (x[i]-1.5); 
      }
   }
   if (sumt1 < 0 || sumt2 > 0) return 0;
   if (m == 0) return 1;
   for (i=0;i<n;i++) {
      if ((m & (1<<i)) && solve(m-(1<<i))) {
         ans[nans++] = i;
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
      nans = 0;
      if (!solve((1<<n)-1)) printf("Impossible\n");
      else for (i=n-1;i>=0;i--) printf("%lg %lg\n",x[ans[i]],w[ans[i]]);
   }
}
