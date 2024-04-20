#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <map>
#include <limits.h>
#include <float.h>

using namespace std;

#define MAXN 10+1

int main () {
  int t;
  scanf("%d",&t);
  for(int sc = 1; sc <=t; sc++) {
    printf("Scenario %d:\n",sc);
    int n, v[MAXN], h[MAXN];
    scanf("%d",&n);
    assert(1<=n && n<=MAXN);
    int gs;
    scanf("%d\n",&gs);
    for(int i=1;i<=n;i++) { scanf("%d",&h[i]); assert(1<=h[i]&&h[i]<=50); }
    for(int i=1;i<=n;i++) { scanf("%d",&v[i]); assert(1<=v[i]&&v[i]<=50); }
    int xs,ys,xt,yt,te,tl;
    scanf("%d%d%d%d%d%d",&xs,&ys,&xt,&yt,&te,&tl);
    assert(tl <= 1000);
    int dx = 0, dy = 0;
    map<int,double> m[MAXN][MAXN];
    pair<int,double> p;
    if (tl < te) goto B;
    if (xs<xt) dx = 1; if (xs>xt) dx = -1;
    if (ys<yt) dy = 1; if (ys>yt) dy = -1;
    m[xs][ys][0] = 0.0;
    for(int i=xs;;i+=dx) {
      if (dx > 0 && i>xt) break;
      if (dx < 0 && i<xt) break;
      for(int j=ys;;j+=dy) {
	//	printf("%d %d, qsize = %d \n",i,j, m[i][j].size());
	if (dy > 0 && j>yt) break;
	if (dy < 0 && j<yt) break;
	if (i==xt && j==yt) goto A;
	if (i!=xt) {
	  map<int,double> :: iterator pos;
	  for(pos=m[i][j].begin();pos!=m[i][j].end();pos++) {
	    for(int s=5;s<=h[j];s+=5) {
	      int t = (*pos).first+3600*gs/s;
	      if ( t > 60*tl) continue;
	      if (m[i+dx][j].find(t) == m[i+dx][j].end() ||
		  m[i+dx][j][t] > (*pos).second+gs/(80-0.03*s*s))
		m[i+dx][j][t] = (*pos).second+gs/(80-0.03*s*s);
	    }
	  }
	}
	if (j!=yt) {
	  map<int,double> :: iterator pos;
	  for(pos=m[i][j].begin();pos!=m[i][j].end();pos++) {
	    for(int s=5;s<=v[i];s+=5) {
	      int t = (*pos).first+3600*gs/s;
	      if (t > 60*tl) continue;
	      if (m[i][j+dy].find(t) == m[i][j+dy].end() ||
		  m[i][j+dy][t] > (*pos).second+gs/(80-0.03*s*s))
		m[i][j+dy][t] = (*pos).second+gs/(80-0.03*s*s);
	    }
	  }
	}
	if (!dy) break;
      }
      if (!dx) break;
    }
  A: if (m[xt][yt].empty()) goto B;
  else {
    p = *(m[xt][yt].begin());
    assert(p.first <= tl*60);
    double bt=INT_MAX,btf, bf=DBL_MAX, bft;
    map<int,double>:: iterator pos;
    for(pos=m[xt][yt].begin();pos!=m[xt][yt].end();pos++) {
      p = *pos;
      assert(p.first <= tl*60);
      if (p.first < 60*te || p.first > 60*tl) continue;
      if (p.second < bf) { bf = p.second; bft = p.first; }
      else if (p.second == bf && p.first < bft) bft = p.first;
      if (p.first < bt) { bt = p.first; btf = p.second; }
      else if (p.first == bt && p.second < btf) btf = p.second;
    }
    if (bt == -1) goto B;
    printf("The earliest  arrival: %.0f minutes, fuel %.2f gallons\n",
	   ceil(bt/60), btf);
    printf("The economical travel: %.0f minutes, fuel %.2f gallons\n",
	   ceil(bft/60), bf);
    continue;
  }
  B: printf("IMPOSSIBLE\n"); 
  }
}
