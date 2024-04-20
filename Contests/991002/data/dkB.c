int num[10001], den[10001];
int pr[10001];

void AddFactors( int *ar, int n ) {
	int i, j, k, x, y, z;

	for( i = 2; i <= n; i++ ) if( pr[i] ) {
		for( j = i; j <= n; j *= i )
			ar[i] += n/j;
	}
}

main() {
	int i, j, k, x, y, z, n;
	int p, q, r, s;
	double val;

	pr[0] = pr[1] = 0;
	for( i = 2; i <= 10000; i++ ) pr[i] = 1;
	for( i = 2; i <= 10000; i++ ) if( pr[i] )
		for( j = 2*i; j <= 10000; j += i ) pr[j] = 0;

	while( scanf( " %d %d %d %d", &p, &q, &r, &s ) == 4 ) {
		for( i = 0; i <= 10000; i++ ) num[i] = den[i] = 0;
		AddFactors( num, p );
		AddFactors( den, q );
		AddFactors( den, p-q );
		AddFactors( den, r );
		AddFactors( num, s );
		AddFactors( num, r-s );

		val = 1.0;
		for( i = 0; i <= 10000; i++ ) if( pr[i] ) {
			num[i] -= den[i];
			while( num[i] > 0 ) {val *= i; num[i]--;}
			while( num[i] < 0 ) {val /= i; num[i]++;}
		}
		printf( "%.5f\n", val );
	}
}
