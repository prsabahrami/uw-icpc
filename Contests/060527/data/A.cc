#include <iostream>
#include <assert.h>

using namespace std;

int main () {
  int c, fl, m, ;
  cin >> c;
  while (c--) {
    cin >> fl >> m;
    fl *= 100;
    int lc = 0, rc = 0, cll = 0, crl = 0;
    while (m--) {
      int l;
      string s;
      cin >> l >> s;
      assert (l <= fl);
      assert(s == "left" || s == "right");
      if (s == "left") 
	cll+l <= fl ? cll += l : (lc++, cll = l);
      else crl+l <= fl ? crl += l : (rc++, crl = l);
    }
    if (cll) lc++;
    if (crl) rc++;
    cout << (lc <= rc ? 2*rc : 2*lc-1) << '\n';	
  }
}
