#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

vector<pair<int, bool> > implications[30][2];  // T = w, F = h
int val[30], val2[30];

bool doit(int n, int v) {
  if (val[n] != -1) return val[n] == v;
  val[n] = v;
  vector<pair<int, bool> >& imp = implications[n][v];
  for (int i = 0; i < imp.size(); i++)
    if (!doit(imp[i].first, imp[i].second)) return false;
  return true;
}

main() {
  int N, M;
  while (cin >> N >> M && N) {
    for (int i = 0; i < N; i++)
    for (int j = 0; j < 2; j++)
      implications[i][j].clear();
    for (int i = 0; i < M; i++) {
      char a, b;
      int an, bn;
      cin >> a >> an >> b >> bn;
      implications[an-1][a=='h'].push_back(make_pair(bn-1, b=='w'));
      implications[bn-1][b=='h'].push_back(make_pair(an-1, a=='w'));
    }
    memset(val, -1, sizeof(val));
    for (int i = 0; i < N; i++) if (val[i] == -1) {
      memcpy(val2, val, sizeof(val));
      if (!doit(i, 0)) {
        memcpy(val, val2, sizeof(val));
        if (!doit(i, 1)) goto fail;
      }
    }
    for (int i = 0; i < N; i++) {
      if (i) cout << ' ';
      cout << (val[i] ? 'w' : 'h') << i+1;
    }
    cout << endl;
    continue;
fail:
    cout << "bad luck" << endl;
  }
}
