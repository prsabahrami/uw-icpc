#include <algorithm>
#include <cassert>
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

int n,m;
vector<int> edg[1000000];
int indeg[1000000];
void doit() {
  srandom(2009);
  scanf("%d%d",&n,&m);
  if (n==0) exit(0);

  FOR(i,n) indeg[i] = 0;
  FOR(i,m) {
    int a,b;
    scanf("%d%d",&a,&b);
    --a;--b;
    ++indeg[b];
    edg[a].PB(b);
  }

  deque<int> q;
  FOR(i,n) if (indeg[i] == 0) q.PB(i);
  vector<int> ret;

  bool happy = 1;
  FOR(i,n) {
    if (!q.size()) {
      happy = 0;
      break;
    }

    int r = random()%(int)q.size();
    swap(q[0], q[r]);

    int v = q.front(); q.pop_front();
    ret.PB(v+1);

    FORALL(w,edg[v]) {
      if (0==--indeg[*w]) q.PB(*w);
    }
  }

  FOR(i,n) edg[i].clear();

  if (happy) {
    FOR(i,n) printf("%d\n",ret[i]);
  } else {
    printf("IMPOSSIBLE\n");
  }
}

const int MULTICASE = 1;
int main() {
  do {
    doit();
  } while (MULTICASE);
}
