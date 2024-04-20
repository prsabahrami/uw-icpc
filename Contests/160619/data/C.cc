#define N 1100000
#include <map>
#include <string>
#include <iostream>
using namespace std;

int p[N];
map<string,int> nn;
int numseen;
int cnt[N];

int lookup(int i) {
    if(i!=p[i]) p[i] = lookup(p[i]);
    return p[i];
}
void merge(int i, int j) {
    int ii = lookup(i);
    int jj = lookup(j);
    if(ii==jj) return;
    if(ii<jj) {
        p[jj] = ii;
        cnt[ii] += cnt[jj];
    } else {
        p[ii] = jj;
        cnt[jj] += cnt[ii];
    }
}
int find(string s) {
    int ret = nn[s];
    if(ret == 0) {
        numseen++;
        ret = numseen;
        nn[s] = ret;
    }
    return ret;
}
main() {
    int CASES;
    cin >> CASES;
    while(CASES--) {
        int i,j;
        for(i=0;i<N;i++) p[i] = i;
        for(i=0;i<N;i++) cnt[i] = 1;
        nn = map<string,int>();
        numseen = 0;
        int num;
        cin >> num;
        for(j=0;j<num;j++) {
            string nm1, nm2;
            cin >> nm1;
            cin >> nm2;
            int n1 = find(nm1);
            int n2 = find(nm2);
            merge(n1, n2);
            cout << cnt[lookup(n1)] << endl;
        }
    }
}
