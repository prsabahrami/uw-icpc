#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct {
	int x,y;
} Point;

#define MAX 200005

int n;
Point pt1[MAX], pt2[MAX];
int bl[MAX],br[MAX];

int sortxy(const void *xa, const void *xb)
{
	Point *a = (Point *)xa;
	Point *b = (Point *)xb;
	if (a->x == b->x) return a->y - b->y;
	return a->x - b->x;
}

void doit(Point *pt, int *out)
{
	int i,j,lo,hi,left;
	set<int> yc;
	for (i=0; i<n; i++) yc.insert(pt[i].y);
	vector<int> lst(yc.begin(),yc.end());
	int ny = lst.size();
	vector<int> cnt(ny, 0);

	for (i=0; i<n; i++) {
		left = 0;
		lo = 0; hi = ny;
		for (;;) {
			j = (hi+lo)/2;
			if (lst[j] == pt[i].y) { left += cnt[j]; break; }
			if (lo+1 == hi) { break; }
			if (pt[i].y < lst[j]) {
				hi = j;
				cnt[j]++;
			} else {
				lo = j;
				left += cnt[j];
			}
		}
		cnt[j]++; left++;
		assert(lst[j] == pt[i].y);
		out[i] = left;
	}
}

int main()
{
	int i,j,k,x,y,stan,olie,best;
	while (scanf("%d ", &n)==1 && n) {
 	        set<int>::iterator ii;
		map<int,int> numx,numy;
		map<int,pair<int,int> > bestx;
		memset(bl, 0, sizeof(bl));
		memset(br, 0, sizeof(br));
		for (i=0; i<n; i++) {
			scanf("%d %d ", &pt1[i].x, &pt1[i].y);
			bestx[pt1[i].x] = make_pair(2*n,0);
		}
		qsort(pt1, n, sizeof(Point), sortxy);
		for (i=0; i<n; i++) {
			numx[pt1[i].y]++; numy[pt1[i].x]++;
			pt2[i].x = -pt1[i].x;
			pt2[i].y = -pt1[i].y;
		}
		doit(pt1, bl);
		qsort(pt2, n, sizeof(Point), sortxy);
		doit(pt2, br);

		for (i=0; i<n; i++) {
			x = pt1[i].x, y = pt1[i].y;
			stan = bl[i] + br[n-1-i] - numx[y] - numy[x];
			olie = n - stan - numx[y] - numy[x] + 1;
			if ((bestx[x].first > stan) ||
			    (bestx[x].first == stan && bestx[x].second < olie))
				bestx[x] = make_pair(stan,olie);
		}

		set<int> os;
		map<int,pair<int,int> >::iterator jj;
		best = -1;
		for (jj=bestx.begin(); jj!=bestx.end(); ++jj) {
			if (jj->second.first == best) 
			        os.insert(jj->second.second);
			else if (jj->second.first > best) {
				best = jj->second.first;
				os.clear();
				os.insert(jj->second.second);
			}
		}
		printf("Stan: %d; Ollie:", best);
		for (ii=os.begin(); ii!=os.end(); ++ii) printf(" %d", *ii);
		printf(";\n");
	}
	return 0;
}
