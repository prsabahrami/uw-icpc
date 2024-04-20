#include <stdio.h>
#include <math.h>

#define SZ 20

int x[SZ], w[SZ], xsum, wsum;
double cg;

main(){
   int i,j,k;
   for (i=0;i<10;i++) {
      printf("100 10 %d\n",SZ);
      xsum = 0;
      wsum = 10;
      for (j=0;j<SZ-1;j++) {
         x[j] = random()%31-15;
         w[j] = random()%21;
         xsum += x[j]*w[j];
         wsum += w[j];
      }
      w[j] = sqrt(fabs(xsum));
      x[j] = -xsum/w[j];
      xsum += w[j]*x[j];
      wsum += w[j];
      //printf("cg %lg\n",(double)xsum/wsum);
      for (j=0;j<SZ;j++) {
         printf("%d %d\n",x[j],w[j]);
      }
   }
   printf("0 0 0\n");
}
