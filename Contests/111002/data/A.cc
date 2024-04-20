#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 100100;
int n;
int ans1, ans2;
int c[MAXN];
vector<pair<int,int> > e[MAXN];

void moo(int p, int d, int pa) {
	ans2 = min(ans2, c[p] - d);
	for(int i = 0; i < e[p].size(); ++i) {
		if(e[p][i].first != pa) {
			moo(e[p][i].first, d + e[p][i].second, p);
		}
	}
}

int main() {
	scanf("%d", &n);
	n++;
	for(int i = 0; i < n; ++i) {
		scanf("%d", &c[i]);
	}
	ans1 = 0;
	ans2 = 1<<30;
	for(int i = 0; i < n - 1; ++i) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		e[a].push_back(make_pair(b, c));
		e[b].push_back(make_pair(a, c));
		ans1 += c * 2;
	}
	moo(0, 0, 0);
	printf("%d\n", ans1 + ans2);
	return 0;
}

