#include <stdio.h>
#include <math.h>

double r,x,y,xx,yy,X,Y,dx,dy,dd,c;

void move(double x, double y, double X, double Y){
   char tmp[100];
   tmp[0] = 0;
   if (Y > y) strcpy(tmp,"north");
   if (Y < y) strcpy(tmp,"south");
   if (X > x) strcat(tmp,"east");
   if (X < x) strcat(tmp,"west");
   printf("%s %0.10lf\n",tmp,hypot(X-x,Y-y));
}

main(){
   while (5 == scanf("%lf%lf%lf%lf%lf",&r,&x,&y,&X,&Y)) {
      if (c++) printf("\n");
      dx = fabs(X-x);
      dy = fabs(Y-y);
      if (dx == 0 || dy == 0 || dx == dy) {
         move(x,y,X,Y);
         continue;
      }
      dd = dx < dy ? dx : dy;
      xx = x + (X-x)/fabs(X-x)*dd;
      yy = y + (Y-y)/fabs(Y-y)*dd;
      //xx = x + (X>x)?dd:-dd;
      //yy = y + (Y>y)?dd:-dd;
      if (hypot(xx,yy) < r) {
         move(x,y,xx,yy);
         move(xx,yy,X,Y);
         continue;
      }
      xx = X + (x-X)/fabs(x-X)*dd;
      yy = Y + (y-Y)/fabs(y-Y)*dd;
      //xx = X - (X>x)?dd:-dd;
      //yy = Y - (Y>y)?dd:-dd;
      move(x,y,xx,yy);
      move(xx,yy,X,Y);
   }
   if (r != -1) printf("Invalid terminator %0.10lf\n");
}
