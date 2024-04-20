#include <stdio.h>
#include <assert.h>

typedef unsigned long long ULL;

ULL cnt(unsigned m) {
  ULL mc = 1;
  unsigned mleft = m, mright = 0, pow10 = 1; 
  for (int i=0;mleft;i++) {
    assert (mleft*pow10+mright == m);
    int digi = mleft%10;
    mleft /= 10;
    mc += digi ? mleft*pow10 : (mleft-1)*pow10+mright+1;
    mright = digi*pow10+mright;
    pow10 *=10;
  }
  return mc;
}

int zcnt(unsigned m) {
  int mc = 0;
  do { if (!(m%10)) mc++;
    m /= 10;
  } while (m);
  return mc;
}

int main () {

  long long m,n;

  while (1) {
    scanf("%lld%lld", &m,&n);
    if (m<0) break;
    assert(m<=n);
    ULL mc, nc;
    mc = cnt(m);
    nc = cnt(n);
    printf("%llu\n",nc-mc+zcnt(m));
  }
}
