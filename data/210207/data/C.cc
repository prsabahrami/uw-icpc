#include <bits/stdc++.h>

using namespace std;

int main() {
    int P, W, N, index, pcount, wcount;
    pcount = 0;
    wcount = 0;
    char dir;
    cin >> P >> W >> N;
    for (int i=0; i<N; i++) {
        cin >> dir >> index;
        if (dir == 'P') {
            pcount++;
        } else {
            wcount++;
        }
    }
    cout << wcount*W+pcount*P-pcount*wcount << endl;
}
