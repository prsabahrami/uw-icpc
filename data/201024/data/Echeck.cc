#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


vi val, comp, z;
int Time, ncomps;
template<class G> int dfs(int j, G& g) {
    int low = val[j] = ++Time, x; z.push_back(j);
    for (auto e : g[j]) if (comp[e] < 0)
        low = min(low, val[e] ?: dfs(e,g));

    if (low == val[j]) {
        do {
            x = z.back(); z.pop_back();
            comp[x] = ncomps;
        } while (x != j);
        ncomps++;
    }
    return val[j] = low;
}
template<class G> void scc(G& g) {
    int n = sz(g);
    val.assign(n, 0); comp.assign(n, -1);
    Time = ncomps = 0;
    rep(i,0,n) if (comp[i] < 0) dfs(i, g);
}

int main(int argc, char * argv[]) {
    setName("Check that graph is a single SCC");
    registerTestlibCmd(argc, argv);

    int n = inf.readInt();
    int m = inf.readInt();

    vector<pii> v(m);
    rep(i,0,m) {
        v[i].first = inf.readInt()-1;
        v[i].second = inf.readInt()-1;
    }

    auto check = [&](auto& out) -> pair<bool, int> {
        vector<vi> g(n);
        int cnt = 0;
        rep(i,0,m) {
            out.skipBlanks();
            char c = out.readChar();
            if(c == '>' || c == '=') g[v[i].first].push_back(v[i].second);
            if(c == '<' || c == '=') g[v[i].second].push_back(v[i].first);
            if(c == '=') ++cnt;
        }
        scc(g);
        rep(i,0,n) if(comp[i] != 0) return {false, cnt};
        return {true, cnt};
    };

    auto [judge_ok, judge_cnt] = check(ans);
    if(!judge_ok) quitf(_fail, "judge solution is not a single scc");

    auto [ok, cnt] = check(ouf);
    if(!ok) quitf(_wa, "one cannot reach every place from every other in contestant's solution");

    if(cnt < judge_cnt) quitf(_fail, "judge solution (%d) is worse than contestants solution (%d)", judge_cnt, cnt);
    if(cnt > judge_cnt) quitf(_wa, "contestant solution (%d) is worse than judge solution (%d)", cnt, judge_cnt);

    quitf(_ok, "solution is okay");
}
