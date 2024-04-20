#include <stdio.h>
#include <stdlib.h>

#define N 6

int off[N+1];
main(){
   int p=0,p1,p2,z,i;
   for (i=1;i<N;i++) {
      z = random()%3-1;  
      //z = 0;
      p += abs(z);
      off[i] = off[i-1] + z;
      //printf("%d\n",off[i]);
   }
   off[N] = off[N-1];
   p1 = N+N+p+50+50+off[N];
   p2 = N+N+p+50+50-off[N];
   printf("%d\n",p1);
   for (i=0;i<N;i++) {
      printf("%d %d\n",50+off[N-i],N-i);
      if (off[N-i-1] != off[N-i]) printf("%d %d\n",50+off[N-i-1],N-i);
   }
   printf("%d %d\n",50+off[0],0);
   for (i=50+off[0]-1;i>=0;i--) {
      printf("%d %d\n",i,0);
   }
   for (i=1;i<=N;i++) {
      printf("%d %d\n",0,i);
   }
   for (i=1;i<50+off[N];i++) {
      printf("%d %d\n",i,N);
   }

   printf("%d\n",p2);
   printf("%d %d\n",950+off[0],0);
   for (i=1;i<=N;i++) {
      printf("%d %d\n",950+off[i-1],i);
      if (off[i-1] != off[i]) printf("%d %d\n",950+off[i],i);
   }
   for (i=950+off[N]+1;i<1000;i++) {
      printf("%d %d\n",i,N);
   }
   for (i=N;i>0;i--) {
      printf("%d %d\n",1000,i);
   }
   for (i=1000;i>950;i--) {
      printf("%d %d\n",i,0);
   }
}
