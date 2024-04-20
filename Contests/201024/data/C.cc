#include "bits/stdc++.h"
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
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
 
const double Pi = acos(-1.0);

const int LEN = 19;
const int MOD = 1000000007;
const int MAX = 5000000;

int p[MAX];
int d[MAX];
Int D[MAX];

Int brute(int n, int m) {
    Int res = 0;
    FOR(i,1,n + m + 1)
        if (n % i + m % i >= i)
            res += d[i];
    return res;
}

Int get_D(int n) {
    if (n < MAX)
        return D[n];
    Int res = 0;
    int l = 1;
    int r = 1;
    while (l <= n) {
        Int y = n / l;
        r = n / y + 1;
        res += y * (r - l);
        l = r;
    }
    return res;
}

Int F(int n) {
    Int res = 0;
    int r = 1;
    int l = 1;
    while (l <= n) {
        Int y = n / l;
        r = n / y + 1;
        res += (get_D(r - 1) - get_D(l - 1)) * y;
        l = r;
    }
    return res;
}

int main() {
ios::sync_with_stdio(0);
cin.tie(0);


    for(int i = 2; i * i < MAX; ++i)
        if (!p[i])
            for(int j = i * i; j < MAX; j += i)
                if (!p[j])
                    p[j] = i;

    FOR(i,1,MAX)
        if (!p[i])
            p[i] = i;
   
    d[1] = 1;
    FOR(i,2,MAX)
    {
        int x = i;
        int c = 0;
        while (x % p[i] == 0)
        {
            x /= p[i];
            ++ c;
        }
        d[i] = d[x] * (c + 1);
    }
    D[1] = d[1];
    FOR(i,2,MAX)
        D[i] = D[i - 1] + d[i];

    int n , m;
    cin >> n >> m;

    Int res = F(n + m) - F(n) - F(m);

    cout << res << endl;

    cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
return 0;
}
