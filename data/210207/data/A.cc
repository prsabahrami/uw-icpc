#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(i, a) for(auto& i : a)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

using bs = bitset<105>;

struct SuffixAutomaton {
    struct node {
        int len, link, cnt, fpos;
        map<int,int> nxt;
        bs reach;
    };
    int last = 0;
    vector<node> st = {node{0, -1, 0, 0}};

    void extend(int c) {
        int p = last;
        last = sz(st);
        st.push_back(node{st[p].len + 1, 0, 1, st[p].len});
        for(; p >= 0 && !st[p].nxt.count(c); p = st[p].link)
            st[p].nxt[c] = last;
        if (p >= 0) {
            int q = st[p].nxt[c];
            if(st[p].len + 1 == st[q].len) st[last].link = q;
            else {
                int clone = sz(st);
                st.push_back(st[q]);
                st[clone].len = st[p].len + 1;
                st[clone].cnt = 0;
                for(; p >= 0 && st[p].nxt[c] == q; p = st[p].link)
                    st[p].nxt[c] = clone;
                st[q].link = st[last].link = clone;
            }
        }
    }
    void calc_reach(){
        vector<vi> ls(st[last].len+1);
        rep(i,0,sz(st)) ls[st[i].len].push_back(i);
        for(int len = st[last].len; len >= 0; --len) {
            for(auto i : ls[len]) {
                for(auto [c,j]: st[i].nxt) {
                    if(c <= 0) st[i].reach[-c] = 1;
                    else st[i].reach |= st[j].reach;
                }
            }
        }
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n;
    cin>>n;
    SuffixAutomaton sa;
    vector<string> v(n);
    bs target;
    rep(i,0,n) {
        cin>>v[i];
        for(char c : v[i]) sa.extend(c);
        sa.extend(-i);
        target[i] = 1;
    }
    sa.calc_reach();
    auto& st = sa.st;
    pii best = {0,0};
    for(auto& x:st ) {
        if(x.reach == target) {
            best = min(best, {-x.len, x.fpos - x.len +1});
        }
    }
    cout << v[0].substr(best.second, -best.first) << endl;
}
