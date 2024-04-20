#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pp[401][401];
#define p(x,y) pp[(x)+200][(y)+200]

int x[10],y[10];

int a,b,c,d,e,f,g,h,i,j,k,m,n;

main(){
   for (i=0;i<50;i++) {
      n = random()%8+3;
      memset(pp,0,sizeof(pp));
      for (j=0;j<n;j++) {
         do{
           a = random()%41-20;
           b = random()%41-20;
         } while (p(a,b)++);
         x[j] = a; y[j] = b;
      }
      a = 1+random()%20;
      b = 1+random()%20;
      c = 1+random()%20;
      d = 1+random()%20;
      e = random()%1001-500;
      f = random()%1001-500;
      g = random()%1001-500;
      h = random()%1001-500;
      printf("%d\n",n);
      for (j=0;j<n;j++) printf("%d %d%c",e+a*x[j]+b*y[j],f+-b*x[j]+a*y[j],j==n-1?'\n':' ');
      for (j=0;j<n;j++) printf("%d %d%c",g+c*x[j]+d*y[j],h+-d*x[j]+c*y[j],j==n-1?'\n':' ');
      if  (i < 10) {
         printf("%d\n",n);
         for (j=0;j<n;j++) printf("%d %d%c",e+a*x[j]+b*y[j],f+-b*x[j]+a*y[j],j==n-1?'\n':' ');
         for (j=0;j<n;j++) printf("%d %d%c",g+c*x[j]+d*y[j],h+d*x[j]-c*y[j],j==n-1?'\n':' ');
      }
      if (i >= 10 && i <= 20) {
         k = random()%n;
         printf("%d\n",n);
         for (j=0;j<n;j++) printf("%d %d%c",(j==k)+e+a*x[j]+b*y[j],f+-b*x[j]+a*y[j],j==n-1?'\n':' ');
         for (j=0;j<n;j++) printf("%d %d%c",g+c*x[j]+d*y[j],h-d*x[j]+c*y[j],j==n-1?'\n':' ');
      }
   }
}
