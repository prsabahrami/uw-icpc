#include <iostream>
#include <string>
using namespace std;

int nc[256];

main() {
  int i, x;
  string s;
  while( cin >> s && s != "0" ) {
    memset(nc, 0, sizeof(nc));
    for( i = 0; i < s.size(); i++ ) nc[s[i]]++;
    int nvar = nc['p']+nc['q']+nc['r']+nc['s']+nc['t'];
    if( nvar == 0 ) {
      cout << "no WFF possible" << endl;
      continue;
    }
    for( i = 0; i < nc['N']; i++ ) cout << 'N';
    x = 1;
    for( i = 0; i < nc['K'] && x+1 <= nvar; i++, x++ ) cout << 'K';
    for( i = 0; i < nc['A'] && x+1 <= nvar; i++, x++ ) cout << 'A';
    for( i = 0; i < nc['C'] && x+1 <= nvar; i++, x++ ) cout << 'C';
    for( i = 0; i < nc['E'] && x+1 <= nvar; i++, x++ ) cout << 'E';
    for( i = 0; i < nc['p'] && x; i++, x-- ) cout << 'p';
    for( i = 0; i < nc['q'] && x; i++, x-- ) cout << 'q';
    for( i = 0; i < nc['r'] && x; i++, x-- ) cout << 'r';
    for( i = 0; i < nc['s'] && x; i++, x-- ) cout << 's';
    for( i = 0; i < nc['t'] && x; i++, x-- ) cout << 't';
    cout << endl;
  }
}
