#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define MC 1000

int cost[110][4][4][3];
int prev[110][4][4][3];

void update(int i, int sl, int sr, int sm, int nl, int nr, int nm) {
  int v, from, to;
  assert(sl == nl || sr == nr);
  if (nl == nr) return;
  if (nl == 2 && nr == 0) return;
  if (nl == 1 && nr == 0 && nm == 1 && nl != sl) return;
  if (nl == 3 && nr == 0 && nm == 1 && nl != sl) return;
  if (nr == 1 && nl == 2 && nm == 2 && nr != sr) return;
  if (nr == 3 && nl == 2 && nm == 2 && nr != sr) return;
  if (!nm) 
    if (cost[i][sl][sr][sm] <= cost[i+1][nl][nr][nm]) {
      cost[i+1][nl][nr][nm] = cost[i][sl][sr][sm];
      prev[i+1][nl][nr][nm] = sl*100+sr*10+sm;	      
    }
  if (sm != nm) v = 1;
  else {
    if (sl == nl) { from = sr; to = nr; }
    if (sr == nr) { from = sl; to = nl; }
    if (from == to) v = 3;
    else if (abs(from-to)%2 == 1) v = 5;
    else if (abs(from-to)%2 == 0) v = 7;
    else assert(0);
  }
  if (cost[i][sl][sr][sm]+v <= cost[i+1][nl][nr][nm]) {
    cost[i+1][nl][nr][nm] = cost[i][sl][sr][sm]+v;
    prev[i+1][nl][nr][nm] = sl*100+sr*10+sm;	      
  }
}

void print(int n, int L, int R, int M) {
  if (!n) return;
  int a = prev[n][L][R][M];
    print(n-1,a/100, (a%100)/10, a%10);
  printf(!M ? "." : M == 1 ? "L" : "R");
}

int main () {
  char line[200];
  while (fgets(line,110,stdin) != NULL) {
    if (line[0] == '#') break;
    line[strlen(line)-1] = 0;
    int n = strlen(line);
    memset(cost,0,sizeof(cost));
    memset(prev,0,sizeof(prev)); 
    for (int i = 0; i <= n+1; i++) 
      for(int l=0;l<4;l++) 
	for(int r=0;r<4;r++) 
	  for(int m=0;m<3;m++) cost[i][l][r][m] = 1000;
    cost[0][0][2][0] = 0;
    for (int i = 0; i < n; i++) {
      for(int l=0;l<4;l++) for(int r=0;r<4;r++) for(int m=0;m<3;m++) {
	if (l == r) continue;
	if (l == 2 && r == 0) continue;
	  switch(line[i]) {
	  case 'L':
	    update(i,l,r,m,0,r,1); 
	    update(i,l,r,m,l,0,2); 
	    break;
	  case 'U':
	    update(i,l,r,m,1,r,1); 
	    update(i,l,r,m,l,1,2); 
	    break;
	  case 'R':
	    update(i,l,r,m,2,r,1); 
	    update(i,l,r,m,l,2,2); 
	    break;
	  case 'D':
	    update(i,l,r,m,3,r,1); 
	    update(i,l,r,m,l,3,2); 
	    break;
	  case '.':
	    update (i, l, r, m, l, r, 0);
	    update (i, l, r, m, 0, r, 1);
	    update (i, l, r, m, 1, r, 1);
	    update (i, l, r, m, 2, r, 1);
	    update (i, l, r, m, 3, r, 1);
	    update (i, l, r, m, l, 0, 2);
	    update (i, l, r, m, l, 1, 2);
	    update (i, l, r, m, l, 2, 2);
	    update (i, l, r, m, l, 3, 2);
	    break;
	  default: printf("Wrong move: %c \n", line[i]);
	    exit(1);
	  }
      }
    }
    int best = 1000, L, R, M;
    for(int l=0;l<4;l++) for(int r=0;r<4;r++) for(int m=0;m<3;m++) 
      if (cost[n][l][r][m] < best) {
	best = cost[n][l][r][m];
	L = l; R = r; M = m;
      }
    print(n, L, R, M);
    printf("\n");
  }
}

