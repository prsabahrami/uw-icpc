#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define debug(...) //ignore
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int r,c;
    cin>>r>>c;
    vector<string> grid(r);
    rep(i,0,r) cin>>grid[i];

    auto at = [&](int x, int y) {
        x = (x%r + r) % r;
        y = (y%c + c) % c;
        return grid[x][y];
    };

    vector<vector<vi>> where(2, vector<vi>(r, vi(c,-1)));
    where[0][0][0] = 0;
    rep(i,0,10*r*c) {
        auto& now = where[i%2];
        auto& nxt = where[(i+1)%2];
        if(now[r-1][c-1] >= i) {
            cout << i << endl;
            exit(0);
        }
        rep(x,0,r) rep(y,0,c) if(now[x][y] >= i) {
            if(at(x-i,y) == 'v') nxt[(x+1)%r][y] = i+1;
            if(at(x+i,y) == '^') nxt[(x+r-1)%r][y] = i+1;
            if(at(x,y-i) == '>') nxt[x][(y+1)%c] = i+1;
            if(at(x,y+i) == '<') nxt[x][(y+c-1)%c] = i+1;
        }
    }
    cout << "-1" << endl;
    return 0;
}
