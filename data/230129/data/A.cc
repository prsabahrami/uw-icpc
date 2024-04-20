#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 1e6 + 10;
const int MM = 1e9 + 7;

int a[111][111];

void solve(int casi){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (i & 1) {
            for (int j = 1; j <= n; j++) ans.emplace_back(a[i][j]);
        }
        else {
            for (int j = n; j >= 1; j--) ans.emplace_back(a[i][j]);
        }
    }
    int pos = 0, neg = 0;
    for (int i = 1; i < ans.size(); i++) {
        if (ans[i] < ans[i - 1]) 
            pos++;
        else
            neg++;
    }
    if (pos < neg) {
        reverse(ans.begin(), ans.end());
    }
    for (int i = 0; i < ans.size(); i++) {
        printf("%d%c", ans[i], " \n"[i + 1 == ans.size()]);
    }
}

int main(){
    int T = 1;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++)
        solve(i);
    return 0;
}
