#include <algorithm>
#include <cassert>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <queue>
#include <vector>
using namespace std;

#define FR(i,a,b) for(int i=(a);i<(b);++i)
#define FOR(i,n) FR(i,0,n)
#define CLR(x,a) memset(x,a,sizeof(x))
#define setmax(a,b) a = max(a,b)
#define PB push_back
#define BEND(v) (v).begin(),(v).end()
#define MP make_pair
#define A first
#define B second
#define FORALL(i,v) for(typeof((v).end())i=(v).begin();i!=(v).end();++i)
typedef long long ll;

char buf[1024*1024];
void doit() {
  scanf(" %s",buf);
  if (0 == strcmp("END",buf)) exit(0);

  int t = 0;
  string xt = buf,xt1;
  while (xt != xt1) {
    ++t;
    xt1 = xt;
    sprintf(buf, "%d", (int)xt1.size());
    xt = buf;
  }

  printf("%d\n", t);
}

const int MULTICASE = 1;
int main() {
  do {
    doit();
  } while (MULTICASE);
}
