#include <stdio.h>
#include <string.h>

char DNA[101][1001];
struct sff {
    char* dna;
    char lf;
};

char* outputs[100001];
struct sff suff[100001];
int dif[100001];

int comp( const struct sff* c1, const struct sff* c2 ) {
    return strcmp(c1->dna, c2->dna);
}


void prt(char* c, int l) {
    int i;
    for( i = 0; i < l; i++) printf("%c", c[i]);
    printf("\n");
}

main() {
    int on;
    int i, n, j, ns, l;
    int first = 1;
    while(1) {
        scanf("%d ", &n);
        if(!n) break;
        if(!first) {
            puts("");
        }
        first = 0;
        ns=0;
        for( i = 0; i < n; i++) {
            gets(DNA+i);
            for(j=0; DNA[i][j]; j++) {
                suff[ns].dna = &DNA[i][j];
                suff[ns].lf = i;
                ns++;
            }
        }
        qsort(suff, ns, sizeof(suff[0]), comp);
        for(i = 1; i < ns; i++) {
            for( j = 0; suff[i-1].dna[j] && suff[i].dna[j] && suff[i-1].dna[j] == suff[i].dna[j]; j++);
            dif[i] = j;
        }
        int maxl = 0;
        for(l=0; l<1001; l++) {
            char lf[n];
            int lfs;
            memset(lf, 0, sizeof(lf));
            lf[suff[0].lf] = 1;
            lfs = 1;
            for(i=1; i<ns; i++) {
                if(dif[i]<l) {
                    memset(lf, 0, n*sizeof(lf[0]));
                    lfs = 0;
                }
                if(!lf[suff[i].lf]){
                    lf[suff[i].lf] = 1;
                    lfs++;
                    if(lfs*2>n) goto OK;
                }
            }
            break;
OK:
            maxl = l;
        }
        //printf("%d\n", maxl);
        if(maxl < 1) {
            printf("?\n");
            continue;
        }
        on = 0;
        for(l=maxl; l<=maxl; l++) {
            char lf[n];
            int lfs;
            memset(lf, 0, sizeof(lf));
            lf[suff[0].lf] = 1;
            lfs = 1;
            for(i=1; i<ns; i++) {
                if(dif[i]<l) {
                    memset(lf, 0, n*sizeof(lf[0]));
                    if(lfs*2>n) outputs[on++] = suff[i-1].dna;
                    lfs = 0;
                }
                if(!lf[suff[i].lf]){
                    lf[suff[i].lf] = 1;
                    lfs++;
                }
            }
            if(lfs*2>n) outputs[on++] = suff[i-1].dna;
            break;
        }
        prt(outputs[0],l);
        for(i = 1; i < on; i++) {
            if(!strncmp(outputs[i-1], outputs[i], l)) continue;
            prt(outputs[i],l);
        }
    }
}
