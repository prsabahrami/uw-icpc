#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
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

const int MAXN = 1000100;
const int siz = 1<<20;
typedef long long ll;
int n;
pair<int,int> lis[MAXN];
int order[MAXN];
int hea[siz * 2];
ll ans;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    scanf("%d", &lis[i].A);
    lis[i].B = i;
  }
  sort(lis, lis + n);
  for(int i = 0; i < n; ++i)
    order[lis[i].B] = n - 1 -i;
  ans = 0;
  memset(hea, 0, sizeof(hea));
  for(int i = 0; i < n; ++i) {
//printf("%d\n", order[i]);
    int p = order[i] + siz;
    while(p) {
      if(p % 2) ans += ll(hea[p-1]);
      hea[p]++;
      p /= 2;
    }
  }
  printf("%lld\n", ans);
  return 0;
}

