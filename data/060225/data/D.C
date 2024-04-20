#include <stdio.h>
#include <assert.h>

double x, y, h, v;

int doit(double llx, double lly, double urx, double ury, int col) {
  assert(llx <= x && x <= urx && lly <= y && y <= ury);
  double nx = llx+(urx-llx)*h, ny = lly+(ury-lly)*v;
  //      printf("\t\t %6.3f %6.3f\n", nx, ny);  
  if (x < nx && y < ny) 
    return doit(llx,lly,nx,ny,1-col);
  else if (x > nx && y > ny)
    return doit(nx,ny,urx,ury,1-col);    
  else if (x < nx && y > ny || x > nx && y < ny)
    return col;
  else 
    assert (0 && "too close to call");
}

int main () {

  double H, V;
  int c = 0, n;
  while (1) {
    scanf("%lf%lf%lf%lf",&H,&V,&h,&v);
    if (!H) {
      assert(!V && !h && !v);
      return 0;
    }
    printf("Case %d:\n",++c);
    scanf("%d",&n);
    while (n--) {
      scanf("%lf%lf",&x,&y);
      //      printf("\t %.10f %.10f\n", x, y);
      printf(doit(0,0,H,V,1) ? "black\n" : "white\n");
    }
  }
  
}
