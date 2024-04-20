#include <math.h>
#define M_PI (2*acos((double)0))

int i,j,k,m,n,t,besti;
double x[3], y[3], xx, yy, delta, a1, a2, a3, a;

double gcd(double a, double b) {
   if (fabs(b) < 6e-3) return a;
   return gcd(b,fmod(a,b));
}

void bi(double x1, double y1, double x2, double y2,
        double *a, double *b, double *c) {
   *a = 2*(x2-x1);
   *b = 2*(y2-y1);
   *c = x2*x2 + y2*y2 - x1*x1 - y1*y1;
}

int isct(double a, double b, double c, double aa, double bb, double cc,
         double *x, double *y) {
   double det = a*bb - b*aa;
   if (fabs(det) < 1e-10) return 0;
   *x = (-b*cc + c*bb)/det;
   *y = (a*cc - c*aa)/det;
   return 1;
}


int circle(double x1, double y1, double x2, double y2,
           double x3, double y3, double *x, double *y) {
   double a1,b1,c1,a2,b2,c2;
   bi(x1,y1,x2,y2,&a1,&b1,&c1);
   bi(x2,y2,x3,y3,&a2,&b2,&c2);
   return isct(a1,b1,c1,a2,b2,c2,x,y);
}


main(){
   scanf("%d",&t);
   while (t--) {
      for (i=0;i<3;i++) scanf("%lf%lf",&x[i],&y[i]);

      circle(x[0],y[0],x[1],y[1],x[2],y[2],&xx,&yy);

      a1 = atan2(x[0]-xx,y[0]-yy);
      a2 = atan2(x[1]-xx,y[1]-yy);
      a3 = atan2(x[2]-xx,y[2]-yy);
      a = gcd(fabs(a1-a2),M_PI*2);
      a = gcd(a,fabs(a2-a3));
      printf("%0.0lf\n",M_PI*2/a);
   }
}
