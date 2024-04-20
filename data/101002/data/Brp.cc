#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <string>
#include <algorithm>
using namespace std;

const int MAXN = 1010;

typedef long long ll;
ll seed = 31;

ll pow[MAXN];

ll lis[MAXN], hash[MAXN];
char line[12345];
int n, l;

int moo(int l) {
  ll h = 0;;
  int t = 0;
  for(int i = 0; i < l; ++i)
    h = h * seed + lis[i];
  for(int i = l; i < n; ++i) {
    h = h * seed + lis[i];
    hash[t++] = h;
    h = h - lis[i - l] * pow[l];
  }
  sort(hash, hash + t);
//for(int i = 0; i < t; ++i) printf("%lld\n", hash[i]);
  int ma = 0;
  for(int i = 0; i < t;) {
    int i1;
    for(i1 = i + 1; i1 < t && hash[i1] == hash[i]; ++i1);
    ma = max(ma, i1 - i);
    i = i1;
  }
  if(ma == 1) return 0;
  printf("%d\n", ma);
  return 1;
}

int main () {
  pow[0] = 1;
  for(int i = 1; i < MAXN; ++i)
    pow[i] = pow[i - 1] * seed;
  gets(line);
  while((l = strlen(line)) > 0) {
    n = 0;
    assert(l <= 1000);
    for(int i = 0; i < l; ++i)
      if(line[i] >= 'A' && line[i] <= 'Z')
        lis[n++] = line[i] - 'A';
      else assert(line[i] == ' ');
    for(int i = 0; i < n; ++i) 
      if(!moo(i)) break;
    printf("\n");
    gets(line);
  }
  return 0;
}

