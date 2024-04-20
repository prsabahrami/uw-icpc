#include <stdio.h>
#include <queue>
#include <list>

using namespace std;

class elem {
public:
  int r, v;
};

int main () {
  
  while (1) {
    int n;
    list<int> c[110];
    queue<elem> q;
    int v[110];
    int hv[110];
    scanf("%d",&n);
    if (n==-1) break;
    for(int i=1;i<=n;i++) hv[i]=-1000000;
    for(int i=1;i<=n;i++) {
      scanf("%d",&v[i]);
      int cn;
      scanf("%d",&cn);
      for(int j=0;j<cn;j++) {
	int r;
	scanf("%d",&r);
	c[i].push_back(r);
      }
    }
    elem a;
    a.r=1; a.v=100;
    q.push(a);
    while (!q.empty()) {
      elem a = q.front(); q.pop();
      if (a.r==n) {printf("winnable\n"); goto A;}
      list<int>::const_iterator pos;
      for(pos=c[a.r].begin();pos!=c[a.r].end();pos++) {
	elem b;
	b.r=*pos;b.v=a.v+v[b.r];
	if (b.v <= 0) continue;
	if (b.v > hv[b.r] && b.v <10001) { hv[b.r] = b.v; q.push(b); }
      }
    }
    printf("hopeless\n");
  A:;
  }
  return 0;
}
