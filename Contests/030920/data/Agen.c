#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

struct ss {
   int h,d,w,c;
} dolls[2*SIZE];

int i,j,k,nd,delta;

comp(struct ss *a, struct ss *b){
   return a->c - b->c;
}

main(){
   for (k=0;k<20;k++) {
      delta = random()%SIZE+1;
      nd = 0;
    
      for (i=0;i<2;i++) { 
         dolls[nd].w = random()%delta+1;
         dolls[nd].h = random()%delta + 2*dolls[nd].w;
         dolls[nd].d = random()%delta + 2*dolls[nd].w;
         dolls[nd++].c = random();
         for (j=1;j<SIZE;j++) {
            dolls[nd].w = random()%delta+1;
            dolls[nd].h = random()%delta + dolls[nd-1].h + 2*dolls[nd].w;
            dolls[nd].d = random()%delta + dolls[nd-1].d + 2*dolls[nd].w;
            dolls[nd++].c = random();
         }
      }
      qsort(dolls,nd,sizeof(struct ss),comp);
      printf("%d\n",nd/2);
      for (i=0;i<nd;i++) printf("%d %d %d\n",dolls[i].h,dolls[i].d,dolls[i].w);
   }
   printf("0\n");
}
