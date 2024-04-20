#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
using namespace std;

#define MAXN 1000

int sets[MAXN];

int getRoot(int x){
  if(sets[x] < 0) return x;
  return sets[x] = getRoot(sets[x]);
}

void Union(int a, int b){
  int ra = getRoot(a);
  int rb = getRoot(b);

  if(ra != rb){
    sets[ra] += sets[rb];
    sets[rb] = ra;
  }
}

int used[256],type[256],linker[256];
vector<int> strct[256];
int eq[256][256];
int seen[256][256];

int getprim(int a)
{
	if (type[a] >= 0 && type[a] <= 3) return a;
	return getprim(linker[a]);
}

int compare(int a, int b)
{
	int i,ac,bc;
	if (seen[a][b]) {
		if (!eq[a][b]) return 0;
		return 1;
	}
	seen[a][b] = seen[b][a] = 1;
	if (strct[a].size() != strct[b].size()) return 0;
	for (i=0; i<strct[a].size(); i++) {
		ac = strct[a][i];
		bc = strct[b][i];
		if (ac == bc) continue;
		if (ac < 5 && bc < 5) {
			if (strct[a][i] != strct[b][i]) return 0;
		} else if (ac > 5 && bc > 5) {
			if (!eq[ac][bc]) return 0;
			if (!compare(ac,bc)) return 0;			
		} else return 0;
	}	
	//	seen[a][b] = seen[b][a] = 0;
	return 1;
}

int main()
{
	int i,j,k;
	char str[1024], nm[16],ty[16];
	int done = 0;
	int first = 1;
	while (!done) {
		memset(used,0,sizeof(used));
		memset(type,-1,sizeof(type));
		for (i=0; i<256; i++) strct[i].clear();
				
		while (1) {
			fgets(str,1024,stdin);
			//printf("%s",str);
			if (str[0]=='-') break;
			sscanf(str,"type %s = %n", nm, &i);
			used[nm[0]] = 1;
			if (str[i] == 's') {
				type[nm[0]] = 0;
				k = strlen(str);
				for (; i<k; i++) if (str[i] == '(') break;
				for (i++; i<k; i++) {
					if (str[i] == ')') break;
					if (str[i] == ' ') continue;
					strct[nm[0]].push_back((int)str[i]);
				}					
			} else {
				sscanf(&str[i], "%s", ty);
				if (!strcmp(ty,"int")) type[nm[0]] = 1;
				else if (!strcmp(ty,"real")) type[nm[0]] = 2;
				else if (!strcmp(ty,"char")) type[nm[0]] = 3;
				else linker[nm[0]] = ty[0];
			}
		}
		if (str[1] == '-') done = 1;
		if (!first) printf("\n");
		first = 0;
		for (i='A'; i<='Z'; i++) {
			if (used[i] && type[i]==-1) {
				j = getprim(i);
				type[i] = type[j];
				if (!type[i]) {
					for (k=0; k<strct[j].size(); k++)
						strct[i].push_back(strct[j][k]);
				}
			}
		}
		for (i='A'; i<='Z'; i++) {
			if (!used[i] || type[i]) continue;
			for (j=0; j<strct[i].size(); j++) 
				if (type[strct[i][j]]) strct[i][j] = type[strct[i][j]];
		}

		memset(eq, -1, sizeof(eq));
		for (i='A'; i<='Z'; i++) {
			if (!used[i]) continue;
			for (j=i+1; j<='Z'; j++) {
				if (!used[j]) continue;
				if (type[i] != type[j]) {
					eq[i][j] = eq[j][i] = 0;
				} else if (!type[i]) {
					memset(seen,0,sizeof(seen));
					if (!compare(i,j)) {
						eq[i][j] = eq[j][i] = 0;
					}
				}
			}
		}
		memset(sets, -1, sizeof(sets));
		for (i='A'; i<='Z'; i++) {
			if (!used[i]) continue;
			for (j=i+1; j<='Z'; j++) {
				if (!used[j]) continue;
				if (eq[i][j]) Union(i,j);
			}
		}
		for (i='A'; i<='Z'; i++) {
			if (!used[i]) continue;
			printf("%c", i);
			for (j=i+1; j<='Z'; j++) if (getRoot(j) == i) {
				printf(" %c", j);
				used[j] = 0;
			}
			printf("\n");
		}
	}
	return 0;
}
