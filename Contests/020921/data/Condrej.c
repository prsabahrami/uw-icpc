#include <stdio.h>
int side;
int bits;
int len[30];
char memo[1111111];
int masktolength( int n ) {
    int i,j,ret = 0;
    for( j = 1, i = 0; i < bits; i++, j<<=1 ) {
        if( n & j ) ret += len[i];
    }
    return ret;
}
int go( int n ) {
    int i,j,length;
    if( memo[n] ) return 0;
    length = masktolength( n );
    if( length == 4*side ) return 1;
    for( j = 1, i = 0; i < bits; i++, j<<=1 ) {
        if( n & j ) continue;
        if( ((length+len[i]) % side) && (length % side) && ( (length + len[i]) / side != length / side ) ) continue;
        if( go( n | j ) ) return 1;
    }
    memo[n] = 1;
    return 0;
}
main() {
    int N;
    scanf( "%u", &N );
    while( N-- ) {
        int i;
        side = 0;
        memset( memo, 0, sizeof( memo ) );
        scanf( "%u", &bits );
        for( i = 0; i < bits; i++ ) {
            scanf( "%u", len+i );
            side += len[i];
        }
        for( i = 0; i < bits; i++ ) {
            if( len[i] > side/4 ) {
                side = 1; break;
            }
        }
        if( side%4 ) puts( "no" );
        else {
            side /= 4;
            if( go(0) ) puts( "yes" );
            else puts( "no" );
        }
    }
}
