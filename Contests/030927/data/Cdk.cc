#include <iostream>
#include <cmath>
using namespace std;

double px[2][11], py[2][11], pl[2][10], pa[2][10];
double pi = acos(0.0)*2;

main() {
	int i, j, k, f;

	while( cin >> f && f ) {
		for( i = 0; i < 2; i++ ) {
			for( j = 0; j < f; j++ ) cin >> px[i][j] >> py[i][j];
			px[i][f] = px[i][0]; py[i][f] = py[i][0];
			for( j = 0; j < f; j++ )
				pl[i][j] = sqrt((px[i][j+1]-px[i][j])*(px[i][j+1]-px[i][j]) +
								(py[i][j+1]-py[i][j])*(py[i][j+1]-py[i][j]));
			for( j = 0; j < f; j++ )
				pa[i][j] = atan2(py[i][j+1]-py[i][j], px[i][j+1]-px[i][j]);
		}
		for( i = 1; i < f; i++ )
			if( fabs(pl[1][0]/pl[0][0]*pl[0][i] - pl[1][i]) > 1e-8 ||
				(fabs(pa[1][0]-pa[0][0]+pa[0][i] - pa[1][i]) > 1e-8 &&
				 fabs(pa[1][0]-pa[0][0]+pa[0][i] - pa[1][i] - 2*pi) > 1e-8 &&
				 fabs(pa[1][0]-pa[0][0]+pa[0][i] - pa[1][i] + 2*pi) > 1e-8) )
				break;
		cout << ((i == f) ? "similar\n" : "dissimilar\n");
	}
}

