#define DEBUG 0
 
#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <complex>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <sstream>
using namespace std;
 
#define LL long long
#define LD long double
#define PR pair<int,int>
 
#define Fox(i,n) for (i=0; i<n; i++)
#define Fox1(i,n) for (i=1; i<=n; i++)
#define FoxI(i,a,b) for (i=a; i<=b; i++)
#define FoxR(i,n) for (i=(n)-1; i>=0; i--)
#define FoxR1(i,n) for (i=n; i>0; i--)
#define FoxRI(i,a,b) for (i=b; i>=a; i--)
#define Foxen(i,s) for (i=s.begin(); i!=s.end(); i++)
#define Min(a,b) a=min(a,b)
#define Max(a,b) a=max(a,b)
#define Sz(s) int((s).size())
#define All(s) (s).begin(),(s).end()
#define Fill(s,v) memset(s,v,sizeof(s))
#define pb push_back
#define mp make_pair
#define x first
#define y second
 
template<typename T> T Abs(T x) { return(x<0 ? -x : x); }
template<typename T> T Sqr(T x) { return(x*x); }
string plural(string s) { return(Sz(s) && s[Sz(s)-1]=='x' ? s+"en" : s+"s"); }
 
const int INF = (int)1e9;
const LD EPS = 1e-12;
const LD PI = acos(-1.0);
 
//#if DEBUG
#define GETCHAR getchar
/*#else
#define GETCHAR getchar_unlocked
#endif*/
 
bool Read(int &x)
{
	char c,r=0,n=0;
	x=0;
		for(;;)
		{
			c=GETCHAR();
				if ((c<0) && (!r))
					return(0);
				if ((c=='-') && (!r))
					n=1;
				else
				if ((c>='0') && (c<='9'))
					x=x*10+c-'0',r=1;
				else
				if (r)
					break;
		}
		if (n)
			x=-x;
	return(1);
}

struct PT { 
  LD x, y; 
  PT() {}
  PT(LD x, LD y) : x(x), y(y) {}
  PT(const PT &p) : x(p.x), y(p.y)    {}
  PT operator + (const PT &p)  const { return PT(x+p.x, y+p.y); }
  PT operator - (const PT &p)  const { return PT(x-p.x, y-p.y); }
  PT operator * (LD c)     const { return PT(x*c,   y*c  ); }
  PT operator / (LD c)     const { return PT(x/c,   y/c  ); }
};

LD dot(PT p, PT q)     { return p.x*q.x+p.y*q.y; }
LD dist2(PT p, PT q)   { return dot(p-q,p-q); }
LD cross(PT p, PT q)   { return p.x*q.y-p.y*q.x; }

// rotate a point CCW or CW around the origin
PT RotateCCW90(PT p)   { return PT(-p.y,p.x); }
PT RotateCW90(PT p)    { return PT(p.y,-p.x); }
PT RotateCCW(PT p, LD t) { 
  return PT(p.x*cos(t)-p.y*sin(t), p.x*sin(t)+p.y*cos(t)); 
}

// project point c onto line through a and b
// assuming a != b
PT ProjectPointLine(PT a, PT b, PT c) {
  return a + (b-a)*dot(c-a, b-a)/dot(b-a, b-a);
}

// compute distance from c to line through a and b
LD DistancePointLine(PT a, PT b, PT c) {
  return sqrt(dist2(c, ProjectPointLine(a, b, c)));
}

LL Cross(PR A,PR B,PR C)
{
	LL X1=B.x-A.x;
	LL Y1=B.y-A.y;
	LL X2=C.x-A.x;
	LL Y2=C.y-A.y;
	return(X1*Y2 - X2*Y1);
}

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int N,M;
	int i,a,b,c;
	LD cur,nxt,ans,d1,d2,d3;
	static PR P[100000],H[100001];
	Read(N);
		Fox(i,N)
			Read(P[i].x),Read(P[i].y);
	sort(P,P+N);
	//create convex hull
	M=0;
		Fox(i,N)
		{
				while ((M-2>=0) && (Cross(H[M-2],H[M-1],P[i])<=0))
					M--;
			H[M++]=P[i];
		}
	a=M;
		FoxR(i,N)
		{
				while ((M>a) && (Cross(H[M-2],H[M-1],P[i])<=0))
					M--;
			H[M++]=P[i];
		}
	M--;
	a=b=1;
	ans=(LD)INF*INF;
		Fox(i,M)
		{
			//create line for this edge
			PT p1(H[i].x,H[i].y);
			PT p2(H[i+1].x,H[i+1].y);
			//create perpendicular bisector to this edge
			PT p3((LD)(H[i].x+H[i+1].x)/2,(LD)(H[i].y+H[i+1].y)/2);
			PT v(H[i+1].x-H[i].x,H[i+1].y-H[i].y);
			PT p4=p3+RotateCW90(v);
			//update a (furthest point from edge)
				for(;;)
				{
					cur=DistancePointLine(p1,p2,PT(H[a].x,H[a].y));
					nxt=DistancePointLine(p1,p2,PT(H[a+1].x,H[a+1].y));
						if (nxt>cur-EPS)
							a=(a+1)%M;
						else
							break;
				}
			d1=cur;
			//update b (furthest point on the first side)
				for(;;)
				{
					cur=DistancePointLine(p3,p4,PT(H[b].x,H[b].y));
						if (cross(p4-p3,PT(H[b+1].x,H[b+1].y)-p3)<0)
							break;
					nxt=DistancePointLine(p3,p4,PT(H[b+1].x,H[b+1].y));
						if (nxt>cur-EPS)
							b=(b+1)%M;
						else
							break;
				}
			d2=cur;
			//update c (furthest point on the second side)
				if (!i)
				{
					c=M;
						while (cross(p4-p3,PT(H[c-1].x,H[c-1].y)-p3)<0)
							c--;
					c%=M;
				}
				for(;;)
				{
					cur=DistancePointLine(p3,p4,PT(H[c].x,H[c].y));
						if (cross(p4-p3,PT(H[c+1].x,H[c+1].y)-p3)>0)
							break;
					nxt=DistancePointLine(p3,p4,PT(H[c+1].x,H[c+1].y));
						if (nxt>cur-EPS)
							c=(c+1)%M;
						else
							break;
				}
			d3=cur;
			//calculate current rectangle
			cur=d1*(d2+d3);
			Min(ans,cur);
		}
	printf("%.0Lf\n",ans);
	return(0);
}