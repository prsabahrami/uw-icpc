#include <stdio.h>

char buf[1000], buf2[1000];

int main( int argc, char *argv[] ) {
	int i, j, k, x, y, z;
	FILE *dat, *dif;
	int len, ll, rl;
	
	strcpy( buf, argv[0] );
	if( strlen(buf)<4 || strcmp( buf+(strlen(buf)-4), ".cmd" ) ) {
		printf( "Invalid command line (call as C.?.cmd)\n" );
		return 7;
	}
	buf[strlen(buf)-4] = 0;
	strcat( buf, ".dat" );
	if( !(dat = fopen( buf, "r" )) ) {
		printf( "Unable to open .dat file '%s'\n", buf );
		return 7;
	}
	buf[strlen(buf)-4] = 0;
	strcat( buf, ".dif" );
	if( !(dif = fopen( buf, "r" )) ) {
		printf( "Unable to open .dif file '%s'\n", buf );
		return 7;
	}

	fscanf( dat, " %d", &len );
	len *= 100;
	fgets( buf, 1000, dif );
	fgets( buf2, 1000, stdin );
	if( strcmp( buf, buf2 ) ) {
		buf[strlen(buf)-1] = 0;
		buf2[strlen(buf2)-1] = 0;
		printf( "Car # error: '%s' != '%s' (from .dif)\n", buf2, buf );
		return 2;
	}
	x = atoi( buf );

	ll = rl = 0;
	for( i = 0; i < x; i++ ) {
		if( !fgets( buf, 1000, stdin ) ) {
			printf( "Unexpected end of input\n" );
			return 2;
		}
		buf[strlen(buf)-1] = 0;
		fscanf( dat, " %d", &y );
		if( !strcmp( buf, "port" ) ) {
			ll += y;
		} else if( !strcmp( buf, "starboard" ) ) {
			rl += y;
		} else {
			printf( "Invalid direction: '%s'\n", buf );
			return 1;
		}
		if( ll > len || rl > len ) {
			printf( "Cars improperly directed\n" );
			return 2;
		}
	}

	if( fgets( buf, 1000, stdin ) ) {
		printf( "Trailing lines:\n" );
		do {
			printf( "%s", buf );
		} while( fgets( buf, 1000, stdin ) );
		return 2;
	}
	return 0;
}
