#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>

int main () {
  int h, m, s;
  double x[6];
  while (1) {
    for (int i = 1; i < 6; i++) {
      if (scanf("%d:%d:%d",&h,&m,&s) != 3) return 0;
      x[i] = h*3600+m*60+s;
    }
    assert(x[1] < x[2]);
    assert(x[2] < x[3]);
    assert(x[3] < x[4]);
    assert(x[4] < x[5]);
    x[2] -= x[1];
    x[3] -= x[1];
    x[4] -= x[1];
    x[5] -= x[1];
    double A = (x[5]-x[4])/(x[5]-x[2])*(1-x[2]/x[3]);
    double B = (x[2]/x[3]-x[2]/x[4]);
    double ans = (B*x[4]+A*x[2])/(A+B)+x[1];
    char buf[100];
    sprintf(buf, "%.0f",ans); sscanf(buf,"%d",&s);
    h = s/3600; s %= 3600; m = s/60; s %= 60;
    printf("%02d:%02d:%02d\n",h,m,s);
  }
  return 0;
}
