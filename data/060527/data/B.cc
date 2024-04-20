#include <iostream>
#include <string>
#include <assert.h>
#include <map>

#define MAXN 1000000

using namespace  std;

string cards[MAXN][60];
int next[MAXN], last[MAXN];

int main () {
  while (1) {
    int n, m;
    cin >> n;
    if (!n) break;
    for (int i=0;i<n;i++) {
      cin >> m;
      assert(m);
      for(int j=0;j<m;j++) {
	cin >> cards[i][j];
	string c = cards[i][j];
	assert(c[0] == 'A' || c[0] == '2' || c[0] == '3' || c[0] == '4' ||
	       c[0] == '5' || c[0] == '6' || c[0] == '7' || c[0] == '8' ||
	       c[0] == '9' || c[0] == '1' || c[0] == 'J' || c[0] == 'Q' ||
	       c[0] == 'K' );
	if (c[0] == '1') {
	  assert(c[1] == '0');
	  assert(c[2] == 'C' || c[2] == 'D' || c[2] == 'H' || c[2] == 'S');
	} else 
	  assert(c[1] == 'C' || c[1] == 'D' || c[1] == 'H' || c[1] == 'S');
      }
      last[i] = m-1;
      next[i] = 0;
    }
    int ans = 0;
    bool cont;
    map<pair<string,int>,int> s;
    do {
      cont = false;
      for(int i=0; i<n;i++) {
	if (last[i] != -1) 
	  cont = true;
	else continue;
	if (!s[make_pair(cards[i][last[i]],next[i])]) {
	  s[make_pair(cards[i][last[i]],next[i])] = ++ans;
	  next[i] = ans;
	} else {
	  next[i] = s[make_pair(cards[i][last[i]],next[i])];
	}
	last[i]--; 
      }
    } while (cont);
    cout << s.size() << '\n';
  }
}
