#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

/* " NSEW" */
int dx[5] = {0,0,0,1,-1};
int dy[5] = {0,-1,1,0,0};

char grid[30][31];
int n;
int Hx, Hy, Sx, Sy, hx, hy, sx, sy;
int *queue = 0;

void dump(int jackx, int jacky, int jillx, int jilly)
{
  int i, j;

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (j == jackx && i == jacky) {
	putchar('J');
      } else if (j == jillx && i == jilly) {
	putchar('j');
      } else {
	putchar(grid[i][j]);
      }
    }
    putchar('\n');
  }
  putchar('\n');
}

void check(char *jack, char *jill)
{
  int jackx, jacky, jillx, jilly;
  double dist, t;
  
  jackx = Hx; jacky = Hy; jillx = hx; jilly = hy;
  dist = sqrt((jackx-jillx)*(jackx-jillx)+(jacky-jilly)*(jacky-jilly));
  while (*jack || *jill) {
    switch (*jack) {
      case 'N':
	jacky--;
	break;
      case 'S':
	jacky++;
	break;
      case 'E':
	jackx++;
	break;
      case 'W':
	jackx--;
	break;
    }

    switch (*jill) {
      case 'N':
	jilly--;
	break;
      case 'S':
	jilly++;
	break;
      case 'E':
	jillx++;
	break;
      case 'W':
	jillx--;
	break;
    }

    if (*jack) jack++;
    if (*jill) jill++;
    t = sqrt((jackx-jillx)*(jackx-jillx)+(jacky-jilly)*(jacky-jilly));
    if (t < dist) dist = t;
  }
  printf("%.2f\n", dist);
  assert(jackx == Sx && jacky == Sy && jillx == sx && jilly == sy);
}

int index2node(int jackx, int jacky, int jillx, int jilly)
{
  return ((jackx*n+jacky)*n+jillx)*n+jilly;
}

void node2index(int index, int *jackx, int *jacky, int *jillx, int *jilly)
{
  *jilly = index % n;
  index /= n;
  *jillx = index % n;
  index /= n;
  *jacky = index % n;
  index /= n;
  *jackx = index % n;
}

void find_dirs(int w, int v, char *jack, char *jill, int i)
{
  int wjackx, wjacky, wjillx, wjilly;
  int vjackx, vjacky, vjillx, vjilly;

  node2index(w, &wjackx, &wjacky, &wjillx, &wjilly);
  node2index(v, &vjackx, &vjacky, &vjillx, &vjilly);
  if (vjackx == wjackx - 1) {
    jack[i] = 'W';
  } else if (vjackx == wjackx + 1) {
    jack[i] = 'E';
  } else if (vjacky == wjacky - 1) {
    jack[i] = 'N';
  } else if (vjacky == wjacky + 1) {
    jack[i] = 'S';
  } else {
    jack[i] = 0;
  }
    
  if (vjillx == wjillx - 1) {
    jill[i] = 'W';
  } else if (vjillx == wjillx + 1) {
    jill[i] = 'E';
  } else if (vjilly == wjilly - 1) {
    jill[i] = 'N';
  } else if (vjilly == wjilly + 1) {
    jill[i] = 'S';
  } else {
    jill[i] = 0;
  }
}

int path_exist(char *jack, char *jill, int d2)
{
  int jackx, jacky, jillx, jilly;
  int jack2x, jack2y, jill2x, jill2y;
  char used[30*30*30*30];
  int P[30*30*30*30];
  int D[30*30*30*30];
  int q_in, q_out, i, j, v, w;
  int src, dest, found;

  if (!queue) {
    queue = malloc((30*30*30*30+1)*sizeof(int));
  }
  memset(used, 0, n*n*n*n);
  src = index2node(Hx, Hy, hx, hy);
  dest = index2node(Sx, Sy, sx, sy);

  queue[0] = src;
  used[src] = 1;
  q_in = 1;
  q_out = 0;
  for (i = 0; i < n*n*n*n; i++) {
    P[i] = -1;
    D[i] = -1;
  }
  D[src] = 0;

  found = 0;
  while (q_out < q_in && !found) {
    v = queue[q_out++];
    node2index(v, &jackx, &jacky, &jillx, &jilly);
    for (i = 0; i < 5; i++) {
      if (i == 0 && grid[jacky][jackx] != 'S') continue;
      jack2x = jackx + dx[i];
      jack2y = jacky + dy[i];
      if (jack2x < 0 || jack2x >= n) continue;
      if (jack2y < 0 || jack2y >= n) continue;
      if (grid[jack2y][jack2x] == '*' ||
	  grid[jack2y][jack2x] == 'h' ||
	  grid[jack2y][jack2x] == 's') continue;

      for (j = 0; j < 5; j++) {
	if (j == 0 && grid[jilly][jillx] != 's') continue;
	jill2x = jillx + dx[j];
	jill2y = jilly + dy[j];
	if (jill2x < 0 || jill2x >= n) continue;
	if (jill2y < 0 || jill2y >= n) continue;
	if (grid[jill2y][jill2x] == '*' ||
	    grid[jill2y][jill2x] == 'H' ||
	    grid[jill2y][jill2x] == 'S') continue;
	if ((jack2x-jill2x)*(jack2x-jill2x)+(jack2y-jill2y)*(jack2y-jill2y) <
	    d2) continue;

	/* after all this, it is okay to add node */
	w = index2node(jack2x, jack2y, jill2x, jill2y);
	if (!used[w]) {
	  D[w] = D[v] + 1;
	  P[w] = v;
	  queue[q_in++] = w;
	  used[w] = 1;
	}
	if (w == dest) {
	  found = 1;
	}
      }
    }
  }

  if (found) {
    /* now we construct the path */
    i = 0;
    jack[D[dest]] = jill[D[dest]] = 0;
    for (v = dest; v != src; v = P[v]) {
      w = P[v];
      find_dirs(w, v, jack, jill, D[dest]-1-i);
      i++;
    }
  }
  return found;
}

void find_path(char *jack, char *jill)
{
  int lo, hi, mid;
  char tjack[8*60+1], tjill[8*60+1];

  lo = 0;
  hi = (Hx-hx)*(Hx-hx)+(Hy-hy)*(Hy-hy);

  while (hi - lo > 1) {
    mid = (lo + hi)/2;
    if (path_exist(tjack, tjill, mid)) {
      strcpy(jack, tjack);
      strcpy(jill, tjill);
      lo = mid;
    } else {
      hi = mid;
    }
  }
}

int main(void)
{
  int i, j;
  char jack[8*60+1], jill[8*60+1];
  int t1, t2;
  int first = 1;
  
  while (scanf("%d", &n) == 1 && n > 0) {
    if (first) {
      first = 0;
    } else {
      printf("\n");
    }
    for (i = 0; i < n; i++) {
      scanf("%s", grid[i]);
    }

    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
	switch (grid[i][j]) {
	  case 'H':
	    Hx = j; Hy = i;
	    break;
	  case 'S':
	    Sx = j; Sy = i;
	    break;
	  case 'h':
	    hx = j; hy = i;
	    break;
	  case 's':
	    sx = j; sy = i;
	    break;
	} 
      }
    }

    find_path(jack, jill);
    t1 = strlen(jack);
    t2 = strlen(jill);
    if (t1 < t2) {
      t1 = t2;
    }
    check(jack, jill);
    t1 = 9*60-t1;
    //printf("%02d:%02d\n", t1/60, t1%60);
    printf("%s\n", jack);
    printf("%s\n", jill);
    /*
    */
  }
  return 0;
}
