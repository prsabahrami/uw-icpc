#include <stdio.h>
#include <assert.h>

int main () {
  unsigned int W, l ,h, n;
  while (scanf("%u",&n)==1) {
    assert(1 < n && n < 4294967295U);
    W = 1; 
    l = n/9; if (l*9<n) l++; h = n-1;
    while (1) {
      if (l <= 1 && 1 <= h) {
	printf(W?"Stan wins.\n":"Ollie wins.\n");
	break;
      }
      if (W) {
	if (l/2*2 < l) l = l/2+1; else l/=2;
	h/=9;
	W=0;
      } else {
	if (l/9*9 < l) l = l/9+1; else l/=9;
	h/=2;
	W=1;
      }
    }
    
  }
  return 0;
}
