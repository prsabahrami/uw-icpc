#include <stdio.h>
#include <math.h>

int n, m, i, j, k, c, cases, x[1000000], y[1000000], l[1000000], r[1000000], 
                    d[1000000];
int hi, lo, mid, cookie;

int test(int dd) {
   int i, rr=0;
   ++cookie;
   for (i=j=0;i<n;i++) {
      if (d[l[i]] == cookie) continue;
      rr++;
      int xx = x[l[i]]+y[l[i]]+dd;
//printf("i %d l[i] %d xx %d\n",i,l[i],xx);
      for (;j<n && x[r[j]]-y[r[j]] <= xx;j++) {
         d[r[j]] = cookie;
      }
      if (j >= n) break;
   }
//printf("test %d return %d\n",dd,rr);
   return rr;
}

int compl(int *a, int *b){
   return (x[*a]+y[*a]) - (x[*b]+y[*b]);
}

int compr(int *a, int *b){
   return (x[*a]-y[*a]) - (x[*b]-y[*b]);
}

main(){
   scanf("%d",&cases);
   for (c=1; c <= cases; c++) {
      int miny = 2000000;
      scanf("%d%d",&n,&m);  
      for (i=0;i<n;i++) {
         scanf("%d%d",&y[i],&x[i]);
         l[i] = r[i] = i;
         if (y[i] < miny) miny = y[i];
      }
//printf("sorting\n");
      qsort(l,n,sizeof(int),compl);
//printf("done sort 1\n");
      qsort(r,n,sizeof(int),compr);
//printf("done sort 2\n");

for (i=0;i<n;i++) {
   //printf("lefti %d %d: %d,%d: %d\n", i, l[i], x[l[i]], y[l[i]], x[l[i]]+y[l[i]]);
}
for (i=0;i<n;i++) {
   //printf("riti %d %d: %d,%d: %d\n", i, r[i], x[r[i]], y[r[i]], x[r[i]]-y[r[i]]);
}
      lo = -miny*2+1;
      hi = 4000000;
      while (hi >= lo) {
         mid = (hi+lo)/2;
         if (test(mid) > m) lo = mid+1;
         else hi = mid-1;
      }
      if (test(hi) <= m) lo = hi;
      printf("Case %d: %0.0lf\n",c,floor(lo/-2.0+.00000001));
   }
}
