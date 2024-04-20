signed char N[10100];
signed char D[10100];

bs( int* a ) {
	int i,j;
	for( i=0;i<3;i++ ) for(j=i+1;j<3;j++ ) if( a[i]<a[j] ) {
	int t = a[i];
	a[i]= a[j];
	a[j] = t;
	}
}

swap( int* a ) {
	int i;
	int j;
	int t;
	i = rand() %3;
	j = rand() %3;
	t = a[i];
	a[i]= a[j];
	a[j] = t;

}
long double pp( int a, int b ) {
	long double ret = 1;
	int i;
	if( a<b) return 1/pp(b,a);
	for( i=a; i>b; i-- ) {
		ret *= (long double) i;
	}
	return ret;
}
main() { 
	int overflowed;
	int j;
	int ii;
	int num[3], den[3];
	int p,q,r,s;
	int i;
	long double Q;
	long double Qn, Qd;
	for(;;) {
		if( scanf( "%u %u %u %u", &p, &q, &r, &s ) != 4 ) {
			break;
		}
	Q  = 1;
	
	num[0]=p;
	num[1]=s;
	num[2]=r-s;
	den[0]=q;
	den[1]=r;
	den[2]=p-q;
	bs( num);
	bs( den );
	ii = 0;
	/*
	do {
	Q = 1;

		ii++;
	for( i=0;i<3; i++ ) {
			
			if( num[i] >= den[i] )
			Q *= pp( num[i],den[i] );
		 else Q /= pp( den[i], num[i] );
	 }
		 if( rand() < .5 ) swap( den ); else swap( num );
	 } while ( Q != Q);
	*/
	memset( N,0,sizeof( N ) );
	memset( D,0,sizeof( D ) );
	for( i=0;i<3;i++) {
		for(j=1;j<=num[i];j++) N[j]++;
		for(j=1;j<=den[i];j++) D[j]++;
	}
	Q = 1;
	do {
	overflowed = 0;
	for( i=1;i<10001; i++) {
		while( N[i] > D[i] ) {
			if( Q > 10E30 ) { overflowed = 1; break;} else {
			N[i]--;
			Q *= (long double) i;
			}
		}
		while( N[i] < D[i] ) {
			if( Q < 1E-30 ) {
				overflowed = 1; break;
				} else {
				D[i]--;
				Q /= (long double) i;
			}
		}
	}
	} while ( overflowed );


	printf( "%.5lf\n", (double) Q );

	}
}
