#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int N, i, j, ret;
string s;

int main()
{
    cin >> N;
    while( N-- ) {
        cin >> s;
        for( ret = i = 0; i < s.size()/2; i++ ) {
            for( j = s.size()-1-i; j > i && s[j] != s[i]; j-- );
            if( i == j ) { 
                if( s.size()%2==0 ) { cout << "Impossible\n"; goto oot; }
                ret += s.size()/2-i; 
                s.erase(i--, 1);
            } else for( ; j < s.size()-1-i; j++ ) {
                swap(s[j], s[j+1]);
                ret++;
            }
        }
        cout << ret << '\n';
oot:;
    }
}

