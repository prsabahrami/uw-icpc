#include <stdio.h>
#include <math.h>
#include <assert.h>

#define MAX_NODES 1010
double graph[MAX_NODES][MAX_NODES];
double D[MAX_NODES];
int x[MAX_NODES], y[MAX_NODES];

#define DISCONNECT -1

void dijkstra(double graph[MAX_NODES][MAX_NODES], int n, int src, double *D)
{
  char used[MAX_NODES];
  double fringe[MAX_NODES];
  int f_size;
  int v, w, j, wj;
  double best;
  int best_init;

  f_size = 0;
  for (v = 0; v < n; v++) {
    if (graph[src][v] != DISCONNECT) {
      D[v] = graph[src][v];
      fringe[f_size++] = v;
      used[v] = 1;
    } else {
      D[v] = DISCONNECT;
      used[v] = 0;
    }
  }
  used[src] = 1;
  best_init = 1;
  while (best_init) {
    /* find unused vertex with smallest D */
    best_init = 0;
    for (j = 0; j < f_size; j++) {
      v = fringe[j];
      assert(D[v] != DISCONNECT);
      if (!best_init || D[v] < best) {
        best = D[v];
        w = v;
        wj = j;
        best_init = 1;
      }
    }

    if (best_init) {
      assert(D[w] != DISCONNECT);
      assert(fringe[wj] == w);

      /* get rid of w from fringe */
      f_size--;
      for (j = wj; j < f_size; j++) {
        fringe[j] = fringe[j+1];
      }
     /* update distances and add new vertices to fringe */
      for (v = 0; v < n; v++) {
        if (v != src && graph[w][v] != DISCONNECT) {
          if (D[v] == DISCONNECT || D[w] + graph[w][v] < D[v]) {
            D[v] = D[w] + graph[w][v];
          } else if (D[w] + graph[w][v] == D[v]) {
            /* put tie-breaker here */
          }
          if (!used[v]) {
            used[v] = 1;
            fringe[f_size++] = v;
          }
        }
      }
    }
  }
  D[src] = 0;
}

double hyp(double x, double y) {
  return sqrt(x*x+y*y);
}

int main () {
  int n, first, i, j, X, Y;
  for(i=0;i<MAX_NODES;i++) for(j=0;j<MAX_NODES;j++) 
    graph[i][j] = i==j ? 0.0 : 10e99;
  scanf("%d%d%d%d",&x[0],&y[0],&x[1],&y[1]);
  n = 2; first = 2;
  while (1) {
    if (scanf("%d%d",&X,&Y) != 2) break;
    if (X == -1 && Y == -1) {
      /* process this subway line - fill the graph from first to n-1 */
      for(i=first;i<n-1;i++)
	graph[i][i+1] = graph[i+1][i] = 
	  hyp(x[i]-x[i+1],y[i]-y[i+1])/(40000.0/60.0);
      first = n;
      continue;
    };
    x[n]=X; y[n]=Y; n++; 
  }
  /*fill the remaining distances */
  for(i=0;i<n;i++) 
    for(j=i+1;j<n;j++) {
      double d=hyp(x[i]-x[j],y[i]-y[j])/(10000.0/60.0);
      if (d < graph[i][j])
	graph[i][j] = graph[j][i] = d;
    }

  dijkstra(graph, n, 0, D);

  printf("%.0f\n",D[1]);
  
  return 0;
}
