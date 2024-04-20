#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define N 510000
int n;
int a[N],ans[N];
int all;
set<pair<int,int> > dic;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    int maxi=0;
    for(int i=1;i<=n;i++)dic.insert(mp(a[i],i));
    for(int i=1;i<=n;i++)
    {
        auto t=*dic.rbegin();
       // cout<<t.first<<" "<<t.second<<endl;
        if (t.first+all<n-1)break;
        maxi=i;
        dic.erase(t);
        all++;
        t.first=t.first-1-(n-1);
        dic.insert(t);
    }
    if (maxi==n){ puts("Recurrent"); return 0; }
    for(auto p:dic)ans[p.second]=p.first+all;
    for(int i=1;i<=n;i++)printf("%d%c",ans[i],i==n?'\n':' ');
    return 0;
}
