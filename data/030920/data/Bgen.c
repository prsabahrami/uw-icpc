#include <stdio.h>
#include <stdlib.h>

main(){
   int i;
   for (i=0;i<1000;i++){
      int a = random()%40;
      int b = random()%40;
      int c = random()%40;
      int d = random()%40;
      if (!(a||b||c||d)) continue;
      if (a==b || b==c || c==d) continue;
      printf("%d %d %d %d\n",a,b,c,d);
   }
   printf("0 0 0 0\n");
}
