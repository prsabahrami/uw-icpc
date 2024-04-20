#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    string s,t;
    cin >> s >> t;
    bool good = false;
    int startIdx = (s.length() - t.length()) / 2;

    if (s.length() == t.length()) {
      good = s == t;
    } else if ((s.length() - t.length()) % 2) {
      good = s.substr(startIdx, t.length()) == t && s.substr(startIdx + 1, t.length()) == t;
    } else {
      good = s.substr(startIdx, t.length()) == t ||
        (s.substr(startIdx - 1, t.length()) == t && s.substr(startIdx + 1, t.length()) == t);
    }

    if (good) {
      cout << "Alice" << endl;
    } else {
      cout << "Bob" << endl;
    }
  }
  return 0;
}
