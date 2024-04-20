#include <stdio.h>

main(){
   int n,rem,digs;
   while (1 == scanf("%d",&n)) {
      for (rem=digs=1;rem;digs++) rem = (rem*10+1) % n;
      printf("%d\n",digs);
   }
}
