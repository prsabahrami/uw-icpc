#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int tcase, n, m, E[100010][2];
vector<int> ans;

vector<int> e[100010], v[100010];
bool ok, vis[100010];
int root[100010];

int findroot(int x) {
    if (root[x] != x) root[x] = findroot(root[x]);
    return root[x];
}

void dfs(int sn, int fa) {
    vis[sn] = true;
    for (int i = 0; i < e[sn].size(); i++) {
        int fn = e[sn][i];
        if (fn == fa) continue;
        ans.push_back(v[sn][i]);
        if (vis[fn]) { ok = true; return; }
        dfs(fn, sn);
        if (ok) return;
        ans.pop_back();
    }
    vis[sn] = false;
}

int main() {
    scanf("%d", &tcase);
    while (tcase--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; i++) scanf("%d%d", &E[i][0], &E[i][1]);

        ans.clear(); ok = false;
        for (int i = 1; i <= n; i++) e[i].clear(), v[i].clear(), vis[i] = false, root[i] = i;
        for (int i = 1; i <= m; i++) {
            int sn = E[i][0], fn = E[i][1];
            e[sn].push_back(fn); v[sn].push_back(i);
            e[fn].push_back(sn); v[fn].push_back(i);
            int x = findroot(sn), y = findroot(fn);
            if (x == y) {
                dfs(sn, 0);
                sort(ans.begin(), ans.end());
                for (int i = 0; i < ans.size(); i++) printf("%d%c", ans[i], "\n "[i + 1 < ans.size()]);
                goto DONE;
            }
            root[x] = y;
        }
        printf("-1\n"); continue;
        DONE: continue;
    }
    return 0;
}
