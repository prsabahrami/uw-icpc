#include <stdio.h>
#include <assert.h>

#define B 1
#define W 2

int S[3];
int a[30][30], n, m;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void remove(int p, int x, int y) {
  S[3-p]++;
  a[x][y] = 0;
  for (int i=0;i<4;i++) 
    if (a[x+dx[i]][y+dy[i]] == 6) remove(p,x+dx[i],y+dy[i]);
}

void ff_live(int p, int x, int y) {
  a[x][y] = 5;
  for (int i=0;i<4;i++) 
    if (a[x+dx[i]][y+dy[i]] == p) ff_live(p,x+dx[i],y+dy[i]);
}
 
void undo_ff_live(int p, int x, int y) {
  a[x][y] = p;
  for (int i=0;i<4;i++) 
    if (a[x+dx[i]][y+dy[i]] == 6) undo_ff_live(p,x+dx[i],y+dy[i]);
}
 
int ff(int x, int y) {
  a[x][y]=5;
  int ret = 1;
  for (int i=0;i<4;i++) 
    if (!a[x+dx[i]][y+dy[i]]) ret += ff(x+dx[i],y+dy[i]);
  return ret;
}

int N[10];

void ngbr(int x, int y) {
  a[x][y] = 6;
  for (int i=0;i<4;i++) {
    if (a[x+dx[i]][y+dy[i]] == 0) N[0] = 1;
    if (a[x+dx[i]][y+dy[i]] == B) N[B] = 1;
    if (a[x+dx[i]][y+dy[i]] == W) N[W] = 1;
    if (a[x+dx[i]][y+dy[i]] == 5) ngbr(x+dx[i],y+dy[i]);
  }
}

int main () {
  while (1) {
    scanf("%d%d",&n,&m);
    if (!n) break;
    assert (n%2);
    for(int i=0;i<n+2;i++) 
      for(int j=0;j<n+2;j++) {
	a[i][j] = 0;
	if (!i || !j || i==n+1 || j == n+1) a[i][j] = 4;
      }
    S[1] = S[2] = 0;
    while (m--) {
      int x,y, pi;
      char pc;
      scanf(" %c(%d,%d)",&pc,&x,&y);
      pi = (pc == 'B') ? B : W;
      x += 1+n/2; y += 1+n/2;
      assert(!a[x][y]);
      a[x][y] = pi;
      for(int i=0;i<4;i++)
	if (a[x+dx[i]][y+dy[i]] == 3-pi) {
	  ff_live(3-pi,x+dx[i],y+dy[i]);
	  N[0] = 0;
	  ngbr(x+dx[i],y+dy[i]);
	  if (!N[0]) 
	    remove(3-pi,x+dx[i],y+dy[i]);
	  else 
	    undo_ff_live(3-pi,x+dx[i],y+dy[i]);
	}
      // checked earleir there were no suicides
    }
    for(int i=1;i<n+1;i++)
      for(int j=1;j<n+1;j++) 
	if (!a[i][j]) {
	  int cnt = ff(i,j);
	  N[1] = N[2] = 0;
	  ngbr(i,j);
	  if (N[1] && !N[2]) S[B]+=cnt;
	  if (!N[1] && N[2]) S[W]+=cnt;
	}
    printf("%d %d\n",S[1], S[2]);
  }
}
