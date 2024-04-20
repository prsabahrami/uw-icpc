#include <bits/stdc++.h>
using namespace std;
 
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define RFOR(i,b,a) for (int i = (b) - 1; i >= (a); i--)
#define ITER(it,a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a,value) memset(a, value, sizeof(a))
 
#define SZ(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair
 
typedef long long Int;
typedef vector<int> VI;
typedef pair<int, int> PII;
 
const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000;
const Int LINF = INF * (Int) INF;
const int MAX = 200007;
const int L = 20;
const int MOD = 998244353;

int f(PII a) {
    if (a.second == 0 && a.first > 0)
        return 0;
    if (a.first > 0 && a.second > 0)
        return 1;
    if (a.first == 0 && a.second > 0)
        return 2;
    if (a.first < 0 && a.second > 0)
        return 3;
    if (a.first < 0 && a.second == 0)
        return 4;
    if (a.first < 0 && a.second < 0)
        return 5;
    if (a.first == 0 && a.second < 0)
        return 6;
    if (a.first > 0 && a.second < 0)
        return 7;
    return 8;
}

bool Comp2(PII a, PII b) {
    int fa = f(a);
    int fb = f(b);
    if (fa < fb)
        return true;
    if (fb < fa)
        return false;
    return (Int)a.first * b.second > (Int)a.second * b.first;
}

bool Comp(pair<PII, int> aa, pair<PII, int> bb) {
    if (Comp2(aa.first, bb.first))
        return true;
    if (Comp2(bb.first, aa.first))
        return false;
    return aa.second < bb.second;
}

PII A[MAX];
bool S[MAX];

int main(int argc, char* argv[])
{
  //ios::sync_with_stdio(false); cin.tie(0);
    // rng = mt19937(chrono::steady_clock::now().time_since_epoch().count());

    int n;
    cin >> n;

    vector<pair<PII, int> > B;

    FOR(i,0,n) {
        int x, y;
        cin >> x >> y;
        A[i] = MP(x, y);
        B.push_back(MP(MP(x, y), i + 1));
        B.push_back(MP(MP(-x, -y), -(i + 1)));
    }

    sort(ALL(B), Comp);

    Int res = 0;

    Int X = 0;
    Int Y = 0;

    FOR(it,0,2)
        FOR(i,0,SZ(B)) {
            if (B[i].second > 0) {
                int id = B[i].second - 1;
                S[id] = true;
                X += A[id].first;
                Y += A[id].second;
            } else {
                int id = -B[i].second - 1;
                if (S[id]) {
                    S[id] = false;
                    X -= A[id].first;
                    Y -= A[id].second;
                }
            }
            res = max(res, X * X + Y * Y);
        }
    cout << res << endl;   

    cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
  return 0;
}


