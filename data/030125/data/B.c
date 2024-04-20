#include <stdio.h>

int f,i,k,m,n,t,c,nf,leave[2000];

main(){
   scanf("%d",&c);
   while (c--) {
      scanf("%d%d%d",&n,&t,&m);
      t *= 2;
      nf = (m+n-1)/n;
      k = m - (nf-1) * n;
      for (i=0;i<k;i++) scanf("%d",&leave[0]);
      for (f=1;f<nf;f++) {
         for (i=0;i<n;i++) scanf("%d",&leave[f]);
      }
      for (f=0;f+1<nf;f++) {
         if (leave[f]+t > leave[f+1]) leave[f+1] = leave[f]+t;
      }
      printf("%d %d\n",leave[nf-1]+t/2,nf);
   }
}
