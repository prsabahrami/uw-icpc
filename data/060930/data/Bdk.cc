#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int c[100000][2];

main() {
  int i, j, k, x, y, z, n, N;

  for( cin >> N; N; N-- ) {
    cin >> n;
    vector<pair<pair<int, int>, int> > v(n);
    for( i = 0; i < n; i++ ) {
      cin >> v[i].first.first >> v[i].first.second;
      v[i].second = i;
    }
    if( n%2 ) goto fail;
    z = 0;
    for( int rep = 0; rep < 2; rep++ ) {
      sort(v.begin(), v.end());
      for( i = 0; i < n; i += 2 ) {
        if( v[i].first.first != v[i+1].first.first ) goto fail;
        z += abs(v[i].first.second - v[i+1].first.second);
        c[v[i].second][rep] = v[i+1].second;
        c[v[i+1].second][rep] = v[i].second;
      }
      for( i = 0; i < n; i++ ) swap(v[i].first.first, v[i].first.second);
    }
    x = 0; y = -1;
    for( i = 0; i < n; i++ ) {
      if( c[x][0] != y ) {
        y = x; x = c[x][0];
      } else {
        y = x; x = c[x][1];
      }
      if( x == 0 ) break;
    }
    if( i != n-1 ) goto fail;
    cout << z << endl;
    continue;
fail:
    cout << -1 << endl;
  }
}
