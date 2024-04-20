char name[30][100];
char party[30][100];
char v[30];
char buff[100];

main() {
	int i, j, k, x, y, z, n;

	scanf( "%d ", &n );
	for( i = 0; i < n; i++ ) {
		gets( name[i] );
		gets( party[i] );
	}
	scanf( "%d ", &x );
	for( i = 0; i < x; i++ ) {
		gets( buff );
		for( j = 0; j < n; j++ ) if( !strcmp( name[j], buff ) ) v[j]++;
	}
	x = -1; y = -1;
	for( i = 0; i < n; i++ ) {
		if( v[i] > x ) {
			x = v[i];
			y = i;
		} else if( v[i] == x ) {
			y = -1;
		}
	}
	if( y == -1 )
		printf( "tie\n" );
	else
		printf( "%s\n", party[y] );
}
