#include <stdio.h>
#include <math.h>

double x[200], y[200];
int n;

double x1,Y1,x2,y2;
main(){
   int i,j,k,m,mm,max = 0;
   for (n=0;2 == scanf("%lf%lf\n",x+n,y+n);n++){}
   if (n > 0) max = 1;
   for (i=0;i<n;i++){
      for (j=i+1;j<n;j++){ 
         if (!centre(x[i],y[i],x[j],y[j])) continue;
         m = mm = 2;
         for (k=0;k<n;k++) {
            if (k==i || k==j) continue;
            if ( (x1-x[k])*(x1-x[k]) + (Y1-y[k])*(Y1-y[k]) <= 2.5l*2.5l) m++;
            if ( (x2-x[k])*(x2-x[k]) + (y2-y[k])*(y2-y[k]) <= 2.5l*2.5l) mm++;
         }
         if (m > max) max = m;
         if (mm > max) max = mm;
      }
   }
   printf("%d\n",max);
}

centre(double a, double b, double c, double d){
   double rise,run,theta;
   double chordlen, perplen;
   double tantheta,tantheta1;
   double r = 2.5;

   chordlen = hypot(a-c,b-d);
   if (chordlen > 2*r) {
      return 0;
   }
   tantheta = sqrt(r*r*4 - chordlen*chordlen)/(chordlen);
/*
   theta = acos(chordlen*.5l/r);
   tantheta1 = tan(theta);
   printf("%lg %lg\n",tantheta1, tantheta);
*/
   run = (a-c)/2;
   rise = (b-d)/2;
   x1= (a+c)/2 + rise * tantheta;
   Y1 = (b+d)/2 + -run * tantheta;
   x2= (a+c)/2 + -rise * tantheta;
   y2 = (b+d)/2 + run * tantheta;
   return 1;
}
