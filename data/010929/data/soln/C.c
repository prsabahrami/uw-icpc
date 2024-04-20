#include <stdio.h>
#include <math.h>

main(){
   double d = 0;
   int x,X,y,Y,t;
   scanf("%*d%*d");
   while (4 == scanf("%d%d%d%d",&x,&y,&X,&Y)) {
      d += hypot(x-X,y-Y);
   }
   t = d/1000*2/20*60+.5; 
   printf("%d:%0.2d\n",t/60,t%60);
}
