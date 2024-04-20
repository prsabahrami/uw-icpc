#include <stdio.h>
#include <math.h>

double xx, yy, x[3], y[3], r[3], delta;
int m,i,j,k;

double foo(double a, double b){
   int i,j,k;
   double d[3], dd=0, ddd=0;
   for (i=0;i<3;i++){
      d[i] = hypot(x[i]-a,y[i]-b)/r[i];
      dd += d[i];
   }
   dd /=3;
   for (i=0;i<3;i++){
      ddd += fabs(dd-d[i]);
   }
   return ddd;
}

main(){
   for (;;){
      for (i=0;i<3;i++) scanf("%lf%lf%lf",&x[i],&y[i],&r[i]);
      for (i=0;i<3 && !(x[i]||y[i]||r[i]);i++);
      if (i==3) break;
      xx = yy = 0;
      for (i=0;i<3;i++) {
        xx += x[i];
        yy += y[i];
      }
      xx/=3; yy/=3;
      delta = 1e99;
      xx=30; yy=10;
      for (i=0;i<3;i++) {
         if (hypot(xx-x[i],yy-y[i]) < delta) delta = hypot(xx-x[i],yy-y[i]);
      }
      delta /= 100;
      for (m=0;m<30;m++) {
         for (i=1;i;) {
            i = 0;
            for (j=-1;j<=1;j++) for (k=-1;k<=1;k++) {
               if (foo(xx+j*delta,yy+k*delta) < foo(xx,yy)) {
                  xx += j*delta; yy += k*delta;
                  i=1;
               }
            }
         }
         delta /=2;
      }
      if (foo(xx,yy) > .001) printf("No solution\n");
      else printf("%0.2lf %0.2lf\n",xx,yy);
   }
}
