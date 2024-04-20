#include <math.h>
#include <stdio.h>

double x[100], y[100], r[100];

double xp[1000], yp[1000]; int tree[1000];
int i,j,k, np, T;
double D, E, F, dx, dy, rdx, rdy, theta, phi;
double adj[1000][1000];  int derv[1000][1000];

void linepoints(double x1, double y1, double x2, double y2,
                double *a, double *b, double *c) {
   *a = y2 - y1;
   *b = x1 - x2;
   *c = *a * x1 + *b * y1;
}

double distpointline(double x, double y, double a, double b, double c) {
   return fabs(a*x + b*y - c)/sqrt(a*a + b*b);
}

double sqdist(double a, double b, double c, double d){
   return (a-c)*(a-c) + (b-d)*(b-d);
}

check(int i, int j, double xj, double yj, double xi, double yi){
   int k;
   double a,b,c,d;
   double dot1 = (xj-x[j])*(xj-xi) + (yj-y[j])*(yj-yi);
   double dot2 = (xi-x[i])*(xi-xj) + (yi-y[i])*(yi-yj);
   //printf("check %d %d %lf %lf : %lf %lf %lf %lf\n",i,j,dot2,dot1,xi,yi,xj,yj);

   linepoints(xi,yi,xj,yj,&a,&b,&c);

   for (k = 0; k<T; k++){
      if (k == i || k == j) continue;
      if (distpointline(x[k],y[k],a,b,c) > r[k]) continue;
      if ((x[k]-xi)*(xj-xi)+(y[k]-yi)*(yj-yi) < 0) continue;
      if ((x[k]-xj)*(xi-xj)+(y[k]-yj)*(yi-yj) < 0) continue;
      //printf(" ... rejected by circle %d\n",k);
      return;
   }
   adj[np][np+1] = adj[np+1][np] = hypot(xi-xj,yi-yj);
   tree[np] = j;
   xp[np] = xj;
   yp[np++] = yj;
   tree[np] = i;
   xp[np] = xi;
   yp[np++] = yi;
}


