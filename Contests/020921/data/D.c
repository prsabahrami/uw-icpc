#include <stdio.h>

int C,N,i,j,k,area,best;

main(){
   scanf("%d",&C);
   while (C--) {
      scanf("%d",&N);
      best = 1000*1000*1000;
      for (i=1;i*i*i<=N;i++) {
         for (j=i;i*j*j<=N;j++) {
            if (N%(i*j)) continue;
            k = N/(i*j);
            area = 2*i*j + 2*i*k + 2*j*k;
            if (area < best) best = area;
         }
      }
      printf("%d\n",best);
   }
}
