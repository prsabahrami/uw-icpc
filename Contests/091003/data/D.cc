#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <string>
#include <vector>
using namespace std;

#define SZ(v) int((v).size())
#define FR(i,a,b) for(int i=(a);i<(b);++i)
#define FOR(i,n) FR(i,0,n)
#define FORI(i,v) FOR(i,SZ(v))
#define CLR(x,a) memset(x,a,sizeof(x))
#define setmax(a,b) a = max(a,b)
#define setmin(a,b) a = min(a,b)
typedef long long ll;

int N,x,y,v,c;
int xs[30],ys[30];
double sqr(double x) { return x*x; }
double f(int i, int j, double a) {
  double x0 = xs[i]*(1-a) + xs[j]*a;
  double y0 = ys[i]*(1-a) + ys[j]*a;

  return sqrt(sqr(x-x0)+sqr(y-y0))/c + y0/v;
}
void doit() {
  scanf("%d%d%d%d%d",&N,&x,&y,&v,&c);
  if (N==0) exit(0);

  FOR(i,N) {
    scanf("%d%d",&xs[i],&ys[i]);
  }

  double t = 1e100;
  FOR(i,N) {
    int j = (i+1)%N;
    double lo = 0, hi = 1;

    FOR(k,200) {
      double m1 = (2*lo+hi)/3, m2 = (lo+2*hi)/3;
      
      if (f(i,j,m1) < f(i,j,m2)) hi = m2;
      else lo = m1;
    }

    setmin(t, f(i,j,lo));
  }

  printf("%.4lf\n",t);
}
int main() {
  while (1) doit();
}
