#include <stdio.h>
#include <math.h>
#include <assert.h>

#define N 1000

double s,delta,k,hb,db,hn,dn,h,V,hs,v;

double area(double r, double s) {
   double t = db/2-s;
   double theta = t<r?acos(t/r):0;
   double wedge = theta * r * r;
   double triangles = r * cos(theta) * r * sin(theta);
   //printf("t %lg r %lg s %lg\n",t,r,s);
   return wedge - triangles;
}

double volume(double s) {
   if (s*2 > db) return V - volume(db-s);
   double vb = area(db/2, s) * hb;
   double vn = area(dn/2, s) * hn;
   double vc = area(db/2, s) + area(dn/2, s);
   int i;
   for (i=1;i<N;i+=2) {
      vc += 4 * area((db + (dn-db)*i/N)/2, s);
   }
   for (i=2;i<N;i+=2) {
      vc += 2 * area((db + (dn-db)*i/N)/2, s);
   }
   vc *= (h-hn-hb)/3/N;
   //printf("vb %lg %lg %lg %lg\n",vb,vn,vc,vb+vn+vc);
   return vb + vn + vc;
}

doit(){
   int hnx = hn, hbx = hb, hx = h, dnx = dn;
   V = 2 * volume(db/2);
   if (k <= hb) {
      hn = 0;
      hb = k;
      h = k;
   } else if (k < h-hn) {
      dn = db + (dn-db) * (k-hb) / (h-hn-hb);
      hn = 0;
      h = k;
   } else {
      hn = hn - h + k;
      h = k;
   }
   v = 2 * volume(db/2);
   hn = hnx; hb = hbx; h = hx; dn = dnx;
   //printf("V %lg v %lg %lg\n",V,v,dn*area(dn/2,db/2) +
                       //db*area(db/2,db/2));
   s = db/2;
   for (delta=s/2;delta > .00001; delta /=2) {
      if (volume(s) > v) s -= delta;
      else s += delta;
   }
   //printf("%lg %lg %lg %lg\n",s,volume(s),v,V);
   printf("%0.2lf\n",s);
}

main(){
   while (6 == scanf("%lf%lf%lf%lf%lf%lf",&k,&hb,&db,&hn,&dn,&h)) {
      if (!(k||hb||db||hn||dn||h)) return;
      assert (k>=0);
      assert (k<=h);
      assert (hb>=0); 
      assert (hn>=0);
      assert (h >= hb+hn);
      assert (h <=100);
      assert (db <=100);
      assert (dn <= db);
      assert (db >=0); 
      assert (dn >=0);
      doit();
   }
   printf("wrong input\n");
}
