#define UW (!strcmp(argv[0]+strlen(argv[0])-4,".cmd"))

#define WRONG (UW?1:2)
#define FORMAT (UW?2:1)
#define OK 0

#include <stdio.h>
#include <string.h>
#include <math.h>

#define N 0
#define S 1
#define E 2
#define W 3

FILE *d, *cont, *judge;

char g[100][101], jack[100000], jill[100000];

int i,j,k,m,n,Hi,Hj,Si,Sj,hi,hj,si,sj,qn;
int cnt,a,b,i,j,qi,I,J,hi,lo,mid,min2;
double cd,jd;

struct qq{
   char I,J,i,j;
   int d;
   int prev;
} q[8000000];

#define isdone(a,b,c,d) done[(((a*100+b)*100+c)*100+d)/32] & (1<<((((a*100+b)*100+c)*100+d)%32))
#define setdone(a,b,c,d) done[(((a*100+b)*100+c)*100+d)/32] |= (1<<((((a*100+b)*100+c)*100+d)%32))

unsigned done[100000000/32];

//char done[100][100][100][100];

//#define isdone(a,b,c,d) done[a][b][c][d]
//#define setdone(a,b,c,d) (done[a][b][c][d] = 1)

dump(int z){
   if (z == 0) return;
   dump(q[z].prev);
   if (q[q[z].prev].I < q[z].I) strcat(jack,"S");
   if (q[q[z].prev].I > q[z].I) strcat(jack,"N");
   if (q[q[z].prev].J < q[z].J) strcat(jack,"E");
   if (q[q[z].prev].J > q[z].J) strcat(jack,"W");
   if (q[q[z].prev].i < q[z].i) strcat(jill,"S");
   if (q[q[z].prev].i > q[z].i) strcat(jill,"N");
   if (q[q[z].prev].j < q[z].j) strcat(jill,"E");
   if (q[q[z].prev].j > q[z].j) strcat(jill,"W");
}

main(int argc, char **argv){
   cont = stdin;

   if (UW) {
      char tmp[1000];
      strcpy(tmp,argv[0]);
      strcpy(tmp+strlen(tmp)-3,"dat");
      d = fopen(tmp,"r");
      strcpy(tmp+strlen(tmp)-3,"diff.sample");
      judge = fopen(tmp,"r");
   } else {
      d = fopen(argv[1],"r");
      judge = fopen(argv[2],"r");
   }

   while (1 == fscanf(d,"%d",&n) && n) {
      if (cnt++) printf("\n");
      for (i=0;i<n;i++) fscanf(d,"%s",g[i]);
      fscanf(judge,"%lf%s%s",&jd,jack,jill);
 
      memset(jill,0,sizeof(jill)); memset(jack,0,sizeof(jack));
      fscanf(cont,"%lf%s%s",&cd,jack,jill);
      printf("case %d\n%0.2lf\n%s\n%s\n",cnt,cd,jack,jill);
      if (jd != cd) {printf("wrong distance %0.2lf should be %0.2lf\n",cd,jd);exit(WRONG);}
      //else printf("distance OK\n");
      //if (a == i/60 && b == i%60) printf("got time right\n");
      //else { printf("wrong time %02d:%02d should be %02d:%02d\n",a,b,i/60,i%60); exit(WRONG); }
      a = strlen(jack);
      b = strlen(jill);
      if (b > a) a = b;
      a = 9*60 - a;
      //if (a == i) printf("path matches time\n");
      //else {printf("wrong path for time\n"); exit(WRONG);}

      jd *= jd;
      min2 = jd + .5;


      for (i=0;i<n;i++) for (j=0;j<n;j++) {
         if (g[i][j] == 'H') {q[0].I = i; q[0].J = j;}
         if (g[i][j] == 'h') {q[0].i = i; q[0].j = j;}
      }
      lo = 0; hi = (q[0].I-q[0].i)*(q[0].I-q[0].i)+ (q[0].J-q[0].j)*(q[0].J-q[0].j);
         qn = 1;
            printf("init - %d,%d %d,%d\n",q[0].I,q[0].J,q[0].i,q[0].j,jack[qi],jill[qi]);
         for (qi=0;qi<qn;qi++) {
            if (!jack[qi] && !jill[qi]) break;
            a=b=-1;
            if (jack[qi]=='N') a = N;
            if (jack[qi]=='S') a = S;
            if (jack[qi]=='W') a = W;
            if (jack[qi]=='E') a = E;
            if (jill[qi]=='N') b = N;
            if (jill[qi]=='S') b = S;
            if (jill[qi]=='W') b = W;
            if (jill[qi]=='E') b = E;
            for(;;){
               I = q[qi].I; J = q[qi].J; i = q[qi].i; j = q[qi].j;
               if (g[I][J] == 'S') { }
               else if (a == N) I--;
               else if (a == S) I++;
               else if (a == W) J--;
               else if (a == E) J++;
               if (g[i][j] == 's') { }
               else if (b == N) i--;
               else if (b == S) i++;
               else if (b == W) j--;
               else if (b == E) j++;
               printf("step %d %d,%d %d,%d %c %c\n",qi,I,J,i,j,jack[qi],jill[qi]);
               if (I<0 || J<0 || i<0 || j<0 || I == n || J == n || i == n || j == n) {printf("runs off course\n"); exit(WRONG);}
               if (g[I][J] == '*' || g[I][J] == 'h' || g[I][J] == 's') {printf("jack hits obstacle\n");exit(WRONG);}
               if (g[i][j] == '*' || g[i][j] == 'H' || g[i][j] == 'S') {printf("jill hist obstacle\n");exit(WRONG);}
               if ((I-i)*(I-i) + (J-j)*(J-j) < min2) {printf("jack & jill get too close\n");exit(WRONG);}
               q[qn].I = I; q[qn].J = J; q[qn].i = i; q[qn].j = j; q[qn].d = q[qi].d+1; q[qn].prev = qi;
               //if (g[I][J] == 'S' && g[i][j] == 's')  goto dun;
               qn++;
               break;
            }
         }
         if (g[I][J] == 'S' && g[i][j] == 's') printf("Jack and Jill got to school\n");
         else {printf("Jack and Jill didn't get to school\n");exit(WRONG);}
      i = strlen(jack);
      j = strlen(jill);
      if (j > i) i = j;
      i = 9 * 60 - i;
      //printf("%02d:%02d\n%s\n%s\n",i/60,i%60,jack,jill);

   }
   if (n) printf("missing 0 in input\n");
   printf("Judge says OK\n"); exit(OK);
}
