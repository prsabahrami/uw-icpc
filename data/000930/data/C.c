#include <stdio.h>
#include <stdlib.h>

char in[5000];
int i,j,k,n,next,prev,jolly;

main(){
   while (1 == scanf("%d",&n)){
      jolly = 1;
      for (i=1;i<n;i++) in[i] = 0;
      scanf("%d",&prev);
      for (i=1;i<n;i++) {
         scanf("%d",&next);
         j = abs(next-prev);
         if (j < 1 || j >= n || in[j]++) jolly = 0;
         prev = next;
      }
      if (jolly) printf("Jolly\n");else printf("Not jolly\n");
   }
}
