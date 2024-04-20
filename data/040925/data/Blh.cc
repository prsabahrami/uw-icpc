#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

void subst( vector<string>& v, string pat, string replace )
{
    for( int i = 0; i < v.size(); i++ ) if( v[i] == pat ) v[i] = replace;
}

int main()
{
    int N; string a, b;
    cin >> N;
    getline(cin, a);
    while( N-- ) {
        getline(cin, a);
        getline(cin, b);
        vector<string> pata, patb;
        { istringstream is(a); while( is >> a ) pata.push_back(a); }
        { istringstream is(b); while( is >> b ) patb.push_back(b); }
        if( pata.size() != patb.size() ) goto bad;
again:;
        for( int i = 0; i < pata.size(); i++ ) {
            if( pata[i][0] == '<' && patb[i][0] != '<' ) {
                subst(pata, pata[i], patb[i]);
                goto again;
            }
            if( patb[i][0] == '<' && pata[i][0] != '<' ) {
                subst(patb, patb[i], pata[i]);
                goto again;
            }
        }
        for( int i = 0; i < pata.size(); i++ ) {
            if( pata[i][0] == '<' && patb[i][0] == '<' ) {
                subst(pata, pata[i], "a");
                subst(patb, patb[i], "a");
                goto again;
            }
        }
        if( pata != patb ) goto bad;
        for( int i = 0; i < pata.size(); i++ ) cout << (i?" ":"") << pata[i];
        cout << '\n';
        continue;
bad:;
        cout << "-\n";
    }
}

