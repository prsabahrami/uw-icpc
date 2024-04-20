#include <stdio.h>
#include <stdlib.h>

#define UW (!strcmp(argv[0]+strlen(argv[0])-4,".cmd"))

#define WRONG (UW?1:2)
#define FORMAT (UW?2:1)
#define OK 0

struct cc {
   int h,d,w;
} c[200], j[200];

int i,k,m,n,cnt,qn,next,which;
char ccc;

int comp(struct cc *a, struct cc *b){
   if (a->h != b->h) return a->h - b->h;
   if (a->d != b->d) return a->d - b->d;
   return b->w - a->w;
}

int holds(int a, int b) {
   int r = c[a].h-2*c[a].w >= c[b].h && c[a].d-2*c[a].w >= c[b].d;
   return r;
}

main(int argc, char **argv){
   FILE *d;

   if (UW) {
      char tmp[1000];
      strcpy(tmp,argv[0]);
      strcpy(tmp+strlen(tmp)-3,"dat");
      d = fopen(tmp,"r");
   } else {
      d = fopen(argv[1],"r");
   }

   while (fscanf(d,"%d",&n) && n) {
      for (i=0;i<2*n;i++) fscanf(d,"%d%d%d",&j[i].h,&j[i].d,&j[i].w);
      printf("case %d %d %d\n",j[0].h,j[0].d,j[0].w);
      for (i=0;i<n;i++) if (3 != fscanf(stdin,"%d%d%d",&c[i].h,&c[i].d,&c[i].w)) {
         printf("not enough boris dolls\n");
         exit(WRONG);
      }
      fscanf(stdin," %c ",&ccc);
      if (ccc != '-') {
         printf("input error; expecting '-' got '%c'\n",ccc);
         exit(WRONG);
      }
      for (i=0;i<n;i++) if (3 != fscanf(stdin,"%d%d%d",&c[n+i].h,&c[n+i].d,&c[n+i].w)) {
         printf("not enough natasha dolls\n");
         exit(WRONG);
      }
      for (i=0;i<2*n;i++) { 
         if (i%n == 0) continue;
         if (!holds(i-1,i)) {
            printf("doll doesn't fit: %d %d %d !> %d %d %d\n",
               c[i-1].h,c[i-1].d,c[i-1].w,c[i].h,c[i].d,c[i].w);
           exit(WRONG);
         }
      }
      qsort(c,2*n,sizeof(struct cc),comp);
      qsort(j,2*n,sizeof(struct cc),comp);
      for (i=0;i<2*n;i++) {
         if (c[i].h != j[i].h || c[i].d != j[i].d || c[i].w != j[i].w) {
            printf("wrong doll: %d %d %d (contestant) != %d %d %d (judge)\n",
               c[i-1].h,c[i-1].d,c[i-1].w,c[i].h,c[i].d,c[i].w);
           exit(WRONG);
         }
      }
   }
   printf("judge says OK\n");
   exit(OK);
}
