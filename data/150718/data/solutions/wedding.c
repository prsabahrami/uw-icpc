#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int BAD[40*40*4][2];
int R[40];

int N;
int P;

int go(int f) {
    int i;
    int p = f;
    if(p<0) {
        p = ~p;
        if(R[p] < 0) return 1;
        if(R[p] > 0) return 0;
        R[p] = -1;
    } else {
        if(R[p] > 0) return 1;
        if(R[p] < 0) return 0;
        R[p] = 1;
    }
    for(i = 0; i < P; i++) {
        if(BAD[i][0] == f)
            if(!go(~BAD[i][1])) return 0;
        if(BAD[i][1] == f)
            if(!go(~BAD[i][0])) return 0;
    }
    return 1;
}
main() {
    int i;
    while(1) {
        memset(BAD,0,sizeof(BAD));
        memset(R,0,sizeof(R));
        scanf("%d %d", &N, &P);
        if(!N) break;
        for(i = 0; i < P; i++) {
            int p1, p2;
            char g1, g2;
            scanf("%d%c %d%c", &p1, &g1, &p2, &g2);
            if(g1 == 'w') p1 = ~p1;
            if(g2 == 'w') p2 = ~p2;
            BAD[i][0] = p1;
            BAD[i][1] = p2;
        }
        memset(R,0,sizeof(R));
        for(i = 0; i < N; i++) {
            if(R[i]) continue;
            if(!go(i)) goto bad;
        }
        for(i = 1; i < N; i++) {
            if(R[i]>0) printf("%dw", i);
            else printf("%dh", i);
            if(i<N-1) printf(" ");
        }
        puts("");
        continue;
bad:
        printf("bad luck\n");
    }
}
