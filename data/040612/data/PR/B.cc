#include <stdio.h>
#include <assert.h>

int p[70][100];

void powers3() {
  p[0][0] = 1;
  for(int i=0;i<69;i++) {
    int c = 0;
    for(int j=0;j<80; j++) {
      p[i+1][j] = (p[i][j]*3+c)%10;
      c = (p[i][j]*3+c)/10;
    }
  }
}

int main () {
  unsigned long long a;
  while (scanf("%lld",&a) == 1) {
    if (a == 0) break;
    assert(a > 0);
    a -= 1;
    int b[100], m = 0;
    while (a) {
      b[m++] = a%2;
      a /=2;
    }
    powers3();
    printf("{ ");
    for(int i = 0; i< m; i++) {
      if (!b[i]) continue;
      int j = 80;
      for(;0<=j;j--) if (p[i][j]) break;
      for(;0<=j;j--) printf("%d",p[i][j]);
      if (i+1!=m) printf(",");
      printf(" ");
    }
    printf("}\n");
  }
}
