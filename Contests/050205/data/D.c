#include <stdio.h>

int s,d,a,b,n;

main(){
   scanf("%d",&n);
   while (n--){
      if (2 != scanf("%d%d",&s,&d)) {
         printf("short input\n");
         exit(1);
      }
      // a + b = s;
      // a - b = d;
      // 2a = s+d;
      a = (s+d)/2;
      b = a - d;
      if (a+b == s && a-b == d && b >= 0) printf("%d %d\n",a,b);
      else printf("impossible\n");
   }
}
