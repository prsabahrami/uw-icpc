#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a%b);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int a, b, d;
        cin >> a >> b >> d;
        assert(1 <= a && a <= 10000000);
        assert(1 <= b && b <= 10000000);
        assert(d <= max(a, b));
        bool can = d >= 0 && d % gcd(a,b) == 0;
        cout << (can ? "Yes" : "No") << endl;
    }
}
