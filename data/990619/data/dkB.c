int mp[21][20001];
int cn, cm[100], ccmin[100], ccmax[100];
int bn, bc[200], bp[200];

main() {
	int i, j, k, m, x, y, z, n;

	scanf( " %d", &bn );
	for( i = 0; i < bn; i++ )
		scanf( " %d %d", &bc[i], &bp[i] );
	scanf( " %d", &cn );
	for( i = 0; i < cn; i++ ) {
		scanf( " %d %d %d", &cm[i], &ccmin[i], &ccmax[i] );
		ccmin[i] *= cm[i];
		ccmax[i] *= cm[i];
	}

	for( j = 0; j <= 20; j++ ) {
		n = 1000*j;
		for( k = 0; k <= n; k++ ) mp[j][k] = 1000000000;
	}
	mp[0][0] = 0;

	for( j = 0; j < bn; j++ ) {
		for( k = 20; k > 0; k-- ) {
			n = 1000*(k-1);
			for( m = 0, z = bc[j]; m <= n; m++, z++ )
				if( (y=mp[k-1][m]+bp[j]) < mp[k][z] )
					mp[k][z] = y;
		}
	}

	for( i = 0; i < cn; i++ ) {
		x = 1000000000;
		for( j = ccmin[i]; j <= ccmax[i]; j++ )
			if( mp[cm[i]][j] < x ) x = mp[cm[i]][j];
		if( x == 1000000000 )
			printf( "impossible\n" );
		else
			printf( "%d\n", x );
	}
}
