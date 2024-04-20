#include <math.h>

#define MAXM 100
#define MAXN 100+1

int solve(int m,int n, double A[][MAXN], double X[]) {
   int i,j,k,ii,best,res=0;
   double t,r;

   for (i=0,ii=0;i<n;i++) {
      for (best=i,j=0;j<m;j++)
          if (fabs(A[j][i]) > fabs(A[best][i]) &&
              (i <= j || fabs(A[j][j]) < 1e-10)) best=j;
      if (fabs(r=A[best][i]) < 1e-10)
          continue;   // singular, but keep going
      for (k=ii++;k<=n;k++) { // pivot in "best" row
         t = A[best][k];
         A[best][k] = A[i][k];
         A[i][k] = t/r;
      }
      for (j=0;j<m;j++) if (j != i) {
            r = A[j][i];
            for (k=i;k<=n;k++) A[j][k] -= r * A[i][k];
      }
   }

   for (i=0;i<m;i++) {
      for (j=0,r=0;j<n;j++) r += A[i][j] * A[j][n];
      if (fabs(r-A[i][n]) > 1e-10*(fabs(r)+fabs(A[i][n]))) return -1;
   }
   for (i=0;i<n;i++) {
      for (j=0,r=0;j<n;j++) r += fabs(A[i][j] - (i==j));
      if (r > 1e-10) {
         X[i] = 1.0/0.0;
         res = 1;
      } else X[i] = A[i][n];
   }
   return res; 
}

double A[MAXM][MAXN];
double x[MAXN];
int t[6];
char c;

readit(){
   int h=0,m=0,s=0,k;
   k = scanf("%d:%d:%d",&h,&m,&s);
   return h*3600+m*60+s;
}

#define aM 0
#define bM 1
#define aD 2
#define bD 3
#define aA 4
#define bA 5
#define aC 6
#define bC 7

main(){
   int i,j,k,xx;
   for (;;) {
      for (i=1;i<=5;i++) t[i] = readit(); 
      if (t[1] < 0) break;
      //for(i=1;i<=5;i++) printf("%d ",t[i]); printf("\n");
      memset(A,0,sizeof(A));
      memset(x,0,sizeof(x));
      A[0][aA] = 1; A[0][8] = 2;
      A[1][bA] = 1; A[1][8] = 0;
      A[2][aC] = 1; A[2][8] = 1;
      A[3][bC] = 1; A[3][8] = t[1];
      A[4][aA] = t[2]; A[4][bA] = 1; A[4][aM] = -t[2]; A[4][bM] = -1;
      A[5][aA] = t[3]; A[5][bA] = 1; A[5][aD] = -t[3]; A[5][bD] = -1;
      A[6][aD] = t[4]; A[6][bD] = 1; A[6][aC] = -t[4]; A[6][bC] = -1;
      A[7][aD] = t[5]; A[7][bD] = 1; A[7][aM] = -t[5]; A[7][bM] = -1;
      k = solve(8,8,A,x); 
      xx = (int)((x[bC]-x[bM])/(x[aM]-x[aC])+.5);
      printf("%02d:%02d:%02d %lg\n",xx/3600,xx/60%60,xx%60,((x[bC]-x[bM])/(x[aM]-x[aC])));
   }
}
