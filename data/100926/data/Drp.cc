#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int RNG = 100;
const int ZERO = 50;

int dir[8][2] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
{1, -2}, {1, 2}, {2, -1}, {2, 1}};

int d[RNG][RNG];
int q[RNG*RNG][2], tail;

void add(int r1, int c1, int d1) {
  if(d[r1][c1] == -1) {
    d[r1][c1] = d1;
    q[tail][0] = r1; 
    q[tail++][1] = c1;
  }
}

int moo(int x, int y) {
  x = abs(x);
  y = abs(y);
  if(x < y) swap(x, y);
  if(x < 20 && y < 20) return d[ZERO + x][ZERO + y];
  if(y == 0) {
    int k = max(0, (x - 10) / 4);
    return k * 2 + moo(x - k * 4, 0);
  }
  else if(x < y + 3) {
    int k = max(0, (y - 10) / 3);
    return k * 2 + moo(x - k * 3, y - k * 3);
  }
  else {
    int k = min(min(x - y, y), max(x / 2, y) - 5);
    return k + moo(x - k * 2, y - k);
  } 
}

char line[1234];
int main() {
  for(int i = 0; i < RNG; ++i)
    for(int j = 0; j < RNG; ++j)
      d[i][j] = -1;
  tail = 0;
  add(ZERO, ZERO, 0);
  for(int i = 0; i < tail; ++i)
    for(int j = 0; j < 8; ++j)
      add(q[i][0] + dir[j][0], q[i][1] + dir[j][1], d[q[i][0]][q[i][1]] + 1); 
  gets(line);
  while(strcmp(line, "END") != 0) {
    int x, y;
    sscanf(line, "%d%d", &x, &y);
    printf("%d\n", moo(x, y));
    gets(line);
  }
  return 0;
}

