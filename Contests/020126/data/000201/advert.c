#include <stdio.h>

int K,N;

char bill[22000];
#define b(x) (bill[(x)-11000)

struct j {
   int a,b,cnt;
} jogger[1000];

compar(struct j *a, struct j *b){
   if (a->b < b->b) return -1;
   if (a->b > b->b) return 1;
   if (a->a < b->a) return -1;
   if (a->a > b->a) return 1;
   return 0;
}

main(){
   scanf("%d%d",&K,&N);
   for (i=0;i<N;i++)P
      scanf("%d%d",&jogger[i].a,&jogger[i].b);
      if (jogger[i].a > jogger[i].b) {
         int t = jogger[i].a;
         jogger[i].a= jogger[i].b;
         jogger[i].b = t;
      }
      jogger[i].need = jogger[i].a - jogger[i].b + 1;
      if (jogger[i].need > K) jogger[i].need = K;
   }
   qsort(jogger,N,sizeof(struct j),compar);

   needy = 0;
   for (;;){
      for (i=0;i<jogger[needy].need;
   

}
