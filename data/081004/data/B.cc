#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define MP make_pair
#define A first
#define B second

#define PB push_back
#define FR(i, a, b) for(int i=(a); i<(b); i++)
#define FOR(i, n) FR(i, 0, n)
#define RF(i, a, b) for(int i=(b)-1; i>=(a); i--)
#define ROF(i, n) RF(i, 0, n)
#define EACH(it,X) for(__typeof((X).begin()) it=(X).begin(); it!=(X).end(); ++it)

#define MAXN 110000

int lis[MAXN],n,m,ans,del;

int work(int len){
  int pre,cou;
  if(len<0) return 0;
  pre=-(1<<20);
  cou=0;
  FOR(i,n)
    if(lis[i]>pre+len){
      pre=lis[i];
      if(++cou>m) return 0;
    }
  return 1;
}

int main(){
  int ct;
  scanf("%d",&ct);
  while(ct--){
    scanf("%d%d",&m,&n);
    FOR(i,n) scanf("%d",&lis[i]);
    sort(lis,lis+n);
    ans=del=1<<20;
    while(del){
      if(work(ans-del)) ans-=del;
      del/=2;
    }
    printf("%d.%d\n",ans/2,(ans%2==0)?0:5);
  }
  return 0;
}

