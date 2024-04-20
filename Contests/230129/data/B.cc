#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define trav(a,x) for(auto&a:x)
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define x0 fuckhel
#define y0 fuckoscar
#define x1 fucksub
#define y1 fuckzzy
#define st first
#define nd second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
typedef vector<int> vi;
const int N=1e6+5,inf=1e9+7;
struct poi{
    ll x,y;
    ll operator*(const poi&p)const{return x*p.y-y*p.x;}
    bool upp()const{return y>0||(y==0&&x>0);}
    bool operator<(const poi&p)const{
        if(upp()!=p.upp())return upp();
        return *this*p>0;
    }
    void scan(){scanf("%lld%lld",&x,&y);}
}a[N];
int T,n;
int main(){
    for(scanf("%d",&T);T--;){
        scanf("%d",&n);
        rep(i,n)a[i].scan();
        sort(a+1,a+n+1);
        int ans=n,ptr=1;
        rep(i,n){
            while(ptr%n+1!=i&&a[i]*a[ptr%n+1]>=0)ptr=ptr%n+1;
            ans=min(ans,(i-ptr-1+n)%n);
            if(ptr==i)++ptr;
        }
        printf("%d\n",ans);
    }
    return 0;
}
/*


*/
