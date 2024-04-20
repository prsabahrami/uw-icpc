#include <stdio.h>
#include <stdlib.h>

int i,j,k,m,n,t,now;
main(int argc, char **argv){
   n = atoi(argv[1]);
   t = atoi(argv[2]);
   m = atoi(argv[3]);
   //printf("1\n");
   printf("%d %d %d\n",n,t,m);
   for (i=0;i<m;i++){
      printf("%d %s\n",now,(now%2)?"left":"right");
      now += random()%(2*t);
   }
}
