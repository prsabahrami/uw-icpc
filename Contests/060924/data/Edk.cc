#include <iostream>
#include <string>
#include <vector>
using namespace std;

int memo[101][101];
string a, b;
int similarity(int ap, int bp) {
  int &ret = memo[ap][bp];
  if( ret != -1 ) return ret;
  if( ap == a.size() || bp == b.size() ) return 0;
  if( a[ap] == b[bp] ) return ret = 1+similarity(ap+1, bp+1);
  return ret = similarity(ap+1, bp) >? similarity(ap, bp+1);
}

bool seen[201][201];

main() {
  int i, j, k, x, y, z, n;

  for(;;) {
    getline(cin, a); getline(cin, b);
    if( a == "0" && b == "0" ) break;
    if( !a.size() || !b.size() ) {
      if( !a.size() && !b.size() )
        cout << 1 << endl;
      else
        cout << "not related" << endl;
      continue;
    }
    memset(memo, -1, sizeof(memo));
    memset(seen, 0, sizeof(seen));
    vector<pair<int, int> > q;
    x = similarity(0, 0);
    q.push_back(make_pair(x, a.size()-x));
    n = 0;
    while( !q.empty() ) {
      vector<pair<int, int> > q2;
      while( !q.empty() ) {
        x = q.back().first; y = q.back().second; q.pop_back();
        if( x == b.size() && y == 0 ) goto done;
        z = (x+y)*2 <? 200;
        for( int p = 0; p <= z; p++ )
        for( int q = 0; p+q <= z; q++ )
        if( !seen[p][q] ) {
          int sim = p <? x, nsim = q <? y;
          if( (sim+nsim)*2 >= p+q && (sim+nsim)*2 >= x+y ) {
            seen[p][q] = true;
            q2.push_back(make_pair(p, q));
          }
        }
      }
      q = q2; n++;
    }
done:
    cout << (n >? 1) << endl;
  }
}
