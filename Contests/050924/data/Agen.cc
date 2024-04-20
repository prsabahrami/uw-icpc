#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#define drand rand()%10000000/10000000.0;
#define rs ((rand()%2) ? 1 : -1)

int main (int argc, char **argv) {
  assert(argc == 4);
  int k,m,sh;
  sscanf(argv[1],"%d",&k);
  sscanf(argv[2],"%d",&m);
  sscanf(argv[3],"%d",&sh);  
  printf("%d %d\n",k,m);
  double R = 20000/M_PI;
  double x, y;
  for(int i=0;i<k;i++) {
    do {
      x = drand; y = drand;
    } while (x*x+y*y > 1.0);
    double z;
    z = sqrt(1-x*x-y*y);
    double Rs = R+51+rand()%sh;
    printf("%.8lf %.8lf %.8lf\n",rs*x*Rs,rs*y*Rs,rs*z*Rs);
    assert(sqrt(x*Rs*x*Rs+y*Rs*y*Rs+z*Rs*z*Rs) > R+50);
  }
  for(int i=0;i<m;i++) {
    do {
      x = drand; y = drand;
    } while (x*x+y*y > 1.0);
    double z;
    z = sqrt(1-x*x-y*y);
    printf("%.8lf %.8lf %.8lf\n",rs*x*R,rs*y*R,rs*z*R);
  }
  printf("0 0\n");
}
