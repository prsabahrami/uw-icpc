/*
LANG: C++
*/

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>

#define MAXN 2001

unsigned short int sum[MAXN][MAXN];
int n, w, l;
int Z;

int getsum(int x, int y, int len){
  int x2 = x - len;
  int y2 = y - len;
  if (x2 < 0 || y2 < 0)
    return l+1;
  return sum[x][y] + sum[x2][y2] - sum[x2][y] - sum[x][y2];
}

int bsearch(int x, int y, int bot, int top){
  if (bot == top) return bot;
  int mid = (bot + top + 1) / 2;
  if (getsum(x, y, mid) <= l)
    return bsearch(x, y, mid, top);
  else
    return bsearch(x, y, bot, mid-1);
}

int main(){
//  freopen("square.in", "r", stdin);
//  freopen("square.out", "w", stdout);
  scanf("%d", &Z);
  for(int tcase = 0; tcase < Z; tcase++){
    memset(sum, 0, sizeof(sum));
    scanf("%d %d %d", &n, &w, &l);
    assert(1 <= n && n <= 2000);
    assert(1 <= w && w <= 50000);
    assert(0 <= l && l <= w);
    int x, y;
    for(int i = 0; i < w; i++){
      scanf("%d %d", &x, &y);
      assert(1 <= x && x <= n);
      assert(1 <= y && y <= n);
      assert(sum[x][y] == 0);
      sum[x][y] = 1;
    }
    for(x = 1; x <= n; x++){
      for(y = 1; y <= n; y++){
        sum[x][y] += sum[x-1][y] + sum[x][y-1] - sum[x-1][y-1];
      }
    }
    int ans = 0;
    for(x = 1; x <= n; x++){
      for(y = 1; y <= n; y++){
        ans = std::max(ans, bsearch(x, y, 0, x));
      }
    }
    printf("%d\n", ans*ans);
  }
}