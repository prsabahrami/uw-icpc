#include <string>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string.h>
#include <utility>
#include <queue>
#include <stack>
#include <iomanip>
#include <ctype.h>
#include <map>
#include <set>
#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <sstream>
#include <math.h>
#include <time.h>
#include <iostream>
#include <iomanip>
#include <unordered_set>
#include <unordered_map>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <list>

using namespace std;

typedef long long LL;

#define FOR(i,n) for(int i = 0;i < n;i++)
#define MP make_pair
#define PB push_back
#define ALL(a) (a).begin(),(a).end()
#define PII pair<int, int>
#define PLL pair<long long, long long>
#define ERASE(a) memset(a, -1, sizeof(a))
#define CLEAR(a) memset(a, 0, sizeof(a))
#define INF 2000000007
#define y1 uu1
#define y2 uu2
#define hash mash
const double EPS = 1E-9;
const double PI = acos(-1.0);
const LL mod = 1000000007;

const PII dir[] = {MP(1, 0), MP(-1, 0), MP(0, 1), MP(0, -1)};
const char pc[] = {'L', 'R', 'U', 'D'};

using namespace std;

int nc,ns,x;
int c[1000];

vector<int> ans[10000];


int main() {
  ios::sync_with_stdio(false);

  cin >> nc >> ns;

  FOR(i, nc) {
    cin >> c[i];
  }

  int sum = 0;
  FOR(i, ns) {
    FOR(j, 5) {
      cin >> x;
      if (c[x-1]) {
        sum++;
        c[x-1]--;
        ans[i].push_back(x);
      }
    }
  }

  cout << sum << endl;
  FOR(i, ns) {
    FOR(j, ans[i].size()) {
      if (j) {
        cout << ' ';
      }
      cout << ans[i][j];
    }
    cout << endl;
  }

  return 0;
}
