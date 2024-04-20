/*
ID: gawry1
LANG: C++
PROG: class
*/
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cassert>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
#define INF 2000000000
int C,T,L,r[25][7500];
typedef pair<int,int> p2;
p2 t[25][7500];
main(){
//  freopen("class.in","r",stdin);
//  freopen("class.out","w",stdout);  
  
  int c;
  scanf("%d",&c);
  assert(c<=20);
  while(c--){
    scanf("%d %d %d",&C,&T,&L);
    assert(1<=C&&C<=25);
    assert(1<=T&&T<=7500);
    assert(1<=L<=1000000);
    for(int i=0;i<C;i++){
      for(int j=0;j<T;j++){
        scanf("%d %d",&t[i][j].first,&t[i][j].second);
        assert(0<=t[i][j].first&&t[i][j].first<=L);
        assert(1<=t[i][j].second&&t[i][j].second<=1000000);  
      }
      sort(t[i],t[i]+T);
      if(!i){
        for(int j=0;j<T;j++)r[0][j]=t[0][j].second+t[0][j].first;
      }else{
        for(int j=0,k=0,best=INF;j<T;j++){
          while(k<T&&t[i-1][k].first<=t[i][j].first)best=min(best,r[i-1][k]-t[i-1][k].first),k++;
          r[i][j]=best+t[i][j].second+t[i][j].first;
        }
        for(int j=T-1,k=T-1,best=INF;j>=0;j--){
          while(k>=0&&t[i-1][k].first>=t[i][j].first)best=min(best,r[i-1][k]+t[i-1][k].first),k--;
          r[i][j]=min(r[i][j],best+t[i][j].second-t[i][j].first);
        }
      }
    }
    int ans=INF;
    for(int j=0;j<T;j++)ans=min(ans,r[C-1][j]+L-t[C-1][j].first);
    printf("%d\n",ans);
  }
}
