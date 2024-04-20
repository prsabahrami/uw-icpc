#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int T, L, N;

int main()
{
    cin >> T;
    while( T-- ) {
        cin >> L >> N;
        int lo = 0, hi = 0, x;
        for( int i = 0; i < N; i++ ) {
            cin >> x;
            lo >?= x <? L-x;
            hi >?= x >? L-x;
        }
        cout << lo << ' ' << hi << '\n';
    }

}

