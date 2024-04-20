#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define RFOR(i,b,a) for (int i = (b) - 1; i >= (a); i--)
#define ITER(it,a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a,value) memset(a, value, sizeof(a))

#define SZ(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000 + 7;
const LL LINF = INF * (LL) INF;

const int MARG = 320;
const int MAX = 200200;

VI g[MAX];
PII E[MAX];

int C[MAX];


int main(int argc, char* argv[])
{
	//ios::sync_with_stdio(false); cin.tie(0);

	int n, m;
	scanf("%d%d", &n, &m);

	FOR (i, 0, m)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;

		g[x].PB(y);
		g[y].PB(x);
		E[i] = MP(x, y);
	}

	FILL(C, -1);
	int mx = 1000;

	FOR (i, 0, n)
	{
		if (SZ(g[i]) > MARG)
		{
			C[i] = mx;
			mx--;
		}
		else
		{
			set<int> s;
			FOR (j, 0, SZ(g[i]))
			{
				int to = g[i][j];
				if (C[to] == -1) continue;
				s.insert(C[to]);
			}

			int c = -1;
			FOR (j, 0, INF)
			{
				if (s.count(j) == 0)
				{
					c = j;
					break;
				}
			}

			C[i] = c;
		}
	}

	FOR (i, 0, m)
	{
		int x = E[i].first;
		int y = E[i].second;

		int res = C[x] - C[y];
		printf("%d\n", res);
	}
}


