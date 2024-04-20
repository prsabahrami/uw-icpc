#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

int main()
{
	int i,n,pt[200005][2],stan,olie,x,y;

	while (scanf("%d ", &n)==1 && n) {
		for (i=0; i<n; i++) scanf("%d %d ", &pt[i][0],&pt[i][1]);
		x = pt[n/2][0];
		y = pt[n/2][1];
		stan = olie = 0;
		for (i=0; i<n; i++) {
			if ((pt[i][0] > x && pt[i][1] > y) ||
			    (pt[i][0] < x && pt[i][1] < y)) {
				stan++;
			}
			if ((pt[i][0] > x && pt[i][1] < y) ||
			    (pt[i][0] < x && pt[i][1] > y)) {
				olie++;
			}
		}
		printf("%d %d\n", stan, olie);
	}
	return 0;
}
