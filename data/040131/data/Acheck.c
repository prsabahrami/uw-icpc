#include <stdio.h>
#define UW (!strcmp(argv[0]+strlen(argv[0])-4,".cmd"))
#define WRONG (UW?1:2)
#define FORMAT (UW?2:1)
#define OK 0
int jbest;

char *B[] = {"LR","LU","LD","UR","UD","UL","RD","RU","DL","DU","DR"};

int t[200][22], prev[200][22];

stepcost(char x, char y){
   if (x == y) return 3;
   if (x == 'R' && y == 'L' || x == 'U' && y == 'D') return 7;
   if (x == 'L' && y == 'R' || x == 'D' && y == 'U') return 7;
   return 5;
}

cost(int s1, int s2, char m) {
   int p1 = s1%2, b1 = s1/2, p2 = s2%2, b2 = s2/2;
   if (m == '.') {
      int a,b;
      if (s1/2 == s2/2) return 0;
      a = cost(s1,s2,'L');
      b = cost(s1,s2,'R');
      if (b<a) a = b;
      b = cost(s1,s2,'U');
      if (b<a) a = b;
      b = cost(s1,s2,'D');
      if (b<a) a = b;
      return a;
   }
   if (p2 == 0) {                          // moving left foot
      if (B[b2][0] != m) return 999999;    // have to end with foot in place
      if (B[b2][1] == m) return 999999;    // other foot on the square
      if (B[b1][1] == 'L' && B[b1][0] != m) return 999999;  // crossed over
      if (B[b1][1] != B[b2][1]) return 999999; // can't move other foot
      if (p1 == 1) return 1;               // alternating feet
      return stepcost(B[b1][0],m);
   } else {
      if (B[b2][1] != m) return 999999;    // have to end with foot in place
      if (B[b2][0] == m) return 999999;    // other foot on the square
      if (B[b1][0] == 'R' && B[b1][1] != m) return 999999;  // crossed over
      if (B[b1][0] != B[b2][0]) return 999999; // can't move other foot
      if (p1 == 0) return 1;               // alternating feet
      return stepcost(B[b1][1],m);
   }
}

char buf[10000], cbuf[10000];

int i,j,k,n;

dump(int j, int k) {
   int i;
   if (j == 0) return 0;
   for (i=0;i<22;i++) {
      if (t[j-1][i] + cost(i,k,buf[j-1]) == t[j][k]) {
         dump(j-1,i);
         if (cost(i,k,buf[j-1]) == 0) printf(".");
         else printf("%c","LR"[k%2]);
         return 0;
      }
   }
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

   while (fgets(buf,100,d) && *buf != '#') {
      n = strlen(buf)-1;
      printf("Data:  %s",buf);
      for (i=0;i<=n;i++) for (j=0;j<22;j++) t[i][j] = 999999;
      t[0][0] = t[0][1] = 0;
      for (i=0;i<n;i++) {
         for (j=0;j<22;j++) for (k=0;k<22;k++) {
            if (t[i][j] == 999999) continue;
            int c = cost(j,k,buf[i]);
            if (t[i][j] + c < t[i+1][k]) {
               t[i+1][k] = t[i][j] + c;
               prev[i+1][k] = j;
               0&&printf("step %d from %d %s to %d %s cost %d total %d\n",
                          i,j%2,B[j/2],k%2,B[k/2],c,t[i+1][k]);

            }
         }
      }
      k = 0;
      for (i=0;i<22;i++) if (t[n][i] < t[n][k]) k = i;
      printf("Diff:  ");
      dump(n,k);
      printf("\nJudge: %d\n",jbest=t[n][k]);
      if (!gets(cbuf)){printf("Missing output for this case.\n");exit(WRONG);}
      printf("Input: %s\n",cbuf);
      if (strlen(cbuf)!=n){printf("Wrong length output.\n");exit(WRONG);}
      for (i=0;i<=n;i++) for (j=0;j<22;j++) t[i][j] = 999999;
      t[0][0] = t[0][1] = 0;
      for (i=0;i<n;i++) {
         for (j=0;j<22;j++) for (k=0;k<22;k++) {
            if (t[i][j] == 999999) continue;
            int c = cost(j,k,buf[i]);
            if (c == 0) {if(cbuf[i] != '.') c = 999999;}
            else if ("LR"[k%2] != cbuf[i]) c = 999999;
            if (t[i][j] + c < t[i+1][k]) {
               t[i+1][k] = t[i][j] + c;
               prev[i+1][k] = j;
               0&&printf("step %d from %d %s to %d %s cost %d total %d\n",
                          i,j%2,B[j/2],k%2,B[k/2],c,t[i+1][k]);

            }
         }
      }
      k = 0;
      for (i=0;i<22;i++) if (t[n][i] < t[n][k]) k = i;
      //dump(n,k);
      printf("Cont:  %d\n",t[n][k]);
      if (t[n][k] != jbest){printf("Wrong cost.\n");exit(WRONG);}
   }
   if (*buf != '#') printf("missing end delimiter\n");
   printf("Judge says OK.\n");
   exit(OK);
}
