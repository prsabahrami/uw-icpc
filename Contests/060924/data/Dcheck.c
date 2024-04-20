#include <stdio.h>
#include <string.h>

#define UW (!strcmp(argv[0]+strlen(argv[0])-4,".cmd"))

#define WRONG (UW?1:2)
#define FORMAT (UW?2:1)
#define OK 0


int need;
int cnt[256];
char s[200],S[200];
char buf[200];
int jj,i,j,vars, bins, uns;
FILE *f;

main(int argc, char **argv){
   if (UW) {
      strcpy(buf,argv[0]);
      strcpy(buf+strlen(buf)-3,"dat");
      f = fopen(buf,"r");
   } else {
      f = fopen(argv[1],"r");
   }
   while (1 == fscanf(f,"%s",s) && strcmp(s,"0")) {
      jj = 0;
      need = 1;
      printf("read '%s'\n",s);
      memset(cnt,0,sizeof(cnt));
      vars = bins = uns = 0;
      for (i=0;s[i];i++) {
         if (s[i] >='p' && s[i] <= 't') vars++;
         else if (s[i] == 'N') uns++;
         else bins++;
         cnt[s[i]]++;
      }
      scanf(" %[^\n]",S);
      printf("cont '%s'\n",S);
      if (!vars) {
         printf("no WFF possible\n");
         if (strcmp(S,"no WFF possible")) {
            printf("cont disagrees! '%s'\n",S);
            exit(WRONG);
         }
         continue;
      }
      if (vars > bins+1) vars = bins+1;
      for (i=0;i<uns;i++) { jj++;}
      for (i=j=0;s[i] && j+1 < vars;i++) {
         if (s[i] < 'Z') {
            //printf("%c",s[i]);
            j++; jj++;
         }
      }
      for (i=j=0;s[i] && j < vars;i++) {
         if (s[i] > 'a') {
            //printf("%c",s[i]);
            j++; jj++;
         }
      }
      //printf("\n");

      if (jj != strlen(S)){
         printf("lengths disagree %d %d\n",jj,strlen(S));
         exit(WRONG);
      }
      for (i=0;S[i];i++) {
         if (need <= 0) {
            printf("bad WFF\n"); exit(WRONG);
         }
         if (!cnt[S[i]]--) {
            printf("too many %c\n",S[i]);
            exit(WRONG);
         }
         if (S[i] == 'N') {}
         else if (S[i] < 'Z') need++;
         else need--;
      }
      if (need) {printf("bad WFF 2\n"); exit(WRONG);}
   }
   if (strcmp(s,"0")) printf("wrong input\n");
   printf("judge says OK\n");
   exit(OK);
}
