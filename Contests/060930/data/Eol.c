#include <stdio.h>

main() {
    double vb, vw, vr, vc;
    int k, i;
    while(1) {
        scanf("%d %lf %lf %lf %lf", &k, &vb, &vw, &vr, &vc);
        if(k == 0) break;
        double f = -(-k*vr+vr-vb+k*vw-vw)/k;
        if(f<0) f = 0;
        double leftover = vb-(k-1)*(vc-vr);
        if(f<leftover) f = leftover;
        if(f+vw>vc) f = vc-vw;
        if(f>vb) f= vb;
        double s = 0;
        if(k>1) {
            s = (vb-f)/(k-1);
            if(vr+s > vc) s=vc-vr;
        }
        printf("%d %lf", k, f);
        for(i = 0; i < k-1; i++) {
            printf(" %lf", s);
        }
        printf("\n");
    }
}
