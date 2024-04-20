#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define FR(i,a,b) for(int i=(a);i<(b);++i)
typedef long long ll;

ll xs[1000001];
int i;
void doit() {
  scanf("%d",&i);
  if (i==-1) exit(0);

  printf("%lld\n", xs[i]);
}
int main() {
  xs[0] = 1;
  FR(j,1,1000001) {
    xs[j] = (xs[(int)floor(j-sqrt(j))]
	   + xs[(int)floor(log(j))]
	   + xs[(int)floor(j*sin(j)*sin(j))]) % 1000000;
  }

  while (1) doit();
}
