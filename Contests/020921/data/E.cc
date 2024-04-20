#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdio>
#include <cstdlib>
#include <cmath>
typedef vector<int> VI;  typedef vector<vector<int> > VVI;
typedef vector<string> VS;  typedef vector<vector<string> > VVS;
typedef signed long long i64;  typedef unsigned long long u64;

main() {
	int leftx, rightx;
	int lefth, righth;
	int leftt, rightt, midt, midl, midr;
	int i, j, x;

	for(;;) {
		scanf( " %d %d", &leftx, &rightx );
		if( leftx == 0 && rightx == 0 ) break;
		VI div;
		for( i = leftx; i <= rightx; i += 2 ) {
			scanf( " %d", &x );
			div.push_back(x);
		}
		lefth = righth = 0;
		for( i = leftx, j = 0; i < 0; i += 2, j++ ) lefth >?= div[j];
		for( i = rightx, j=div.size()-1; i > 0; i -= 2, j-- ) righth >?= div[j];
		if( lefth > righth ) {
			reverse(div.begin(), div.end());
			swap(lefth, righth);
			swap(leftx, rightx); leftx = -leftx; rightx = -rightx;
		}
		leftt = lefth = 0;
		for( i = leftx, j = 0; i < 0; i += 2, j++ ) {
			lefth >?= div[j];
			leftt += 2*lefth;
		}
		midl = j-1; midr = j;
		midt = 2*lefth; leftt -= 2*lefth;
		while( div[midl] < lefth ) {midl--; midt += 2*lefth; leftt -= 2*lefth;}
		while( div[midr] < lefth ) {midr++; midt += 2*lefth;}
		if( lefth == righth ) {
			rightt = righth = 0;
			for( i = rightx, j = div.size()-1; j > midr; i -= 2, j-- ) {
				righth >?= div[j];
				rightt += 2*righth;
			}
			printf( "%d\n", 2*(leftt <? rightt) + midt );
		} else {
			rightt = 0;
			for( j = midr; div[j] <= lefth; j++ ) {
				rightt += 2*lefth;
			}
			printf( "%d\n", leftt + midt + (leftt <? rightt) );
		}
	}
}

