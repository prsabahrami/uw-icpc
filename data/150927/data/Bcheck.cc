// special judge for a
//
// usage : first 3 lines in main function
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define FOR(i,s,e) for(int i=(s);i<(int)(e);i++)
#define FOE(i,s,e) for(int i=(s);i<=(int)(e);i++)
#define CLR(s) memset(s,0,sizeof(s))
#define PB push_back
using namespace std;
typedef vector<int> vi;

const int VX = 55;
int  g[VX][VX];
bool vis[VX];
vi h[VX];       // ans
int n, m;

int gao(int u, bool *vis, vi *g) {
	if(vis[u]) return 0;
	int ret = vis[u] = 1;
	FOR(i,0,g[u].size())
		ret += gao(g[u][i], vis, g);
	return ret;
}

int main(int argc, char **argv){
  char buf[100];
  strcpy(buf,argv[0]);
  strcpy(buf+strlen(buf)-3,"dat");
  FILE *fin = fopen(buf,"r"); // judge input
  strcpy(buf,argv[0]);
  strcpy(buf+strlen(buf)-3,"diff");
  FILE *fans = fopen(buf,"r"); // judge output
	FILE *fout = stdin;       // contestant output

	int T;
	fscanf(fin,"%d", &T);
	FOE(ca,1,T) {
//	      printf("Checking #%d...\n", ca);
		fscanf(fin,"%d%d", &n, &m);
//	      printf("n=%d m=%d\n", n, m);
		vi h[n+1];

		CLR(g);

		// read input
		FOR(j,0,m) {
			int x, y;
			fscanf(fin,"%d%d", &x, &y);
			g[x][y]++;
			g[y][x]++;
		}

		// read judge output (yes / no)
		char s[65], t[65];
		fscanf(fans,"%s",s);
		fscanf(fout,"%s",t);

		// check correctness

		// YES / NO unmatched
		if (strcmp(s,t)) {
			printf("WA at #%d : Output = \"%s\"; Expected = \"%s\"\n", ca, t, s);
			exit(2);
		}

		// verify good content in graph
		if (*s=='Y') {
			int x, y;
			FOR(j,0,m) {
				fscanf(fans, "%*d%*d");
				fscanf(fout, "%d%d", &x, &y);
				if (x<1 || y<1 || x>n || y>n) {
					printf("WA at #%d - invalid edge: (%d %d) (n=%d)\n", ca, x, y, n);
					exit(2);
				}
				g[x][y]--;
				g[y][x]--;
				h[x].PB(y);
			}
			FOE(i,1,n) FOE(j,1,n) {
				if(g[x][y] != 0) {
					printf("WA at #%d - not all edges are used\n", ca, x, y);
					exit(2);
				}
			}

			bool scc = 1;
			FOE(i,1,n) if (scc) {
				bool vis[n+1];
				CLR(vis);
				scc = (gao(i, vis, h)==n);
			}
			if (!scc) {
				printf("WA at #%d - graph is not strongly connected\n", ca);
				exit(2);
			}
		}
	}
	printf("AC!! (Passed all %d test cases)\n", T);
	return 0;
}
