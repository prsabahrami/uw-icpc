int card[52];
int new_card[52];
int S[200][52];
main() {
    int i,j,s,n;
    char* vals[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack",
"Queen", "King", "Ace" };
    char* suits[] = { "Clubs", "Diamonds", "Hearts", "Spades" };
    for( i=0; i<52; i++ ) {
        card[i] = i;
    }
    scanf( "%u ", &n );
    for( i=0; i<n; i++) for( j=0; j<52; j++ ) scanf( "%u ", S[i]+j );
    while( scanf("%u ", &s ) == 1) {
        for( i=0; i<52; i++ ) {
            new_card[i] = card[S[s-1][i]-1];
        }
        memcpy(card,new_card,sizeof(card));
        for( i=0; i<52; i++ ) {
            printf( "%s of %s\n", vals[card[i]%13], suits[card[i]/13] );
        }
        puts("");
    }
}
