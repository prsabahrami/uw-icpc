#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <queue>
#include <tuple>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    assert(1 <= n && n <= 1000);
    assert(1 <= m && m <= 1000);
    vector<string> M(n);;
    for (int i = 0; i < n; ++i) {
        cin >> M[i];
        assert(M[i].size() == m);
    }
    vector<vector<bool> > visited(n, vector<bool>(m, false));
    vector<vector<int> > dist(n, vector<int>(m, 10000));
    deque<pair<int, int> > Q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (M[i][j] == 'W') {
                Q.push_back(make_pair(i, j));
                dist[i][j] = -1;
            }
        }
    }
    while (Q.size() > 0) {
        int i, j;
        tie(i, j) = Q.front(); Q.pop_front();
        if (visited[i][j]) continue;
        visited[i][j] = true;
        char from = M[i][j];
        for (int di = -1; di <= 1; ++di) for (int dj = -1; dj <= 1; ++dj) if (i+di >= 0 && i+di < n && j+dj >= 0 && j+dj < m) {
            char to = M[i+di][j+dj];
            if (from == to) {
                dist[i+di][j+dj] = min(dist[i+di][j+dj], dist[i][j]);
                Q.push_front(make_pair(i+di, j+dj));
            } else {
                dist[i+di][j+dj] = min(dist[i+di][j+dj], dist[i][j]+1);
                Q.push_back(make_pair(i+di, j+dj));
            }
        }
    }
    int val[26];
    for (int c = 0; c < 26; ++c) {
        val[c] = 10000;
    }
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) val[M[i][j]-'A'] = min(val[M[i][j]-'A'], dist[i][j]);
    for (int c = 0; c < 26; ++c) {
        if (val[c] >= 0 && val[c] < 10000) {
            cout << char('A' + c) << " " << val[c] << endl;
        }
    }
}
