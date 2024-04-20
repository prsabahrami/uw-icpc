#include <iostream>
#include <vector>
using namespace std;

int best[2001][2001];

main() {
  int i, j, k, x, y, z, x2, y2, n;

  while( cin >> n && n ) {
    vector<pair<int, int> > q;
    memset(best, 63, sizeof(best));
    for( j = 0; j < n; j++ ) {
      cin >> x >> y;
      q.push_back(make_pair(x, y));
    }
    cin >> n;
    for( j = 0; j < n; j++ ) {
      cin >> x >> y;
      best[y][x] = 1000000;
    }
    n = 0;
    for(;;) {
      vector<pair<int, int> > q2;
      while( !q.empty() ) {
        x = q.back().first; y = q.back().second; q.pop_back();
        if( x < 0 || x > 2000 || y < 0 || y > 2000 || n >= best[y][x] )
          continue;
        if( best[y][x] == 1000000 ) goto done;
        best[y][x] = n;
        q2.push_back(make_pair(x+1, y));
        q2.push_back(make_pair(x-1, y));
        q2.push_back(make_pair(x, y+1));
        q2.push_back(make_pair(x, y-1));
      }
      q = q2; n++;
    }
done:
    cout << n << endl;
  }
}
