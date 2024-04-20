#include <stdio.h>

int p[11000000];
char pp[1100000];
char sp[1100000];
char memo[1100000];

int isp(int x) {
    int i;
    for(i = 5; i*i <= x; i++) {
        if(x % i) continue;
        int j = x / i;
        if((j%4) == 1) return 0;
    }
    return 1;
}
int np;
int issp(int h) {
    if(memo[h] == 1) return 1;
    if(memo[h] == 2) return 0;
    int i;
    for(i = 0; i < np && p[i]*p[i] <= h; i++) {
        int x = p[i];
        int y = h/x;
        if(x*y != h) continue;
        if(pp[y]) {
            memo[h] = 1;
            return 1;
        }
    }
    memo[h] = 2;
    return 0;
}
main() {
    int h, i;
    for(i = 5; i < 1000000; i+=4) {
        if(isp(i)) {
            p[np++] = i;
            pp[i] = 1;
        }
    }
    while(1) {
        scanf("%d", &h);
        if(!h) break;
        int n = 0;
        for(i = 5; i <= h; i+=4) {
            if(issp(i)) n++;
        }
        printf("%d %d\n", h, n);
    }
}
