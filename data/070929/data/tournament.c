#include <stdio.h>
#include <string.h>

typedef struct {
    char n[30];
    double a;
} knight;

knight ks[12000];

int comp(knight* a, knight* b) {
    if(a->a > b->a) return 1;
    if(a->a < b->a) return -1;
    return 0;
}
int ispow2(int n) {
    return (n & (n-1)) == 0;
}
double mem[3000][3000];

double sq(double x) {return x*x;}
#define SETMIN(x,y) {double z = (y); if(z<(x)) x = z;}
#define INF (1e100)
double foo(int t, int b) {
    double ret = INF;
    if(mem[t][b] != INF) return mem[t][b];
    if(b > 0) SETMIN(ret, foo(t, b-1))
    if(t > 0) SETMIN(ret, foo(t-1, b) + sq(ks[t*2+b-1].a-ks[t*2+b-2].a))
    if(b == 0 && t == 0) ret = 0;
    mem[t][b] = ret;
    return ret;
}
void print(int t, int b) {
    if(b > 0) {
        if(foo(t, b-1)==foo(t,b)) {
            puts(ks[t*2+b-1].n);
            print(t, b-1);
        } else if(t > 0) print(t-1, b);
    }
}
main() {
    int N, i, j, b;
    while(1) {
        scanf("%d", &N);
        if(!N) break;
        for(i = 0; i < N; i++) {
            scanf("%s %lf", ks[i].n, &ks[i].a);
        }
        qsort(ks, N, sizeof(ks[0]), comp);
        b = 0;
        while(!ispow2(N+b)) b++;
        for(i=0; i<3000; i++) for(j=0; j<3000; j++) mem[i][j] = INF;
        print((N-b)/2, b);
    }
}
