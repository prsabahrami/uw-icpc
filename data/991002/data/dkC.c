int ar[500001];

main() {
	int i, j, k, x, y, z, n, w;

	memset( ar, 0, sizeof( ar ) );
	ar[0] = 1;
	scanf( " %d %d", &w, &n );
	w *= 1000;
	if( w > 500000 ) {
		printf( "0\n" );
		return;
	}
	for( i = 0; i < n; i++ ) {
		scanf( " %d %d", &x, &y );
		y -= x;
		z = 1000000000;
		for( j = 0; j <= w-x; j++ ) {
			if( ar[j] ) z = 0; else z++;
			if( z <= y ) ar[j+x] = 1;
		}
		if( ar[w] ) break;
	}
	for( i = 0; i <= w; i++ ) if( ar[w-i] ) break;
	printf( "%d\n", i );
}
