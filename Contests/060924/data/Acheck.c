#include <stdio.h>
#include <string.h>

#define N 10001

#define UW (!strcmp(argv[0]+strlen(argv[0])-4,".cmd"))

#define WRONG (UW?1:2)
#define FORMAT (UW?2:1)
#define OK 0

int A[N];
int B[N];
int in[N];

int format;

int comp(const int* a, const int* b) {
    return (*a)-(*b);
}

char buf[1000],c[1000];

FILE *f;

main(int argc, char **argv) {
   int cmax, n, max, i, j, per;
   if (UW) {
      strcpy(buf,argv[0]);
      strcpy(buf+strlen(buf)-3,"dat");
      f = fopen(buf,"r");
   } else {
     f = fopen(argv[1],"r");
   }
   while(1 == fscanf(f,"%d", &n) && n) {
      max = 0;
      memset(A,0,sizeof(A));
      memset(in,0,sizeof(in));
      for(i = 0; i < n; i++) {
          int d;
          fscanf(f,"%d", &d);
          A[d]++;
          in[i] = d;
          if(A[d]>max) max = A[d];
      }
      scanf("%d",&cmax);
      printf("judge %d cont %d\n", max,cmax);
      if (max != cmax) exit(WRONG);
      per = ((n+max-1)/max);
      for (i=0;i<n;i++) {  
         int d;
         scanf("%[ \n]%d",c,&d);
         if (strlen(c) != 1) format = 1;
         if (c[strlen(c)-1] == '\n') {
            j = 0;
            memset(B,0,sizeof(B));
         }
         if (--A[d] < 0) {
            printf("wrong number of %d\n",d);
            exit(WRONG);
         }
         if (B[d]++) {
            printf("dupe %d\n",d);
            exit(WRONG);
         }
         if (++j > per) {
            printf("too many bags!\n");
            exit(WRONG);
         }
      }
   }
   if (format) {printf("Format error\n");exit (FORMAT);}
   printf("judge says OK\n");
   exit(OK);
}
