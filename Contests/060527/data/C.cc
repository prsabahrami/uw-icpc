#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

typedef unsigned long long ULL;

char f[100][100];
ULL N;

ULL eval(ULL n) {
  ULL stos[100];
  int sp = -1;
  for (int i=0; ;i++) {
    if (isdigit(f[i][0])) {
      sscanf(f[i],"%llu",&stos[++sp]);
      assert(stos[sp] <= N);
      stos[sp] %= N;
    } else if (f[i][0] == 'x') {
      stos[++sp] = n;
    } else if (f[i][0] == 'N') {
      stos[++sp] = N;
    } else if (f[i][0] == '+') {
      sp -= 1;
      stos[sp] += stos[sp+1];
      stos[sp] %= N;
    } else if (f[i][0] == '*') {
      sp -= 1;
      stos[sp] *= stos[sp+1];
      stos[sp] %= N;      
    } else if (f[i][0] == '%') {
      assert(stos[sp] == N);
      assert(sp == 1);
      return (stos[sp-1] % N);
    }
  }
}

int main () {
  while (1) {
    ULL n;
    scanf("%llu%llu",&N, &n);
    if (!N) break;
    assert(0<=N && N <= 100000000);
    assert(0<=n && n <= N);
    int i = 0;
    while(1) {
      char s[100];
      scanf("%s",s);
      strcpy(f[i++],s);
      if (s[0] == '%') break;
    }
    ULL a=eval(n), b = eval(a);
    while (a != b) {
      //      printf("%llu %llu\n",a, b);
      a = eval(a);
      b = eval(eval(b));
    }
    int m = 1;
    b = eval(a);
    while (a != b) {
      m++;
      b = eval(b);
    }
    printf("%d\n",m);
  }
}
