#include <stdio.h>

int a,b,c,d,r;

main(){
   while ((4 == scanf("%d%d%d%d",&a,&b,&c,&d)) && (a||b||c||d)){
      a*=9; b*=9; c*=9; d*=9;
      r = 720;
      r += (a-b+360)%360;
      r += 360;
      r += (c-b+360)%360;
      r += (c-d+360)%360;
      printf("%d\n",r);
   }
   if (a||b||c||c) printf("missing end delimiter\n");
}
