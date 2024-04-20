/**
 * CTU Open 2017
 * Problem Solution: Gallery
 * Idea: Dynamic programming - similar to largest palindrome
 * @author Morass
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define ZERO (1e-10)
#define INF int(1e9+1)
#define CL(A,I) (memset(A,I,sizeof(A)))
#define DEB printf("DEB!\n");
#define D(X) cout<<"  "<<#X": "<<X<<endl;
#define EQ(A,B) (A+ZERO>B&&A-ZERO<B)
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define IN(n) int n;scanf("%d",&n);
#define FOR(i, m, n) for (int i(m); i < n; i++)
#define F(n) FOR(i,0,n)
#define FF(n) FOR(j,0,n)
#define FT(m, n) FOR(k, m, n)
#define aa first
#define bb second
void ga(int N,int *A){F(N)scanf("%d",A+i);}
#define MX 5001
int A[MX],N;
short dp[2][MX];
int main(void){
    while(~scanf("%d",&N)){
        assert(N<MX&&N>0),ga(N,A),CL(dp,0);//TODO ASS
        F(N)assert(A[i]>0&&A[i]<=1e4);//TODO ASS
        for(int i=N-1;~i;--i)FT(i,N)
            dp[i&1][k]=i^k?A[k]^A[i]?max(dp[i&1][k-1],dp[!(i&1)][k]):1+dp[!(i&1)][k-1]:0;
        printf("%d\n",(int)dp[0][N-1]);
    }
    return 0;
}
