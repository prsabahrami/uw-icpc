#define UW (!strcmp(argv[0]+strlen(argv[0])-4,".cmd"))

#define WRONG (UW?1:2)
#define FORMAT (UW?2:1)
#define OK 0

#include <stdio.h>
#include <string.h>

char tmp[10000];

double rest, sum,r[100];
int i,j,k,m,n, R[100], prev[10001], who[10001];
char *p;

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

   while (1 == fscanf(d,"%d",&n) && n) {
      printf("n = %d\n",n);
      for (i=0;i<n;i++) fscanf(d,"%lf",&r[i]);
      if (!gets(tmp)) {
         printf("Short contestant output\n");
         exit(WRONG);
      }
      printf("     %s\n",tmp);
      rest = 0;
      for (i=0;i<n;i++) rest += r[i];
      sum = 0;
      for (p=strtok(tmp," ");p;p=strtok(NULL," ")) {
         k = atoi(p);
         if (k < 1 || k > n) {
            printf("invalid rock number %d\n",k);
            exit(WRONG);
         }
         if (r[k-1] < 0) {
            printf("rock %d used twice\n",k);
            exit(WRONG);
         }
         sum += r[k-1];
         r[k-1] = -1;
      }
      rest -= sum;
      printf("delta %0.10lf%\n",100*fabs(rest-sum)/sum);
      if (fabs(rest-sum) > 0.020000001 * sum) {
         printf("not within 2%%\n");
         exit(WRONG);
      }
   }
   printf("Judge says OK\n");
   exit(OK);
}
