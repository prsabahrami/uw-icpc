#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int i,j,k,m,f,r,front[100],rear[100];
double rat[10000];

comp(double *a, double *b){
   if (*a > *b) return 1;
   if (*a < *b) return -1;
   return 0;
}

main(){
   while (2 == scanf("%d%d",&f,&r) && f){
      double best=1;
      k = 0;
      for (i=0;i<f;i++) scanf("%d",&front[i]);
      for (i=0;i<r;i++) scanf("%d",&rear[i]);
      for (i=0;i<f;i++) for (j=0;j<r;j++) {
         rat[k++] = (double)rear[j]/front[i];
      }
      qsort(rat,k,sizeof(double),comp);
      //for (i=0;i<k;i++) printf("%0.4lf\n",rat[i]);
      for (i=0;i+1<k;i++) {
         if (rat[i+1]/rat[i] > best) best = rat[i+1]/rat[i];
      }
      printf("%0.22lf\n",best);
   }
   assert (f == 0);
}
