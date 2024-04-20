#include <algorithm>
#include <cassert>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <utility>
#include <vector>
using namespace std;

#define FR(i,a,b) for(int i=(a);i<(b);++i)
#define FOR(i,n) FR(i,0,n)
#define FORI(i,v) FOR(i,(int)(v).size())
#define RF(i,a,b) for(int i=(a)-1;i>=(b);--i)
#define ROF(i,n) RF(i,n,0)
#define ROFI(i,v) ROF(i,(int)(v).size())
#define FORALL(i,v) for(typeof((v).end())i=(v).begin();i!=(v).end();++i)
#define CLR(x,a) memset(x,a,sizeof(x))
#define BEND(v) (v).begin(),(v).end()
#define SZ(v) (int)(v).size()
#define MP make_pair
#define PB push_back
#define A first
#define B second
#define dump(x) cerr << #x << " = " << (x) << endl
typedef long long ll; typedef long double ld;

typedef complex<ll> cpx;
#define X real()
#define Y imag()

bool cpxlt(const cpx &p, const cpx &q) {
  if (p.X != q.X) return p.X < q.X;
  return p.Y < q.Y;
}
int n;
ll cross(const cpx &p, const cpx &q) {
  return (conj(p)*q).Y;
}
int main() {
  scanf("%d",&n);

  vector<cpx> pts;
  FOR(i,n) {
    cpx p;
    char ch;
    scanf("%lld%lld %c",&p.X,&p.Y,&ch);
    if (ch == 'Y') pts.PB(p);
  }

  sort(BEND(pts),cpxlt);

  vector<cpx> top,bot;
  FORALL(i,pts) {
    while (top.size()>=2 && cross(top[SZ(top)-1]-top[SZ(top)-2], *i-top.back())>0) top.pop_back();
    top.PB(*i);

    while (bot.size()>=2 && cross(bot[SZ(bot)-1]-bot[SZ(bot)-2], *i-bot.back())<0) bot.pop_back();
    bot.PB(*i);
  }
  assert(top[0] == bot[0]);
  assert(top.back() == bot.back());
  assert(SZ(top)+SZ(bot) == 2 + SZ(pts));

  printf("%d\n",SZ(pts));
  FORI(i,bot) if (i+1 < SZ(bot)) printf("%lld %lld\n", bot[i].X, bot[i].Y);
  ROFI(i,top) if (i) printf("%lld %lld\n", top[i].X, top[i].Y);
}
