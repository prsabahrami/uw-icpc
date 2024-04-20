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
#include <fstream>
#include <time.h>

#include "testlib.h"

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

const int INF = 1000000000;
const int BASE = 1000000007;
const int MAX = 100007;
const int MAX2 = 10007;
const int MAXE = 100000;
const int ADD = 1000000;
const int MOD = 1000000007;
const int CNT = 0;

VI G[MAX];
VI GR[MAX];

VI order;
bool U[MAX];
int C[MAX];

void dfs1(int v) {
    U[v] = true;
    for(int to: G[v]) {
        if (U[to])
            continue;
        dfs1(to);
    }
    order.push_back(v);
}   

void dfs2(int v, int c) {
    U[v] = true;
    C[v] = c;
    for(int to: GR[v]) {
        if (U[to])
            continue;
        dfs2(to, c);
    }
}  

vector<PII> GG[MAX];
int V[MAX];

void dfs(int v) {
    U[v] = true;
    for(auto p: GG[v]) {
        int to = p.first;
        int l = p.second;
        if (U[to]) {
            if (V[to] != V[v] + l)
                quitf(_wa, "Mismatch for cycle: %d != %d", V[to], V[v] + l);
        } else {
            V[to] = V[v] + l;
            dfs(to);
        }
    }
}

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    
    try{

        
        int n , m;
        n = inf.readInt();
        m = inf.readInt();
        vector<PII> E;
        FOR(i,0,m) {
            int a = inf.readInt();
            int b = inf.readInt();
            -- a; -- b;
            E.push_back(MP(a, b));
            G[a].push_back(b);
            GR[b].push_back(a);
        }

        FILL(U, 0);
        FOR(i,0,n)
            if (!U[i])
                dfs1(i);
        FILL(U, 0);
        int col = 0;
        FOR(i,0,n) {
            int v = order[n - 1 - i];
            if (!U[v]) {
                dfs2(v, col);
                ++ col;
            }
        }

        FOR(i,0,m) {
            int l = ouf.readInt(-1000, 1000, "wire current strength");
            int a = E[i].first;
            int b = E[i].second;
            if (C[a] == C[b]) {
                GG[a].push_back(MP(b, l));
                GG[b].push_back(MP(a, -l));
            }
        }

        FILL(U, 0);
        FOR(i,0,n)
            if (!U[i])
                dfs(i);
    }
    catch (...){
        quitf(_fail, "Checker failed with exception");
    }
    quitf(_ok, "good one");
    return 0;
}
