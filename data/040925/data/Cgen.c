#include <stdio.h>
#include <string.h>

char a[1000], b[1000];
int t,i,j;

struct nn {
   int n; char lbl;
   struct nn *fwd[100];
   int fwdi[100];
} n[200], *p, *root1, *root2;

char * parse(int depth,char *x, int ni, struct nn **r) {
   char lbl = *x++;
   struct nn *pp = p++;
   int i;
   //for (i=0;i<depth;i++) printf(" ");
   //printf("parse %s\n",x-1);fflush(stdout);
   pp->n=ni;
   pp->lbl = lbl;
   if (*x == '(') {
      while (*x == ',' || *x == '(') {
         x = parse(depth+1,++x,1,&pp->fwd[pp->n]);
         pp->fwdi[pp->n] = 0;
         pp->fwd[pp->n]->fwd[0] = pp;
         pp->fwd[pp->n]->fwdi[0] = pp->n;
         pp->n++;
      }
      x++;
   }
   *r = pp;
   return x;
}

dump(struct nn *t, int w){
   int i,j;
   printf("%c",t->lbl);
   if (w == -1) {
      if (t->n) printf("(");
      for (i=0;i<t->n;i++) {/*printf("[%c%d,%d]",t->lbl,i,t->n);*/if (i) printf(",");dump(t->fwd[i],t->fwdi[i]);}
      if (t->n) printf(")");
      printf("\n");
   } else {
      if (t->n > 1) printf("(");
      for (i=(w+1)%t->n;i!=w;i=(i+1)%t->n) {
         if (i!=(w+1)%t->n) printf(",");dump(t->fwd[i],t->fwdi[i]);
      }
      if (t->n > 1) printf(")");
   }
}

equiv(struct nn *t, int where,int depth){
   int i;
   dump(t,-1); 
   //for (i=0;i<depth;i++) printf(" ");
   //printf("---%c\n",t->lbl);
   if (where == -1) {
      for (i=0;i<t->n;i++) {
         equiv(t->fwd[i],t->fwdi[i],depth+1);
     }
   }else{
      for (i=(where+1)%t->n;i!=where;i=(i+1)%t->n) equiv(t->fwd[i],t->fwdi[i],depth+1);
   }
   return 0;
}

main(){
   scanf("%d ",&t);
   while (t--) {
      p = n;
      if (!gets(b)) {printf("short input\n"); exit(1); }
      parse(0,b,0,&root2);
      equiv(root2,-1,0);
   }
   if (gets(a)) printf("extraneous input!\n");
}
