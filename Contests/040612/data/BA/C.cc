#include <cstdio>
#include <cstdlib>
#include <string>
#include <utility>
#include <vector>
#include <set>

int main()
{
	int cnum,nc,i,n,N,M,L,cost;
	char name[105][32];
	int A[105],B[105];

	scanf("%d ", &nc);
	for (cnum=1; cnum<=nc; cnum++) {
		set<pair<int,string> >::iterator ii;
		set<pair<int,string> > ss;
		printf("Case %d\n", cnum);
		scanf("%d %d %d ", &N, &M, &L);
		for (i=0; i<L; i++) {
			scanf("%[^:]: %d, %d ", name[i], &A[i], &B[i]);
			n = N;
			cost = 0;
			while(n/2>=M && B[i]<=(n-n/2)*A[i]) {
				n /= 2;
				cost += B[i];
			}
			cost += (n-M)*A[i];
			string sss = name[i];
			ss.insert(make_pair(cost,sss));
		}
		for (ii=ss.begin(); ii!=ss.end(); ii++) 
			printf("%s %d\n", (ii->second).c_str(), ii->first);
	}
	return 0;
}
