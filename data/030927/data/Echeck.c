#define UW (!strcmp(argv[0]+strlen(argv[0])-4,".cmd"))

#define WRONG (UW?1:2)
#define FORMAT (UW?2:1)
#define OK 0

#include <stdio.h>
#include <string.h>

#define SIZE 100

char g[SIZE][SIZE];

int i,j,k,m,n,p,x,a,size;

int v[SIZE], cnt[SIZE][SIZE], is, best[SIZE][SIZE], prev[SIZE][SIZE];

dump(int p, int x){
   if (p) dump(p-1,prev[p][x]);
   printf(" %d",x+1);
}

main(int argc, char **argv){
   FILE *d;
   if (UW) {
      char tmp[1000];
      strcpy(tmp,argv[0]);
      strcpy(tmp+strlen(tmp)-3,"dat");
      d = fopen(tmp,"r");
      strcpy(tmp+strlen(tmp)-3,"diff.sample");
   } else {
      d = fopen(argv[1],"r");
   }

   while (1 == fscanf(d,"%d",&n) && n != -1) {
      memset(g,0,sizeof(g));
      memset(cnt,0,sizeof(cnt));
      for (i=0;i<n;i++) {
         fscanf(d,"%d%d",&j,&k);
         //g[j-1][k-1] = 1;
         g[k-1][j-1] = 1;
      }

      fscanf(d,"%d",&m); m--;
      for (i=0;i<=m;i++) {
         fscanf(d,"%d",&v[i]);
         v[i]--;
      }
      fscanf(d,"%d",&p); p--;
   
      for (a=0;a<m;a++) {
         for (i=0;i<SIZE;i++) {
            is = 0;
            for (size=1;i+size<SIZE;size++) {
               for(j=v[a];j<v[a+1];j++) {
                  is |= g[i+size-1][j];
                  if (is) {
                     cnt[i][i+size]++;
                     break;
                  }
               }
            }
         }
      }
      for (i=0;i<SIZE;i++) cnt[i][i] = -1;

      for (i=0;i<SIZE;i++) for (j=0;j<SIZE;j++) best[i][j] = -1;
      best[0][0] = 0;
      for (n=0;n<p;n++) {
         for (j=SIZE-1;j>0;j--) {
            for (i=0;i<j;i++) {
               if (cnt[i][j] + best[n][i] > best[n+1][j]) {
                  best[n+1][j] = cnt[i][j] + best[n][i];
                  prev[n+1][j] = i;
               }
            }
         }
      }
      //printf("%d",p+1);
      //dump(p,SIZE-1);
      //printf("\n");
      printf("Best solution: %d\n",best[p][SIZE-1]);
      {
         int i, cA, csol[101], cbest=0;
         scanf("%d",&cA);
         if (cA != p+1) {
            printf("contest can't get the size right!!\n");
            exit(WRONG);
         }
         for (i=0;i<cA;i++) {
            if (scanf("%d",&csol[i]) != 1) {
               printf("Bad contestant input - read failed\n");
               exit(WRONG);
            }
         }
         if (csol[0] != 1) {
           printf("first avenue is %d; should be 1\n",csol[0]);
           exit(WRONG);
         }
         if (csol[p] != SIZE) {
           printf("last avenue is %d; should be %d\n",csol[p],SIZE);
           exit(WRONG);
         }
         for (i=0;i<p;i++) {
           if (csol[i] >= csol[i+1]) {
              printf("streets not in ascending order:  %d %d\n",csol[i],csol[i+1]);
              exit(WRONG);
           }
           cbest += cnt[csol[i]-1][csol[i+1]-1];
         }
         printf("Contestant says: %d\n",cbest);
         if (cbest != best[p][SIZE-1]) {
            printf("mismatch!\n");
            exit(WRONG);
         }
      }
   }
   if (n != -1) printf("missing end delimiter\n");
   printf("Judge says OK\n"); exit(OK);
}
