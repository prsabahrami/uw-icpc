#include <stdio.h>
#include <math.h>

int p,i,j,k,n,maxi,mini,maxj,minj;
double max,min,r;

main(){
   while(1){
      scanf("%d%d",&p,&n);
      if (!p) break;
      max = -1e99;
      min = 1e99;
      for (i=1;i<=n;i++) for(j=i/sqrt((double)p);j<=1+i/sqrt((double)p);j++){
         if (j < 1 || j > n) continue;
         r = (double)i/j;
         if (r*r < p && r > max) {
            max = r;
            maxi = i;
            maxj = j;
         }
         if (r*r > p && r < min){
            min = r;
            mini = i;
            minj = j;
         }
      }
      printf("%d/%d %d/%d\n",mini,minj,maxi,maxj);
   }
}
