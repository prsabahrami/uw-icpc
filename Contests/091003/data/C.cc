#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <string>
#include <vector>
using namespace std;

#define SZ(v) int((v).size())
#define FR(i,a,b) for(int i=(a);i<(b);++i)
#define FOR(i,n) FR(i,0,n)
#define FORI(i,v) FOR(i,SZ(v))
#define CLR(x,a) memset(x,a,sizeof(x))
#define setmax(a,b) a = max(a,b)
#define setmin(a,b) a = min(a,b)
typedef long long ll;

const int den = 1000000;
char buf[16];
bool mark[den+1];
vector<int> rev[den+1];
void doit() {
  scanf("%s",buf);
  if (0==strcmp("END",buf)) exit(0);

  string s(buf);
  {
    size_t i = s.find('.');
    if (i != string::npos) s = s.substr(0,i) + s.substr(i+1);
  }

  while ((int)s.size() < 7) s.push_back('0');
  int num;
  sscanf(s.c_str(), "%d", &num);

  printf("%s\n", mark[num] ? "NON-MEMBER" : "MEMBER");
}
int main() {
  CLR(mark,0);

  deque<int> q;
  FOR(n,den) {
    int next = (3*n)%den;
    int dig = (3*n)/den;

    if (dig==1 && next!=0) {
      mark[n] = 1;
      q.push_back(n);
    }

    rev[next].push_back(n);
  }

  while (q.size()) {
    int n = q.front(); q.pop_front();
    FORI(i,rev[n]) {
      int m = rev[n][i];
      if (!mark[m]) {
	mark[m] = 1;
	q.push_back(m);
      }
    }
  }

  while (1) doit();
}
