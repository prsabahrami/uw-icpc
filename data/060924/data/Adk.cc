#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

main() {
  int i, j, k, x, y, z, n, prob=0;

  while( cin >> n && n ) {
    vector<int> b(n);
    for( i = 0; i < n; i++ ) cin >> b[i];
    sort(b.begin(), b.end());
    for( i = z = 0; i < n; i = j) {
      for( j = i+1; j < n && b[j] == b[i]; j++ );
      z >?= j-i;
    }
    if( prob++ ) cout << endl;
    cout << z << endl;
    for( i = 0; i < z; i++ ) {
      for( j = i; j < n; j += z ) {
        if( j > i ) cout << ' ';
        cout << b[j];
      }
      cout << endl;
    }
  }
}
