#include <stdio.h>
#include <string.h>
#include <math.h>
#include <assert.h>

#define EPS 10e-9

int main () {
  double R = 20000/M_PI;
  while (1) {
    int k,m;
    scanf("%d%d",&k,&m);
    if (!k && !m) break;
    double sx[110],sy[100],sz[110];
    for(int i=0;i<k;i++) {
      scanf("%lf%lf%lf",sx+i,sy+i,sz+i);
      assert(sqrt(sx[i]*sx[i]+sy[i]*sy[i]+sz[i]*sz[i]) > R+50+EPS);
    }
    double dx[110],dy[100],dz[110];
    for(int i=0;i<m;i++) {
      scanf("%lf%lf%lf",dx+i,dy+i,dz+i);
      assert(fabs(sqrt(dx[i]*dx[i]+dy[i]*dy[i]+dz[i]*dz[i])-R) < EPS);
    }
    char done[110];
    memset(done,0,110);
    for(int i=0;i<k;i++)
      for(int j=0;j<m;j++) {
#define SQR(x) ((x)*(x))
	double dx1 = sx[i]-dx[j], dy1 = sy[i]-dy[j], dz1 = sz[i]-dz[j];
	double dot = dx1*-dx[j] + dy1*-dy[j] + dz1*-dz[j];
	double l1 = sqrt(SQR(dx1)+SQR(dy1)+SQR(dz1));
	double l2 = sqrt(SQR(dx[j])+SQR(dy[j])+SQR(dz[j]));
	if (acos(dot / (l1*l2)) < M_PI/2) continue;
	done[j] = 1;
      }
    int res = 0;
    for(int i=0;i<m;i++) 
      res += done[i];
    printf("%d\n",res);
  }
}

