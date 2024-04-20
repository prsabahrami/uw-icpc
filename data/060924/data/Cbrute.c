#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define N 100000000

FILE *in;

double vv,d,s,delta,k,hb,db,hn,dn,h,V,hs,v;
int w;

doit(){
   double X,Y,Z;
   int i, hhcnt=0, cnt=0, vcnt=0, hcnt=0, Hcnt = 0;
   for (i=0;i<N;i++) {
      X = db*random()/RAND_MAX;
      Y = db*random()/RAND_MAX;
      Z = h*random()/RAND_MAX;
      if (Z <= hb) d = db;
      else if (Z <= h-hb) d = db + (dn-db) * (Z-hb)/(h-hb-hn);
      else d = dn;
      cnt += (w=(X-db/2)*(X-db/2)+(Y-db/2)*(Y-db/2) <= (d/2)*(d/2));
      if (Y <= s)
         hhcnt += w;
      if (Y <= s-.005)
         hcnt += w;
      if (Y <= s+.005)
         Hcnt += w;
      if (Z <= k)
         vcnt += w;
   }
   printf("%0.3lf [%0.3lf] %0.3lf",
          db*db*h*hcnt/N, 
          db*db*h*vcnt/N, 
          //db*db*h*hhcnt/N, 
          db*db*h*Hcnt/N ,v);
   if (vcnt < hcnt || vcnt > Hcnt) {
      printf(" ***\n");
      doit();
   } else printf("\n");
}

main(){
   in = fopen("C.in","r");
   while (6 == fscanf(in,"%lf%lf%lf%lf%lf%lf",&k,&hb,&db,&hn,&dn,&h)) {
      if (!(k||hb||db||hn||dn||h)) return;
      scanf("%lf",&s);
      doit();
   }
   printf("wrong input\n");
}
