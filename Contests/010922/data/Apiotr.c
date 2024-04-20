#include <stdio.h>

int main () {
  char line[100];
  int h,m,s,lspeed = 0,nspeed, i;
  double dist = 0, ltime = 0, ntime;
  while(1) {
    if (!fgets(line, 90, stdin)) break;
    sscanf(line,"%d:%d:%d",&h,&m,&s);
    if (sscanf(line+8,"%d",&nspeed) == 1) {
      ntime = h+m/60.0+s/3600.0;
      dist += (ntime-ltime)*lspeed;
      ltime = ntime;
      lspeed = nspeed;
    } else {
      ntime = h+m/60.0+s/3600.0;
      for(i=0;i<8;i++)
	printf("%c",line[i]);
      printf(" %.2f km\n", dist+(ntime-ltime)*lspeed);
    }
    
  }
  return 0;
}
