#include <math.h>
#include <stdio.h>
#define pi (2*acos(0))

double D,V,d,delta;

int i,j,k;

double v(double d){
   double R = D/2;
   double r = d/2;
   double vCyl = D * pi * R * R;
   double vcyl = d * pi * r * r;
   double vCone = pi * (D/2)*(D/2)*(D/2) / 3;
   double vcone = pi * (d/2)*(d/2)*(d/2) / 3;
   double res = vCyl - 2*vCone - vcyl + 2*vcone;
   return res;
}

main(){
   while (2 == scanf("%lf%lf",&D,&V) && D) {
      delta = d = D/2;
      for (d=D/2; delta > .000000001; delta /=2) {
         if (v(d) < V) d -= delta;
         else d += delta;
      }
      printf("%0.3lf\n",d);
   }
}
