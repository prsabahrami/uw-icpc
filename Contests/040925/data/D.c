#include <stdio.h>

int x[10000], y[10000];
int i,j,k,n;

main(){
   while (1 == scanf("%d: ",&n) && n) {
      for (i=0;i<n;i++) {
         scanf("%d",&x[i]);
         y[x[i]] = i;
      }
      for (i=0;i<n;i++) {
         for (j=i+1;j<n;j++) {
            k = x[j]+x[j]-x[i];
            if (k < 0 || k >= n) continue;
            if (y[k] > j) {
               printf("no\n");
               goto dun;
            }
         }
      }
      printf("yes\n");dun:;
   }
   if (n) printf("missing end delim\n");
}
