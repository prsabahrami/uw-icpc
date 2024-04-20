#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

const int NSTEPS = 50000;

int N, prev[NSTEPS+50];
double kg[100], sum;

int main()
{
    while( cin >> N && N ) {
        memset(prev, 0, sizeof(prev));
        sum = 0;
        for( int i = 0; i < N; i++ ) { cin >> kg[i]; sum += kg[i]; }
        double step = sum / NSTEPS;
        prev[0] = 1;
        for( int i = 0; i < N; i++ ) {
            int wt = (int)(kg[i] / step);
            for( int j = NSTEPS; j-wt >= 0; j-- ) if( prev[j-wt] && !prev[j] ) prev[j] = i+1;
        }
        for( int j = NSTEPS/2; j > 0; j-- ) if( prev[j] ) {
            int f = 0;
            while( j > 0 ) {
                if( f++ ) printf(" ");
                printf("%d", prev[j]);
                j -= (int)(kg[prev[j]-1] / step);
            }
            printf("\n");
            break;
        }
    }
}

