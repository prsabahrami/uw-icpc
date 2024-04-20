#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

const int NSTEPS = 50000;

int N, chosen[100];
pair<double,int> kg[100];
double sum, target, threshold, psum[101];

void go( int p, double wt )
{
    if( p-- == 0 ) return;
    if( fabs(target-wt) <= threshold ) {
//        printf("target=%lf, wt=%lf, diff=%lf\n",target,wt,fabs(target-wt));
        for( int i = 0, f = 0; i < N; i++ ) if( chosen[i] ) {
            if( f++ ) cout << ' ';
            cout << (kg[i].second+1);
        }
        cout << '\n';
        throw -1;
    }
    if( wt-target > threshold ) return;
    if( wt+psum[p+1] < target-threshold ) return;

    chosen[p] = 1;
    go(p, wt+kg[p].first);
    chosen[p] = 0;
    go(p, wt);
}

int main()
{
    while( cin >> N && N ) {
        memset(chosen, 0, sizeof(chosen));
        sum = 0;
        for( int i = 0; i < N; i++ ) { cin >> kg[i].first; sum += kg[i].first; kg[i].second=i; }
        sort(kg, kg+N);
        psum[0] = 0;
        for( int i = 0; i < N; i++ ) psum[i+1] = psum[i] + kg[i].first;
        target = sum/2;
        threshold = target*0.01;
        try {
            go(N, 0);
            printf("???\n");
        } catch(...) {
        }
    }
}

