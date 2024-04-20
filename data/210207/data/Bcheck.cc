#include "testlib.h"

#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <ctime>
#include <iostream>
#include <functional>
#include <complex>
#pragma comment(linker, "/STACK:836777216")

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<pii, int> p3i;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<p3i> v3i;
typedef vector<vii> vvii;
typedef vector<p3i> vp3i;
typedef long double ld;
typedef vector<ld> vld;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define REPD(i, n) for (int (i) = (n) - 1; (i) >= 0; (i)--)
#define FOR(i, a, b) for (int (i) = (a); (i) < (b); (i)++)
#define FORD(i,a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define sz(v) (int)(v).size()
#define all(v) (v).begin(), (v).end()
#define rv(v) reverse(all(v))
#define CL(v, val) memset((v), (val), sizeof((v)))
#define SORT(a) sort(all(a))
#define un(v) SORT(v), (v).resize(unique(all(v)) - (v).begin())
#define eps 1.0e-6
#define X first
#define Y second
#define bit(n) (1 << (n))
#define bit64(n) (ll(1) << (n))
#define sqr(x) ((x) * (x))
#define N 1005

int n, a, b;

void fail(string s) {
  quitf(_wa, ("WA: " + s).c_str());
}


int main(int argc, char* argv[]) {
  registerTestlibCmd(argc, argv);
  try
  {
    n = inf.readInt();

    int x;
    vector<int> p(n);
    vector<pair<int, int> > z;
    FOR(i,0,n) {
      x = inf.readInt();
      z.push_back(mp(x, i));
    }
    sort(z.begin(), z.end());
    FOR(i,0,n) {
        p[z[i].second] = i;
    }

    a = inf.readInt();
    b = inf.readInt();

    long long cost_user;
    long long cost_ans;
    int moves_user;
    int moves_ans;

    cost_user = ouf.readLong();
    moves_user = ouf.readInt();
    cost_ans = ans.readLong();
    moves_ans = ans.readInt();

    if ((cost_user != cost_ans) || (moves_user != moves_ans)) {
      fail("cost or moves");
    }

    vii m_user, m_ans;
    REP(i, moves_user) {
      int x,y;
      x = ouf.readInt(1,n);
      y = ouf.readInt(1,n);
      m_user.pb(mp(x - 1, y - 1));
      x = ans.readInt(1,n);
      y = ans.readInt(1,n);
      m_ans.pb(mp(x - 1, y-1));
    }
    long long real_price = 0;
    REP(i, sz(m_user)) {
      real_price += abs(m_user[i].X - m_user[i].Y) * 1LL * a + b;
      swap(p[m_user[i].X], p[m_user[i].Y]);
    }

    if (cost_ans != real_price) {
      fail("cost_ans != real_price");
    }

    bool valid = true;
    REP(i, n) {
      if (p[i] != i) {
        fail("p[i] != i");
      }
    }
  }
  catch (...){
    cout << "CHECKER ERROR" << endl;
    quitf(_fail, "Judge error");
  }
  quitf(_ok, "OK");
}
