
#define UW (!strcmp(argv[0]+strlen(argv[0])-4,".cmd"))

#define WRONG (UW?1:2)
#define FORMAT (UW?2:1)
#define OK 0

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char BB[1000], A[1000], B[1000], a[1000], a[1000], b[1000];

int na,nb,i,j,k,m,n,c;
char *pa, *pb, aa[100][100], bb[100][100];
int fail;



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

   fscanf(d,"%d ",&c);
   c *= 3;
   while (c--) {
      if (c%3 == 2) {
         fail = 0;
         fgets(a,500,d);
         a[strlen(a)-1] = 0;
         strcpy(A,a);
         fgets(b,500,d);
         b[strlen(b)-1] = 0;
         strcpy(B,b);
         printf("a: %s\nb: %s\n",a,b);
      } 
      if (c%3 == 1) {
         strcpy(a,A);
         gets(b);
         printf("c: %s\n",b);
         strcpy(BB,b);
         if (!strcmp(b,"-") && fail) continue;
         if (!strcmp(b,"-")) {
            printf("cont fail, judge has match\n");
            exit(WRONG);
         }
         for (i=0;b[i];i++) if (b[i] != ' ' && !islower(b[i])) {
            printf("junk in cont output\n");
            exit(WRONG);
         }
      }
      if (c%3 == 0) {
         if (fail) continue;
         strcpy(a,B);
         strcpy(b,BB);
      }
      na = nb = 0;
      for (pa = strtok(a," ");pa;pa = strtok(NULL," ")){
         if (*pa == '<') *pa = '0';
         strcpy(aa[na++],pa);
      }
      for (pb = strtok(b," ");pb;pb = strtok(NULL," ")){
         if (*pb == '<') *pb = '1';
         strcpy(bb[nb++],pb);
      }
      if (na != nb) {
            if (c%3 == 2) fail = 1;
            else {
               printf("match failed\n");
               exit(WRONG);
            }

         printf("-\n");
         continue;
      }
      for (i=0;i<na;i++) {
         if (isdigit(aa[i][0])) {
           for (j=0;j<na;j++) if (!strcmp(bb[j],aa[i])) strcpy(bb[j],bb[i]);
           for (j=i+1;j<na;j++) if (!strcmp(aa[j],aa[i])) strcpy(aa[j],bb[i]);
           for (j=0;j<=i;j++) if (!strcmp(aa[j],aa[i])) strcpy(aa[j],bb[i]);
         } else if (isdigit(bb[i][0])) {
           for (j=0;j<na;j++) if (!strcmp(aa[j],bb[i])) strcpy(aa[j],aa[i]);
           for (j=i+1;j<na;j++) if (!strcmp(bb[j],bb[i])) strcpy(bb[j],aa[i]);
           for (j=0;j<=i;j++) if (!strcmp(bb[j],bb[i])) strcpy(bb[j],aa[i]);
         } else if (strcmp(aa[i],bb[i])){
            if (c%3 == 2) fail = 1;
            else {
               printf("match failed\n");
               exit(WRONG);
            }
            printf("-\n");
            goto dun;
         }
      }
      for (i=0;i<na;i++) {
         if (i) printf(" ");
         if (isdigit(aa[i][0])) printf("x"); else printf("%s",aa[i]);
      }
      printf("\n");
   dun:;}
   if (fgets(a,500,d)) printf("Extra input!\n");
   printf("Judge says OK\n");
   exit(OK);
   return 0;
}
