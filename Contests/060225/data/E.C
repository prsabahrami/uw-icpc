#include <iostream>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

int main () {
  int n, h, t;
  set<string> W;
  cin >> n;
  for(int i=0;i<n;i++) {
    string s;
    cin >> s;
    sort(s.begin(),s.end());
    W.insert(s);
  }
  cin >> h;
  while(h--) {
    cin >> t;
    char C[20];
    int v[20];
    for(int i=0;i<t;i++) cin >> C[i] >> v[i];
    int maxv = 0;
    for(int b=0;b<(1<<t);b++) {
      string s;
      int cval = 0;
      for(int i=0;i<t;i++)
	if (b & (1<<i)) {
	  cval += v[i];
	  s += C[i];
	}
      sort(s.begin(),s.end());
      if (W.count(s) && cval > maxv) maxv = cval;
    }
    printf("%d\n",maxv);
  }
}
