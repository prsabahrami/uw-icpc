#include <cstdio>
#include <iostream>
using namespace std;

main() {
  int d;
  while (cin >> d && d) {
    long long maxcan = 100000, maxus = 0;
    while (d--) {
      double rate;
      cin >> rate;
      maxus >?= (long long)((maxcan / rate) * 0.97 + 1e-6);
      maxcan >?= (long long)((maxus * rate) * 0.97 + 1e-6);
    }
    printf("%0.2lf\n", maxcan / 100.0);
  }
}
