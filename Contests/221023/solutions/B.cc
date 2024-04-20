#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:16777216")
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <cassert>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
#include <time.h>
#include <complex>
using namespace std;

#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define RFOR(i, b, a) for(int i=(b)-1;i>=(a);--i)
#define FILL(A,value) memset(A,value,sizeof(A))

#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define Pi 3.14159265358979
#define x0 ikjnrmthklmnt
#define y0 lkrjhkltr
#define y1 ewrgrg

typedef long long Int;
typedef unsigned long long UInt;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef pair<Int, Int> PLL;
typedef pair<double, double> PDD;
typedef complex<double> base;

const int INF = 1000000000;
const int BASE = 1000000007;
const int MAX = 2007;
const int MAX2 = 47;
const int MAXE = 100000;
const int ADD = 1000000;
const int MOD = 1008691207;
const int CNT = 800;

double dp[MAX][MAX];
double pw[MAX];

double bpow(double a, int k)
{
    double res = 1;
    while(k)
    {
        if (k & 1)
        {
            res *= a;
        }
        a *= a;
        k /= 2;
    }
    return res;
}

int main()
{
    //    freopen("in.txt", "r", stdin);
    //freopen("distance.in",  "r", stdin);
    //freopen("distance.out", "w", stdout);
    //freopen("out.txt" , "w" , stdout);
    
    int n , m;
    double p;
    cin >> n >> m >> p;
    
    swap(m, n);
    
    FOR(k,0,n + 1)
    {
        dp[0][k] = 1;
        
        FOR(i,1,n + 1)
        {
            dp[i][k] = dp[i - 1][k];
            if (i == k + 1)
            {
                dp[i][k] -= bpow(p, k + 1);
            }
            if (i > k + 1)
            {
                dp[i][k] -= bpow(p, k + 1) * (1 - p) * dp[i - (k + 2)][k];
            }
        }
    }
    
    double res = 0;
    
    FOR(i,1,n + 1)
    {
        res += i * (bpow(dp[n][i] , m) - bpow(dp[n][i - 1] , m));
    }
    
    printf("%.12f\n" , res);
    
    
    return 0;
}





