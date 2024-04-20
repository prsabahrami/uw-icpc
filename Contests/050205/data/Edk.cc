#include <iostream>
using namespace std;

int b[5][5];

main() {
	int i, j, k, x, y, z, n;

	for( cin >> n; n--; ) {
		for( y = 0; y < 5; y++ )
		for( x = 0; x < 5; x++ ) {
			if( y == 2 && x == 2 )
				b[y][x] = -1;
			else
				cin >> b[y][x];
		}
		int ret = 0;
		for( i = 0; i < 75; i++ ) {
			cin >> z;
			for( y = 0; y < 5; y++ )
			for( x = 0; x < 5; x++ )
				if( b[y][x] == z ) b[y][x] = -1;
			if( !ret ) {
				for( y = 0; y < 5; y++ ) {
					for( z = x = 0; x < 5; x++ ) z += (b[y][x] == -1);
					if( z == 5 ) ret = i+1;
				}
				for( x = 0; x < 5; x++ ) {
					for( z = y = 0; y < 5; y++ ) z += (b[y][x] == -1);
					if( z == 5 ) ret = i+1;
				}
				for( z = x = 0; x < 5; x++ ) z += (b[x][x] == -1);
				if( z == 5 ) ret = i+1;
				for( z = x = 0; x < 5; x++ ) z += (b[x][4-x] == -1);
				if( z == 5 ) ret = i+1;
			}
		}
		cout << "BINGO after " << ret << " numbers announced\n";
	}
}
