/**
 * CTU Open 2017
 * Problem Solution: Northwest
 * Idea: Count how many lines can be formed on each diagonal and divide it by
 *       total number of ways to select two points
 * @author Roman Jelinek
 */
 
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9+7;

int main( ) {
    int  n, x, y;

    while (scanf("%d", &n) == 1) {
        map<int,int> diag1, diag2;
        long         res = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &x, &y);
            int d1 = x + y;
            int d2 = x - y;
            res += diag1[d1];
            res += diag2[d2];
            ++diag1[d1];
            ++diag2[d2];
        }
        printf("%.8f\n", 2.0 * res / n / n);
    }
    return 0;
}
