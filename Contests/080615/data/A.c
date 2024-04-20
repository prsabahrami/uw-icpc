#include <stdio.h>

int w[11000];
int a[11000];
int b[11000];

main() {
    int n;
    int i, j;
    scanf("%d", &n);
    for(i = 0; i<n; i++) {
        scanf("%d", w+i);
    }
    for(i = n-1; i >=0; i--) {
        for(j=i+1; j <= n; j++) {
            if(j==n || w[j] > w[i]) {
                int nw = a[j]+1;
                if(nw > a[i]) a[i] = nw;
            }
            if(j == n || w[j] < w[i]) {
                int nw = b[j]+1;
                if(nw > b[i]) b[i] = nw;
            }
        }
    }
    int max = 0;
    for(i=0; i<n; i++) {
        /*printf("%d %d %d\n", w[i], a[i], b[i]);*/
        int nw = a[i] + b[i] - 1;
        if(nw > max) max = nw;
    }
    printf("%d\n", max);
}
