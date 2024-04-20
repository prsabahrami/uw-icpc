int km[200], pr[200], max[200], min[200];
#define MAX(x,y) if((x)>(y)) (x)=(y)
#define MIN(x,y) if((x)<(y)) (x)=(y)
main() {
    int dist;
    int n=0;
    int i,j;
    int cost=0;
    int gas=100;

    scanf( "%u ", &dist );
    while( scanf( "%u %u ", km+n, pr+n ) == 2 ) {
        if( n>0) if( km[n] == km[n-1] ) {
            MAX(pr[n-1], pr[n] );
            continue;
        }
        max[n] = 200;
        MAX(max[n], dist-km[n] + 100 );
        MIN(min[n], 100 - km[n] );
        if( n>0 ) MIN(min[n-1], km[n]-km[n-1] );
        n++;
    }
    MIN(min[n-1], dist-km[n-1] + 100 );
    for(i=0; i<n; i++) for( j=i+1; j<n; j++ ) {
        if( pr[j]<pr[i] ) MAX(max[i], km[j]-km[i] );
    }
    if( n == 0 && dist > 0 ) { puts( "Impossible" ); exit(0); }
    if( km[0] > 100 ) { puts( "Impossible" ); exit(0); }
    for(i=0; i<n; i++) {
0&&     printf( "%u %u %u\n", km[i], max[i], min[i] );
        if( max[i] < min[i] ) {
            puts( "Impossible" ); exit(0);
        }
        if( i==0 ) gas -= km[i];
        else gas -= km[i] - km[i-1];
        cost += (max[i]-gas)*pr[i];
        gas = max[i];
    }
    printf( "%u\n", cost );
}
