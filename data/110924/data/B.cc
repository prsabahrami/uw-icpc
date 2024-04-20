#include <stdio.h>
#include <stdlib.h>

void dump(long long x, int b) {
 if (!x) return;
 dump(x/b,b);
 printf("%c","0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[x%b]);
}

void doit() {
 int x,y;
 char foo[64000];
 scanf("%d%d%s",&x,&y,foo);
 long long p = strtoll(foo,0,x);
 if (!p) printf("0"); else dump(p,y);
 printf("\n");
}

int main() {
 int n;
 scanf("%i", &n);
 while(n--)doit();
}
