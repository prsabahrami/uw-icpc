#include <stdio.h>
#include <string.h>

struct cc {
   int h,d,w;
} c[201];

int i,k,j,m,n,cnt,qn,next,which;

int comp(struct cc *a, struct cc *b){
   if (a->h != b->h) return a->h - b->h;
   if (a->d != b->d) return a->d - b->d;
   return b->w - a->w;
}

int holds(int a, int b) {
   int r = c[a].h-2*c[a].w >= c[b].h && c[a].d-2*c[a].w >= c[b].d;
   return r;
}

char memo[201][201][201];

foo(int a, int b, int na){
   int next;
   if (memo[a][b][na]) return 0;
   next = a>b?a:b;
   if (na > n/2 || next-na > n/2) return 0;
   if (next++ == n) return 1;
   if (holds(next,a) && foo(next,b,na+1)) {
      if (which) printf("%d %d %d\n",c[next].h,c[next].d,c[next].w);
      return 1;
   }
   if (holds(next,b) && foo(a,next,na)) {
      if (!which) printf("%d %d %d\n",c[next].h,c[next].d,c[next].w);
      return 1;
   }
   memo[a][b][na] = 1;
   return 0;
}

main(){
   while (1 == scanf("%d",&n) && n) {
      n *= 2;
      if (cnt++) printf("\n");
      for (i=1;i<=n;i++) scanf("%d%d%d",&c[i].h,&c[i].d,&c[i].w);
      qsort(c,n+1,sizeof(struct cc),comp);
      memset(memo,0,sizeof(memo));
      which = 0;
      foo(0,0,0);
      printf("-\n");
      which = 1;
      foo(0,0,0);
   }
}
