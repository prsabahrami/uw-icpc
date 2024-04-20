#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define fu(i,n) for( int i = 0; i < (n); i++ )
typedef long long i64;

i64 gcd( i64 a, i64 b ) { return !b ? a : gcd(b, a%b); }
i64 lcm( i64 a, i64 b ) { return a/gcd(a,b)*b; }

int n, t;
i64 coin[100];
vector<i64> lcms;

int main()
{
    while( cin >> n >> t && (n+t) ) {
        lcms.clear();
        fu(i,n) cin >> coin[i];
        fu(i,n) fu(j,i) fu(k,j) fu(l,k) {
            lcms.push_back(lcm(lcm(lcm(coin[i],coin[j]),coin[k]),coin[l]));
        }
        fu(i,t) {
            i64 targ; 
            i64 low = -1;
            i64 high = INT_MAX;
            cin >> targ;
            fu(j,lcms.size()) {
                i64 x = targ - (targ%lcms[j]);
                low >?= x;
                high <?= x + lcms[j];
            }
            if( low == targ ) high = targ;
            cout << low << ' ' << high << '\n';
        }
    }
}

