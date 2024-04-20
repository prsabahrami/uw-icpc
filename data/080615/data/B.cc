using namespace std;

#include <bitset>
#include <vector>
#include <stdio.h>
#include <iostream>

#define MAX 11000
//#define MAX 11

bitset<MAX> seen;
int es[MAX][2];
int ei[MAX];
vector<int> topo;
int dd[MAX];
int uu[MAX];

void dfs(int i) {
    int j;
    if(seen[i]) return;
    seen[i] = 1;
    for(j = ei[i]; es[j][0] == i; j++) {
        dfs(es[j][1]);
    }
    topo.push_back(i);
}
int comp(const void* aa, const void* bb) {
    int* a = (int*) aa;
    int* b = (int*) bb;
    if(a[0] != b[0]) return a[0]-b[0];
    return a[1] - b[1];
}
bitset<MAX> bounds[MAX];

int l,r,u,d,a;
int glb(int x, int y) {
    int i;
    bitset<MAX> all = bounds[x] & bounds[y];
    for(i=0; i < topo.size(); i++) {
        if(all[topo[i]]) return topo[i];
    }
    printf("no glb for %u %u\n", x,y);
    cout << bounds[x] << endl;
    cout << bounds[y] << endl;
    cout << all << endl;
    exit(1);
}

main() {
    int i,j;
    scanf("%u%u%u%u%u", &l, &r, &u, &d, &a);
    for(i = 0; i < r; i++) {
        scanf("%u%u", &(es[i][0]), &(es[i][1]));
    }
    qsort(es, r, sizeof(es[0]), comp);
    /*
    for(i = 0; i < r; i++) {
        printf("%u %u\n", es[i][0], es[i][1]);
    }
    */
    j = 0;
    for(i = 0; i < r; i++) {
        while(j <= es[i][0]) {
            ei[j] = i;
            j++;
        }
    }
    for(i=1; i<= l; i++) dfs(i);
    for(i=1; i<= l; i++) bounds[i][i] = 1;
    reverse(topo.begin(), topo.end());
    for(i=0; i < topo.size(); i++) {
        int k = topo[i];
        for(j = ei[k]; es[j][0] == k; j++) {
            bounds[es[j][1]] |= bounds[es[j][0]];
        }
        //cout << k << " " << bounds[k] << endl;
    }
    reverse(topo.begin(), topo.end());
    for(i=1; i<= u; i++) scanf("%u", uu+i);
    for(i=1; i<= d; i++) scanf("%u", dd+i);
    for(i=1; i<= a; i++) {
        char s[1000];
        int x,y;
        scanf("%u %s %u", &x, s, &y);
        int g = glb(uu[x],dd[y]);
        if(s[0] == 'w') dd[y] = g;
        else uu[x] = g;
        printf("%u\n", g);
    }
}
