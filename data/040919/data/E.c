#include <stdio.h>

unsigned gcd(unsigned a, unsigned b){
   if (b == 0) return a;
   return gcd(b,a%b);
}

unsigned lo,hi,bestlo, besthi, c[100], i,j,k,m,n,t,L,g;

main(){
   while (2 == scanf("%d%d",&n,&t)) {
      for (i=0;i<n;i++) scanf("%d",&c[i]);
      while (t--) {
         scanf("%d",&L);
         bestlo = 0;
         besthi = 0xffffffff;
         for (i=0;i<n;i++) for (j=i+1;j<n;j++) for (k=j+1;k<n;k++) for (m=k+1;m<n;m++) {
            g = c[i]/gcd(c[i],c[j])*c[j];
            g = g/gcd(g,c[k])*c[k];
            g = g/gcd(g,c[m])*c[m];
            lo = L/g*g;
            if (lo > bestlo) bestlo = lo;
            if (lo != L) lo += g;
            if (lo < besthi) besthi = lo;
         }
         printf("%u %u\n",bestlo,besthi);
      }
   }
}
