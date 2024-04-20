#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

double h, v;
int cnt;

void doit(double llx, double lly, double urx, double ury) {
  double nx = llx+(urx-llx)*h, ny = lly+(ury-lly)*v;
  cnt--;
  if (cnt) { 
    if (rand()%2) 
      doit(llx,lly,nx,ny);
    else 
      doit(nx,ny,urx,ury);    
  }
  else 
    printf("%.10f %.10f\n",(llx+urx)/2,(lly+ury)/2);
}

int main () {

  double H, V;
  int c = 0, n;
  while (1) {
    scanf("%lf%lf%lf%lf",&H,&V,&h,&v);
    if (!H) {
      printf("0 0 0 0\n");
      return 0;
    }
    printf("%f %f %f %f\n",H,V,h,v);
    scanf("%d",&n);
    printf("%d\n",n);
    while (n--) {
      // scanf("%lf%lf",&x,&y);
      //      printf("\t %.10f %.10f\n", x, y);
      cnt = 1+rand()%20;
      doit(0,0,H,V);
    }
  }
  
}
