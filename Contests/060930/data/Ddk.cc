#include <iostream>
#include <string>
using namespace std;

string s;
int vval;

int eval(int &x) {
  char ch = s[x++];
  if( islower(ch) ) return (vval>>(ch-'p'))&1;
  if( ch == 'N' ) return !eval(x);
  int v1 = eval(x), v2 = eval(x);
  if( ch == 'K' ) return v1 & v2;
  if( ch == 'A' ) return v1 | v2;
  if( ch == 'C' ) return !v1 | v2;
  if( ch == 'E' ) return v1 == v2;
}

main() {
  int x;
  while( cin >> s && s != "0" ) {
    for( vval = 0; vval < 32; vval++ )
      if( !eval(x=0) ) break;
    if( vval < 32 ) cout << "not" << endl; else cout << "tautology" << endl;
  }
}
