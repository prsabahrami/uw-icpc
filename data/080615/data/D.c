#include <stdio.h>

int M[110];
int P[1100000];

main() {
    int i,j,a,b,c,p;
    for(i = 0; i < 110; i++) M[i] = i;
    scanf("%u %u %u", &a, &b, &c);
    for(i = 0; i < a; i++) P[i] = 1;
    while(b--) {
        scanf("%u %u", &i, &j);
        M[i] = j;
    }
    p = 0;
    while(c--) {
        scanf("%u", &i);
        P[p] += i;
        if(P[p] > 100) P[p] = 100;
        P[p] = M[P[p]];
        if(P[p] == 100) break;
        p++;
        p %= a;
    }
    for(i = 0; i < a; i++)
        printf("Position of player %u is %u.\n", i+1, P[i]);
}
