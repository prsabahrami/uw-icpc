#include <stdio.h>

int seq[40000];
int dyn[40000];

main() {
    int i;
    int sgn;
    int count;
    int n;
    int j;

    scanf("%d", &count);
    while(count--) {
        scanf("%d", &n);
        for(i = 0; i < n; i++) scanf("%d", seq+i);
        memset(dyn, 0, sizeof(dyn));
        dyn[1] = seq[0];
        sgn = -1;
        for(i=1; i < n; i++) {
            if(dyn[1] < seq[i]) dyn[1] = seq[i];
            for(j = 1; dyn[j]; j++) {
                if(j&1) {
                    if(dyn[j]>seq[i])
                        if(dyn[j+1]==0 || dyn[j+1]>seq[i]) dyn[j+1] = seq[i];
                } else {
                    if(dyn[j]<seq[i])
                        if(dyn[j+1]==0 || dyn[j+1]<seq[i]) dyn[j+1] = seq[i];
                }
            }
        }
        for(j=1; dyn[j]; j++);
        printf("%d\n", j-1);
    }
}
