#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int i,j,xo, yo, x,y;
main(){
   printf("30\n");
   for (j=0;j<30;j++) {
      printf("30\n");
      for (i=0;i<30;i++) {
         xo = random()%20-10;
         yo = random()%20-10;
         x = random()%301-150;
         y = sqrt(301*301-(double)x*x);
         y += random()%3-1;
         x += xo;
         y += yo;
         assert(x*x + y*y < 500*500);
         printf("%d %d\n",x,y);
      }
   }
}
