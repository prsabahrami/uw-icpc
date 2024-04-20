#include <stdio.h>
#include <stdlib.h>

char buf[10000];

main(){
   while (gets(buf)) {
      if (random()%10 == 0) printf("%s\n",buf);
   }
}
