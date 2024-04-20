#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

char foo[300][300][300];
char class[1000];

int i,j,k,m,n,x[300],y[300],z[300],empire;
double a,b,c,d;
main(){
   FILE *f = fopen("Eanswer","w");
   for (i=0;i<30;i++) {
      memset(foo,0,sizeof(foo));
      empire=0;
      if (i < 10) n = i+1;
      else n = 200;
      a = random()%201-100;
      b = random()%201-100;
      c = random()%201-100;
      d = random()%201-100;
      fprintf(f,"%0.6lf %0.6lf %0.6lf %0.6lf\n",a,b,c,d);
      //printf("%d\n",n);
      for (j=0;j<n;j++) {
         do {
            x[j] = random()%201-100;
            y[j] = random()%201-100;
            z[j] = random()%201-100;
         } while (foo[x[j]+100][y[j]+100][z[j]+100]++);
         if (a*x[j] + b*y[j] + c*z[j] + d > 0) empire++;
      }
      empire = random()%n;
      printf("%d\n",n-empire);
      for (j=0;j<n-empire;j++) {
         printf("%d %d %d\n",x[j],y[j],z[j]);
      }
      printf("%d\n",empire);
      for (j=0;j<empire;j++) {
         printf("%d %d %d\n",x[j],y[j],z[j]);
      }
   }
   printf("-1 -1\n");
}
