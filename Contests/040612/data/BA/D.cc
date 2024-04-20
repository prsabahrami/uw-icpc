#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <utility>
#include <vector>
#include <map>

#define MAX 15

void swap(int *a, int *b) { int t; t = *a; *a = *b; *b = t; }
int main()
{
	int cs,cnum,i,j,s,n,tt;
	int hlim[MAX], vlim[MAX];
	int xs,ys,xe,ye,st,et,unit;

	scanf("%d ", &cnum);
	for (cs=1; cs<=cnum; cs++) {
		map<int,double> mm[MAX][MAX];
		map<int,double>::iterator k;
		printf("Scenario %d:\n",cs);
		scanf("%d %d ", &n, &unit);
		for (i=1; i<=n; i++) scanf("%d ", &hlim[i]);
		for (i=1; i<=n; i++) scanf("%d ", &vlim[i]);
		scanf("%d %d %d %d %d %d ", &xs,&ys,&xe,&ye,&st,&et);
		if (xs > xe) {
			for (i=1; i<=n/2; i++) swap(&vlim[i], &vlim[n+1-i]);
			xs = n+1-xs; xe = n+1-xe;
		}
		if (ys > ye) {
			for (i=1; i<=n/2; i++) swap(&hlim[i], &hlim[n+1-i]);
			ys = n+1-ys; ye = n+1-ye;
		}
		mm[ys][xs][0] = 0.0;
		for (i=ys; i<=ye; i++) for (j=xs; j<=xe; j++) { 
			for (s=5; s<=hlim[i]; s+=5) {
				int t = (unit*7*3600/s);
				double g = unit/(80-0.03*s*s);
				for (k=mm[i][j].begin(); k!=mm[i][j].end(); ++k) {
					tt = t + k->first;
					//tt = (tt + 3)/7*7; // round to nearest sec?
					if (tt > et*7*60) continue;
					if (mm[i][j+1][tt] < 1e-8 || 
					    mm[i][j+1][tt] > k->second+g){
						mm[i][j+1][tt]=k->second+g;
					}
				}
			}
			for (s=5; s<=vlim[j]; s+=5) {
				int t = (unit*7*3600/s);
				double g = unit/(80-0.03*s*s);
				for (k=mm[i][j].begin(); k!=mm[i][j].end(); ++k) {
					tt = t + k->first;
					//tt = (tt + 3)/7*7; // round to nearest sec?
					if (mm[i+1][j][tt] < 1e-8 || 
					    mm[i+1][j][tt] > k->second+g) {
						mm[i+1][j][tt]= k->second+g;
					}
				}
			}
		}
		double gg=1e10;
		int good = 0, first = 1, gt = (int)1e10;
		for (k=mm[ye][xe].begin(); k!=mm[ye][xe].end(); ++k) {
			if (k->first >= st*7*60 && k->first <= et*7*60) {
				if (first) printf("The earliest  arrival: %d minutes, fuel %.2lf gallons\n", (k->first+7*60-1)/(7*60), k->second);
				good = 1; first = 0;
				if (k->second < gg) {
					gg = k->second;
					gt = k->first;
				}
			}
		}
		if (!good) printf("IMPOSSIBLE\n"); 
		else printf("The economical travel: %d minutes, fuel %.2lf gallons\n",
			    (gt+60*7-1)/(7*60), gg);
	}
	return 0;
}
