#include <stdio.h>

double p;

double doit(int n, double s) {
  if (!n) return s;
  double lv = 0.5/s;
  if (p<lv) 
    return doit(n-1,((lv-p)+s*(1-lv*lv))/(1-p));
  else
    return doit(n-1,s*(1+p));
}

int main () {
  while (1) {
    int n;
    scanf("%d",&n);
    if (!n) break;
    scanf("%lf",&p);
    printf("%.3f\n",doit(n,1.0));
  
  }
}
