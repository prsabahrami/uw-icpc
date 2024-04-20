#include <stdio.h>

int i,j,k,C,N,m[1000];
double sum,avg,cnt;

main(){
   scanf("%d",&C);
   while (C--) {
      scanf("%d",&N);
      sum = 0;
      for (i=0;i<N;i++) {
         scanf("%d",&m[i]);
         sum += m[i];
      }
      avg = sum/N;
      cnt = 0;
      for (i=0;i<N;i++) if (m[i]>avg) cnt++;
      printf("%0.3lf%%\n",100*cnt/N);
   }
}
