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

int R,C;
int i1,j1,i2,j2;
bool mark[20][20][4][1601];
int dist[20][20][4][1601];
bool pass[20][20][4];
int dr[] = { -1, 0, 1, 0 },
    dc[] = { 0, 1, 0, -1 };
deque<pair<pair<int,int>, pair<int,int> > > q;
void enq(int d, int r, int c, int rot, int rem) {
  assert(rem <= 1600);
  if (rem < 0) return;
  if (mark[r][c][rot][rem]) return;
  q.PB(MP(MP(r,c),MP(rot,rem)));
  mark[r][c][rot][rem] = 1;
  dist[r][c][rot][rem] = d;
}
void doit() {
  scanf("%d%d",&R,&C);
  if (R==0) exit(0);

  scanf("%d%d%d%d",&i1,&j1,&i2,&j2);
  --i1;--j1;--i2;--j2;

  CLR(pass,0);
  FOR(r,R) {
    FOR(c,C) {
      char buf[256];
      scanf("%s",buf);

      if (buf[0] == 'x') continue;

      for (char *p = buf; *p; ++p) {
	pass[r][c][
	  *p=='N' ? 0 :
	  *p=='E' ? 1 :
	  *p=='S' ? 2 :
		    3] = 1;
      }
    }
  }

  CLR(mark,0);
  q.clear();
  q.PB(MP(MP(i1,j1), MP(0,0)));
  mark[i1][j1][0][0] = 1;
  dist[i1][j1][0][0] = 0;

  int ans = -1;
  while (q.size()) {
    int r = q.front().A.A,
	c = q.front().A.B,
	rot = q.front().B.A,
	rem = q.front().B.B,
	d = dist[r][c][rot][rem];
    q.pop_front();

    if (r == i2 && c == j2) {
      ans = d;
      break;
    }

    for (int drot = -1; drot <= 1; ++drot) {
      int rotp = (rot+drot+4)%4;
      int remp = rem + (drot==0);

      enq(d+1, r, c, rotp, remp);

      FOR(k,4) {
	int r2 = r + dr[k], c2 = c + dc[k];
	if (r2<0 || r2>=R || c2<0 || c2>=C) continue;
	int kp = (k+rotp)%4;
	if (!pass[r][c][kp]) continue;
	
	for (int drot2 = -1; drot2 <= 2; ++drot2) {
	  if (abs(drot2) > remp) continue;
	  int rot2 = (drot2+4)%4,
	      rem2 = remp - abs(drot2);
	  if (!pass[r2][c2][(k+rot2+2)%4]) continue;

	  enq(d+1, r2, c2, rot2, rem2);
	}
      }
    }
  }

  printf("%d\n",ans);
}

const int MULTICASE = 1;
int main() {
  do {
    doit();
  } while (MULTICASE);
}
