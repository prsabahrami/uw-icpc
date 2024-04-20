#include <stdio.h>

int x[20];
int y[20];
int r[20];

int dsq(int i, int j) {
    return i*i + j*j;
}
int hits(int i, int j) {
    return dsq(x[i]-x[j], y[i]-y[j]) <= dsq(r[i]+r[j],0);
}

main() {
    int CASES;
    scanf("%d", &CASES);
    while(CASES--) {
        int c,i,j,k;
        int mx = 0;
        scanf("%d", &c);
        for(i=0;i<c;i++) {
            scanf("%d %d %d", x+i,y+i, r+i);
        }
        for(i=0;i<(1<<c);i++) {
            int tota = 0;
            for(j=0;j<c;j++) {
                if(!(i & (1<<j))) continue;
                tota += r[j]*r[j];
                for(k=0;k<c;k++) {
                    if(j==k) continue;
                    if(!(i & (1<<k))) continue;
                    if(hits(j,k)) goto blah;
                }
            }
            if(tota > mx) mx = tota;
blah:;
        }
        printf("%d\n", mx);
    }
}

