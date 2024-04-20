#define ULL unsigned long long
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define swap(a,b) do { int temp = (a); (a) = (b); (b) = temp; } while(0)
int foo[5000];
int* div; 
int left, right;
ULL try() {
    int i, highest = 0;
    ULL total = 0, middle = 0, candidate1 = -1LL, candidate2 = -1LL;
    for( i = left; i <= 0; i+=2 ) {
        if( div[i] >= highest ) {
            middle = total;
            highest = div[i];
        }
        total += 2*highest;
    }
    for( ; i <= right; i+=2 ) {
        if( div[i] == highest && candidate1 == -1LL )
            candidate1 = total + middle;
        if( div[i] > highest ) {
            candidate2 = total;
            break;
        }
        total += 2*highest;
    }
    return min( candidate1, candidate2 );
}
main() {
    ULL candidate1, candidate2;
    div = foo+2500;
    for(;;) {
        int i;
        scanf( "%d %d ", &left, &right );
        if( !left ) break;
        for( i = left; i <= right; i+=2 )
            scanf( "%d ", div+i );
        candidate1 = try();
        for( i = 0; i <= 2000; i++ ) 
            swap( div[i], div[-i] );
        swap(left,right); left *= -1; right *= -1;
        candidate2 = try();
        printf( "%lld\n", min( candidate1, candidate2 ) );
    }
}
