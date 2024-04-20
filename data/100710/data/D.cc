#include <cstdio>
#include <string>
#include <map>

#define ll long long

using namespace std;

ll tax(ll cents, ll rate) {
  return (cents * rate + 5000) / 10000;
}
main() {
    int NN;
    scanf("%d", &NN);
    while(NN--) {
      map<string, ll> pst;
      map<string, ll> gst;
      map<string, ll> hst;
      int N, M;
      scanf("%d %d ", &N, &M);
      while(N--) {
        char name[100];
        double pp, gg, hh;
        scanf("%s %lf%% %lf%% %lf%%\n", &name, &pp, &gg, &hh);
        ll p = pp*100+.5;
        ll g = gg*100+.5;
        ll h = hh*100+.5;
        pst[string(name)] = p;
        gst[string(name)] = g;
        hst[string(name)] = h;
      }
      ll cents = 0;
      while(M--) {
        char name[100];
        double pp;
        scanf("%s $%lf\n", &name, &pp);
        ll p = pp*100+.5;
        string nm = string(name);
        cents += tax(p, hst[nm]) - tax(p, gst[nm]) - tax(p, pst[nm]);
      }
      printf("%.02lf\n", cents*.01);
    }
}
