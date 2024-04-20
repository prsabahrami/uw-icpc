#include <stdio.h>
#define ll long long
const int MOD=1000000007;
ll powmod(ll b,int e)
{
    if (e==1) return b;
    if (e&1) return powmod(b*b%MOD,e/2)*b%MOD;
    return powmod(b*b%MOD,e/2);
}

int n,p,q;
ll solve()
{
    scanf("%d%d%d",&n,&p,&q);
    ll r=p*powmod(q,MOD-2)%MOD;
    ll nc3=(n*1LL*(n-1)*1LL*(n-2)/6)%MOD;
    return nc3*((3*(n-3)*(powmod(r,5)+MOD-powmod(r,6))+powmod(r,3)+MOD-powmod(r,6))%MOD)+powmod(nc3,2)*powmod(r,6);
}

int t;
int main()
{
    scanf("%d",&t);
    while (t--) printf("%lld\n",solve()%MOD);
}
