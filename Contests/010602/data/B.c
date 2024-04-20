#include <stdio.h>
#include <math.h>

double D,M,A,J,jtime, jtimeaccellimit, jtimespeedlimit, jtimedistlimit,
               atime, dist, delta, a, b, c, r;

double cubrt(double x) {
   return (exp(log(x)/3));
}

main(){
   while (4 == scanf("%lf%lf%lf%lf",&D,&M,&A,&J)) {
      jtimeaccellimit = A/J;
      jtimespeedlimit = sqrt(M/J);
      jtimedistlimit = cubrt(D/2/J);
      jtime = jtimeaccellimit;
      if (jtimespeedlimit < jtime) jtime = jtimespeedlimit;
      if (jtimedistlimit < jtime) jtime = jtimedistlimit;
      atime = (M - J*pow(jtime,2))/A;
      a = 0.5*A;
      b = A*jtime + 0.5*J*pow(jtime,2);
      c = J * pow(jtime,3) - D/2;
      r = (-b + sqrt(b*b - 4*a*c))/2/a;
      if (r < atime) atime = r;
      dist = J * pow(jtime,3) 
             + 0.5*J*pow(jtime,2)*atime + 0.5*A * pow(atime,2) 
             + A * atime*jtime;
      printf("%0.1lf\n",4*jtime+2*atime+2*(D/2-dist)/M);
   }
}
