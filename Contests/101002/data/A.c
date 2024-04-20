#include <stdio.h>
#include <assert.h>

int a,b,c;
main(){
   while (3 == scanf("%d%d%d",&a,&b,&c) && (a || b || c)) {
      if (a*a == b*b + c*c || b*b == a*a+c*c || c*c == a*a+b*b) printf("right\n"); else printf("wrong\n");
   }
   assert (!a && !b && !c);
}
