#include<stdio.h>
#include<algorithm>
#include<assert.h>
#define N 1000005
#define M 4000005
using namespace std;
 
vector<pair<int, int> >a[N];
int dfn[N], deep[N], depth[N], ver[N], f[N], Log[N];
long long dist[N]; int dp[22][N];
int opt[N], u[N], v[N], col[N], n, m, tot;
 
void DFS(int x){
	ver[dfn[x] = ++tot] = x;
	deep[tot] = depth[x];
	for (auto pa: a[x])
	    if (pa.first != f[x]){
	    	int y = pa.first; 
			dist[y] = dist[x] + pa.second;
			depth[y] = depth[x] + 1;
			f[y] = x; DFS(y);
			ver[++tot]=x;
			deep[tot] = depth[x];
	    }
}
 
void RMQ_init(){
	for (int i = 1; (1 << i) <= tot; i++) Log[1 << i] = i;
	for (int i = 2; i <= tot;i++) if (!Log[i]) Log[i] = Log[i-1];
	for (int i = 1; i <= tot; i++) dp[0][i] = i;
	for (int k = 1; (1 << k) <= tot; k++)
		for (int i = 1; i <= tot - (1 << k) + 1; i++)
			dp[k][i] = deep[dp[k-1][i]] < deep[dp[k-1][i + (1 << k-1)]] ? dp[k-1][i] : dp[k-1][i + (1 << k-1)];
}
 
long long calc(int u, int v){ 
	int x = dfn[u], y = dfn[v];
	if (x > y) swap(x, y);
	int k = Log[y - x + 1];
	int ret1 = dp[k][x];
	int ret2 = dp[k][y - (1 << k) + 1];
	int lca = ver[deep[ret1] < deep[ret2] ? ret1 : ret2];
	//printf("%d %d %d %lld\n", u, v, lca, dist[u] + dist[v] - 2 * dist[lca]);
	return dist[u] + dist[v] - 2 * dist[lca];
}
 
int pairx_[M], pairy_[M], *pairx, *pairy;
long long sum_[M], only_[M], *sum, *only, ans;
vector<int>vec[N]; bool get_ans;
int rt[N], allocate;
 
void build(int x, int l, int r, int &mx){
	pairx[x] = pairy[x] = sum[x] = only[x] = 0;
	mx = max(mx, x);
	if (l == r) return;	
	int mid = (l + r) >> 1;
	build(x << 1, l, mid, mx);
	build(x << 1 | 1, mid + 1, r, mx);
}
 
void up(int x, int l, int r){
	int p[2] = {pairx[l], pairy[l]};
	int q[2] = {pairx[r], pairy[r]};
	if (sum[l] > sum[r] || sum[l] == sum[r] && p[0] > 0) 
		sum[x] = sum[l], pairx[x] = pairx[l], pairy[x] = pairy[l];
	else 
		sum[x] = sum[r], pairx[x] = pairx[r], pairy[x] = pairy[r];
	only[x] = max(only[l], only[r]);
	if (!p[0] || !q[0]) return;
	for (int _1 = 0; _1 < 2; _1++)
		for (int _2 = 0; _2 < 2; _2++){
			auto dis = calc(p[_1], q[_2]);
			if (dis > only[x]) only[x] = dis;
			if (dis > sum[x]){
				sum[x] = dis;
				pairx[x] = p[_1];
				pairy[x] = q[_2];
			}
		}
}
 
void update(int x, int l, int r, int pos, int id1, int id2){
	if (l == r){
		pairx[x] = id1;
		pairy[x] = id2;
		sum[x] = (!id1 || !id2 || id1 == id2) ? 0 : calc(id1, id2);
		only[x] = 0;
		return;
	}
	int mid = (l + r) >> 1;
	if (pos <= mid){
		update(x << 1, l, mid, pos, id1, id2);
	} else {
		update(x << 1 | 1, mid + 1, r, pos, id1, id2);
	}
	up(x, x << 1, x << 1 | 1);
}
 
long long solve(int col, int id){
	pairx = pairx_ + rt[col];
	pairy = pairy_ + rt[col];
	sum = sum_ + rt[col];
	only = only_ + rt[col];
	update(1, 1, vec[col].size(), lower_bound(vec[col].begin(), vec[col].end(), abs(id)) - vec[col].begin() + 1, id * (id > 0), id * (id > 0));
	pairx = pairx_ + allocate;
	pairy = pairy_ + allocate;
	sum = sum_ + allocate;
	only = only_ + allocate;
	update(1, 1, m, col, pairx_[rt[col] + 1], pairy_[rt[col] + 1]);
	return only[1];
}
 
int main(){
	int Test;
	scanf("%d", &Test);
	while (Test--){
		scanf("%d%d", &m, &col[1]);
		vec[col[1]].emplace_back(1);
		n = 1;
		for (int i = 1; i <= m; i++){
			scanf("%d%d", &opt[i], &u[i]);
			if (opt[i] == 0){
				++n;
				int d;
				scanf("%d%d", &col[n], &d);
				vec[col[n]].emplace_back(n);
				a[u[i]].emplace_back(make_pair(n, d));
			} else {
				scanf("%d", &v[i]);
				vec[v[i]].emplace_back(u[i]);
			}
		}
		tot = 0;
		depth[1] = 1;
		DFS(1);
		RMQ_init();
		allocate = 0;
		for (int i = 1; i <= m; i++){
			if (!vec[i].empty()){
				sort(vec[i].begin(), vec[i].end());
				vec[i].erase(unique(vec[i].begin(), vec[i].end()), vec[i].end());
				rt[i] = allocate;
				pairx = pairx_ + rt[i];
				pairy = pairy_ + rt[i];
				sum = sum_ + rt[i];
				only = only_ + rt[i];
				int mx = 1;
				build(1, 1, vec[i].size(), mx);
				allocate += mx;
				assert(allocate + m < M);
			}
		}
		pairx = pairx_ + allocate;
		pairy = pairy_ + allocate;
		sum = sum_ + allocate;
		only = only_ + allocate;
		int mx = 1;
		build(1, 1, m, mx);
		solve(col[1], +1);
		tot = 1;
		for (int i = 1; i <= m; i++){
			if (opt[i] == 0){
				++tot;
				printf("%lld\n", solve(col[tot], tot));
			} else {
				solve(col[u[i]], -u[i]);
				printf("%lld\n", solve(col[u[i]] = v[i], +u[i]));
			}
		}
		for (int i = 1; i <= n; i++){
			a[i].clear();
		}
		for (int i = 1; i <= m; i++){
			vec[i].clear();
		}
	}
}
 
