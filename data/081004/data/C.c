#include <stdio.h>
#include <string.h>

int coins[1100000];
unsigned dp[1100000];

int comp(const int* a, const int *b) {
    return (*a)-(*b);
}
main() {
    int nc;
    int i,j;
    int CASES;
    int price;
    scanf("%d", &CASES);
    while(CASES--) {
        memset(dp,-1,sizeof(dp));
        dp[0]=0;
        scanf("%d", &price);
        scanf("%d", &nc);
        for(i=0;i<nc;i++) {
            scanf("%d", coins+i);
        }
        for(i=0;i<nc;i++) {
            for(j=price-1;j>=0;j--) {
                if(dp[j]==-1) continue;
                if(dp[j+coins[i]] > dp[j]+1) dp[j+coins[i]] = dp[j]+1;
            }
        }
        for(i=price;dp[i]==-1;i++);
        printf("%d %d\n", i, dp[i]);
    }
}
