int hi[20];
int lo[20];

main() {
    int num, i;
    char guess[1000];
    while(1) {
        scanf( "%u ", &num );
        if( !num ) break;
        gets( guess );
        if( !strcmp( guess, "too high" ) ) hi[num] = 1;
        else if( !strcmp( guess, "too low" ) ) lo[num] = 1;
        else {
            for( i = 1; i <= 10; i++ ) {
                if( hi[i] && i <= num ) goto cheat;
                if( lo[i] && i >= num ) goto cheat;
            }
            puts("Stan may be honest");

goagain:
            memset(lo,0,sizeof(lo));
            memset(hi,0,sizeof(hi));
            continue;
cheat:
            puts("Stan is dishonest");
            goto goagain;
        }
    }
}

