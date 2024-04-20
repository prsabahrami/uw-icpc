signed char hash[999999];
unsigned hash2[999999];

long long n;

signed char go( long long c ) {
    signed char winnable;
    int i;
    if( c >= n ) return 1;
    if( hash2[ c % 999999 ] == c ) {
        return hash[ c % 999999 ];
    }
    hash2[ c % 999999 ] = c;
    winnable = 1;
    for( i=2; i < 10; i++ ) {
	if( go( c*i ) > 0 ) {
	    winnable = -1;
	    break;
	}
    }
    return hash[ c % 999999 ] = winnable;
}
main() {
    int nn;
    while( scanf("%u", &nn) ==1 ) {
	n = nn;
	memset( hash, 0, sizeof(hash) );
	memset( hash2, 0, sizeof(hash2) );
	printf( "%s wins.\n", go( 1 ) < 0 ? "Stan" : "Ollie" );
    }
}