main(){
   double x1a, x1b, x1c, x1d, x2a, x2b, x2c, x2d, y1a, y1b,y1c, y1d, y2a, y2b, y2c, y2d;
   scanf("%d%lf%lf%lf%lf",&T,&x[0],&y[0],&x[1],&y[1]);
   r[0] = r[1] = 0;
   T += 2;
   for (i=2;i<T;i++) {
      scanf("%lf%lf%lf",&x[i],&y[i],&r[i]);
      r[i] /= 2;
   }
   xp[np] = x[0];
   yp[np++] = y[0];
   tree[np]=1;
   xp[np] = x[1];
   yp[np++] = y[1];
   for (i=0;i<T;i++) for (j=0;j<T;j++) {
      if (r[i] > r[j] || r[i]==r[j] && i>=j) continue;

      D = hypot(x[i]-x[j], y[i]-y[j]); 
      theta = asin((r[j]-r[i])/D);
  
      E = D * cos(theta);
      phi = atan(r[i]/E);

      F = E / cos(phi);

      dx = (x[j] - x[i]) * F/D;
      dy = (y[j] - y[i]) * F/D;
     
      rdx = cos(theta+phi) * dx - sin(theta+phi) * dy;
      rdy = sin(theta+phi) * dx + cos(theta+phi) * dy;

      x1a = x[i] + rdx;
      y1a = y[i] + rdy;

      rdx = cos(-theta-phi) * dx - sin(-theta-phi) * dy;
      rdy = sin(-theta-phi) * dx + cos(-theta-phi) * dy;

      x1b = x[i] + rdx;
      y1b = y[i] + rdy;

      dx = (x[j] - x[i]) * r[i]/D;
      dy = (y[j] - y[i]) * r[i]/D;

      rdx = cos(theta+M_PI/2) * dx - sin(theta+M_PI/2) * dy;
      rdy = sin(theta+M_PI/2) * dx + cos(theta+M_PI/2) * dy; 

      x2a = x[i] + rdx;
      y2a = y[i] + rdy;

      rdx = cos(-theta-M_PI/2) * dx - sin(-theta-M_PI/2) * dy;
      rdy = sin(-theta-M_PI/2) * dx + cos(-theta-M_PI/2) * dy; 
  
      x2b = x[i] + rdx;
      y2b = y[i] + rdy; 

      // Case 2:  tangent passes between centres

      D = hypot(x[i]-x[j], y[i]-y[j]);
      theta = asin((r[i]+r[j])/D);
      E = D * cos(theta);
      phi = atan(r[i]/E);
      F = E / cos(phi);

      dx = (x[j] - x[i]) * F/D;
      dy = (y[j] - y[i]) * F/D;

      rdx = cos(theta-phi) * dx - sin(theta-phi) * dy;
      rdy = sin(theta-phi) * dx + cos(theta-phi) * dy;

      x1c = x[i] + rdx;
      y1c = y[i] + rdy;

      rdx = cos(-theta+phi) * dx - sin(-theta+phi) * dy;
      rdy = sin(-theta+phi) * dx + cos(-theta+phi) * dy;

      x1d = x[i] + rdx;
      y1d = y[i] + rdy;

      dx = (x[j] - x[i]) * r[i]/D;
      dy = (y[j] - y[i]) * r[i]/D;

      rdx = cos(theta-M_PI/2) * dx - sin(theta-M_PI/2) * dy;
      rdy = sin(theta-M_PI/2) * dx + cos(theta-M_PI/2) * dy; 
      
      x2c = x[i] + rdx;
      y2c = y[i] + rdy;

      rdx = cos(-theta+M_PI/2) * dx - sin(-theta+M_PI/2) * dy;
      rdy = sin(-theta+M_PI/2) * dx + cos(-theta+M_PI/2) * dy; 
      
      x2d = x[i] + rdx;
      y2d = y[i] + rdy;

      check(i,j,x1a,y1a,x2a,y2a);
      check(i,j,x1b,y1b,x2b,y2b);
      check(i,j,x1c,y1c,x2c,y2c);
      check(i,j,x1d,y1d,x2d,y2d);

   }

   for (i=0;i<np;i++) for (j=0;j<np; j++) {
      if (i == j || adj[i][j]) continue;
      if (tree[i] != tree[j]) {
         adj[i][j] = 1e99;
      } else {
         double xx = x[tree[i]];
         double yy = y[tree[i]];
         double rr = r[tree[i]];
         double costheta = ((xp[i]-xx)*(xp[j]-xx)+(yp[i]-yy)*(yp[j]-yy)) / (rr*rr);
         double theta = acos(costheta);
         double d = theta * rr;
         if (rr == 0) continue;
         adj[i][j] = d;
      }
   }
   for (i=0;i<np;i++) for (j=0;j<np; j++) {
      if (adj[i][j] > 1e98) continue;
      //printf("edge %d %d %lf %lf %lf %lf (%lf)\n",tree[i],tree[j],xp[i],yp[i],xp[j],yp[j],adj[i][j]);
   }
   for (i=0;i<np;i++)for(j=0;j<np;j++)for(k=0;k<np;k++){
      if (adj[j][i]+adj[i][k] < adj[j][k]) {
         adj[j][k] = adj[j][i]+adj[i][k];
         derv[j][k] = i;
      }
   }
   printf("%0.2lf\n",adj[0][1]*3600/200, adj[0][1]);
   //printderv(0,1);
}

printderv(int i, int j){
   double r1, r2;
   if (i == j) return;
   if (!derv[i][j]) {
      printf("derv %lf %lf (tree %d)-> %lf %lf (tree %d) (%lf) \n",xp[i],yp[i],tree[i],xp[j],yp[j],tree[j],adj[i][j]); 
   }else{
      printderv(i,derv[i][j]);
      printderv(derv[i][j],j);
   }
}

