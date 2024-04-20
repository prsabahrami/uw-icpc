#include <stdio.h>
#include <string.h>

char buf[2000];

int c,i,j,n,swaps,extra;

main(){
   scanf("%d",&c);
   while (c--) {
      scanf("%s",buf);
      n = strlen(buf);
      swaps = 0;
      extra = 0;
      for (i=0;i<n/2;i++) {
         for (j=n-i-!extra;j>i && buf[i] != buf[j];j--) {}
         if (j == i) {
            if (extra || n%2 == 0) {
               printf("Impossible\n");
               goto dun;
            }
            extra = n/2 - i;
            continue;
         }
         for (; j < n-i-!extra ; j++) {
            int t = buf[j];
            buf[j] = buf[j+1];
            buf[j+1] = t;
            swaps++;
         }
      }
      printf("%d\n",swaps+extra);
   dun:;}
   if (1 == scanf("%s",buf)) printf("extra input!!!\n");
}
