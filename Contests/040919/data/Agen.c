#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int i,j,k,m,n;
double a,b,c,r,x,y;

main(){
   for (i=0;i<10;i++) {
      r = random()%1000;
      a = random()%1000000;
      x = r*sin(a);
      y = r*cos(a);
      for (j=0;j<10;j++) {
         b = random()%1000000;
         printf("%0.10lf %0.10lf %0.10lf %0.10lf %0.10lf\n",
              r, x, y, r*cos(b), r*sin(b));
      }
   }
   printf("1000 0 -1000 1000 0\n");
   printf("1000 0 -1000 0 1000\n");
   printf("1000 0 -1000 -1000 0\n");

   printf("1000 0 1000 1000 0\n");
   printf("1000 0 1000 0 -1000\n");
   printf("1000 0 1000 -1000 0\n");

   printf("1000 1000 0 0 1000\n");
   printf("1000 1000 0 0 -1000\n");
   printf("1000 1000 0 -1000 0\n");

   printf("1000 -1000 0 0 1000\n");
   printf("1000 -1000 0 0 -1000\n");
   printf("1000 -1000 0 1000 0\n");


   printf("-1\n");
}
