#include <stdio.h>
#include <string.h>
#define N 1100000

char toppled[N];
int edges[N][2];
unsigned se[N];
char incoming[N];

int topple(int x) {
    if(!toppled[x]) {
        int i;
        toppled[x] = 1;
        for(i = se[x]; i < N && edges[i][0] == x; i++) {
            topple(edges[i][1]);
        }
    }
}
int comp(const int *e1, const int *e2) {
    return *e1 - *e2;
}

char seen[N];
int nextfin;
int finish[N];
int dfs(int n) {
    if(!seen[n]) {
        int i;
        seen[n] = 1;
        for(i = se[n]; i < N && edges[i][0] == n; i++) {
            dfs(edges[i][1]);
        }
        finish[n] = ++nextfin;
    }
}
int fincomp(const int *e1, const int *e2) {
    return finish[*e2] - finish[*e1];
}
int nums[N];
main() {
    int CASES;
    scanf("%d", &CASES);
    while(CASES--) {
        int n, m, i, cnt,l;
        memset(toppled,0,sizeof(toppled));
        memset(incoming,0,sizeof(incoming));
        memset(seen,0,sizeof(seen));
        memset(finish,0,sizeof(finish));
        scanf("%d %d %d", &n, &m, &l);
        for(i=0; i<m; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            x--; y--;
            edges[i][0] = x;
            edges[i][1] = y;
            incoming[y] = 1;
        }
        qsort(edges, m, sizeof(edges[0]), comp);
        memset(se,-1,sizeof(se));
        for(i=m-1; i>=0; i--) {
            se[edges[i][0]] = i;
        }
        for(i=0;i<l;i++) {
            int x;
            scanf("%d", &x);
            x--;
            topple(x);
        }
        cnt = 0;
        for(i=0;i<n;i++) if(toppled[i]) cnt++;
        printf("%d\n", cnt);
    }
}
