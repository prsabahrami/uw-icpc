/*
LANG: C++
*/
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;

#define MP make_pair
#define A first
#define B second

#define PB push_back
#define FR(i, a, b) for(int i=(a); i<(b); i++)
#define FOR(i, n) FR(i, 0, n)
#define RF(i, a, b) for(int i=(b)-1; i>=(a); i--)
#define ROF(i, n) RF(i, 0, n)
#define EACH(it,X) for(__typeof((X).begin()) it=(X).begin(); it!=(X).end(); ++it)

typedef long long ll;

int r, c;
ll grid[50][50], answer[50][50];;

void moo(ll key) {
  memset(grid, 0, sizeof(grid));
  FR(i, 1, c+1) 
    grid[1][i] = (key >> (i - 1)) % 2LL;
  FR(i, 1, r+1)
    FR(j, 1, c+1)
      grid[i+1][j] = grid[i][j] ^ grid[i][j-1] ^ grid[i][j+1] ^ grid[i-1][j];
  FR(j, 1, c+1)
    if(grid[r+1][j] != 0) return;
  FR(i, 1, r+1) FR(j, 1, c+1)
    answer[i][j] = grid[i][j];
}

ll mask[50][50];
ll lis[50];
int t;

int dot(ll a, ll b) {
  ll x = a & b;
  int res = 0;
  FOR(i, 60) res += ((x >> i) % 2LL);
  return res % 2;
}

void showmask(ll x) {
  FOR(i, c) printf("%lld", (x>>i)%2LL);
  printf("\n");
}

int leadingbit(ll x) {
  FOR(i, c) if((x>>i)%2LL == 1LL) return i;
  return -1;
}

ll findkey() {
  t = 0;
  memset(mask, 0, sizeof(mask));
  FR(i, 1, c+1) 
    mask[1][i] = (1LL<<(i-1));
  FR(i, 1, r+1)
    FR(j, 1, c+1)
      mask[i+1][j] = mask[i][j] ^ mask[i][j-1] ^ mask[i][j+1] ^ mask[i-1][j];
  t = 0;
  FR(j, 1, c+1)
    lis[t++] = mask[r+1][j];
//FOR(i, t) {printf("%d   ", dot(lis[i], ((1LL<<40) - 1))); showmask(lis[i]);}
  int t1 = 0;
  FOR(i, c) {
    FR(j, t1, t) if((lis[j]>>i)%2LL == 1LL) {
      swap(lis[t1], lis[j]);
      break;
    }
    if((lis[t1] >> i)%2LL == 1LL) {
      t1++;
      FR(j, t1, t) if((lis[j]>>i)%2LL == 1LL)
        lis[j] = lis[j] ^ lis[t1-1];
    }
  }
  ll key = 0;
  ROF(i, c) {
    int i1 = 0;
    while(i1 < t && (leadingbit(lis[i1]) != i)) ++i1;
//printf("%d:", i1);
    if(i1 < t) {
      if(dot(key, lis[i1])) key += (1LL<<i);
    }
    else key += (1LL<<i);
//showmask(key);
  }
//FOR(i, t) showmask(lis[i]);
//showmask(key);
  return key;
}

int main() {
//freopen("harm.in", "r", stdin);
//freopen("harm.out", "w", stdout);
  srand(0);
  int ct;
  scanf("%d", &ct);
  while(ct--) {
    memset(answer, 0, sizeof(answer));
    scanf("%d%d", &r, &c);
    moo(findkey());
    FR(i, 1, r+1) { 
      FR(j, 1, c+1) {
//if(answer[i][j] ^ answer[i-1][j] ^ answer[i+1][j] ^ answer[i][j-1] ^ answer[i][j+1] != 0) {printf("FUBAR %d %d\n", i,j); assert(0);}
        printf("%d", answer[i][j]);
        if(j == c) printf("\n");
        else printf(" ");
      }
    }
  }
}
