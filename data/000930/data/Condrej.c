int A[5000];

main() {
    int n;
    int x,y,d;
    int i;
    int nope;
    while( scanf( "%u ", &n ) == 1 ) {
	memset(A,0,sizeof(A));
	nope=0;
	scanf( "%u ", &x );
	for( i=1; i<n; i++ ) {
	    scanf( "%u ", &y );
	    d = y-x;
	    x=y;
	    if( d<0 ) d*=-1;
	    if( d>=n || d == 0 ) {
		nope=1;
	    } else {
		if( A[d] ) nope=1;
		A[d]=1;
	    }
	}
	if( nope ) printf("Not jolly\n");
	else printf( "Jolly\n" );
    }
}

