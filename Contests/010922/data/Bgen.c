#include <stdio.h>

main(){
   int i,j,k,m,stops=200;

   printf("1 1 10001 10001\n");

   while (stops > 1) {
      m = 2;
      stops -= m;
      for (i=0;i<m;i++) {
         j = random()%10000;
         k = j + random() % 4000 - 2000;
         printf("%d %d ",j,k);
      }
      printf("-1 -1\n");
   }
}
