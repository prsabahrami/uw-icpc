#include <math.h>
#include <stdio.h>

#define EPS 0.0000001

char buf[100000];
char fd[200][30];
char lt[200][30];

double X, Y;

double HD;

void FD(int d) {
    X += d*cos(HD/180*M_PI);
    Y += d*sin(HD/180*M_PI);
    //printf("FD %d to %lf %lf\n", d, X, Y);
}

void LT(int d) {
    HD+=d;
}

void HOME() {
    HD = 0;
    X = 0;
    Y = 0;
}

int myatoi(char* st, int other) {
    if(st[0] == '?') return other;
    return atoi(st);
}



main() {
    int CASES;
    scanf("%d ", &CASES);
    while(CASES--) {
        int cnt;
        int i;
        int turn = 0;
        int cmds;
        scanf("%d", &cmds);
        HOME();
        while(cmds--) {
            int dist;
            scanf("%s %d\n", buf, &dist);
            switch(buf[0]) {
                case 'f': FD(dist); break;
                case 'b': FD(-dist); break;
                case 'l': LT(dist); break;
                case 'r': LT(-dist); break;
            }
        }
        printf("%.0lf\n", sqrt(X*X+Y*Y));
    }
}
