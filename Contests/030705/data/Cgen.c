#include <stdio.h>
#include <string.h>

int fst,i,j,k,m, mm[12],s,T;
char buf[2000];

char *p;

char *t[] = {"C","C#","D","D#","E","F","F#","G","G#","A","A#","B"};

main(){
   for (i=0;i<12;i++) {
      mm[i] |= (1<<((i+0)%12));
      mm[i] |= (1<<((i+2)%12));
      mm[i] |= (1<<((i+4)%12));
      mm[i] |= (1<<((i+5)%12));
      mm[i] |= (1<<((i+7)%12));
      mm[i] |= (1<<((i+9)%12));
      mm[i] |= (1<<((i+11)%12));
   }

   for (i=0;i<499;i++) printf("C ");
   printf("C#\n");

   for (i=0;i<100;i++) {
      j = random()%9;
      printf("%s",t[random()%12]);
      for (k=0;k<j;k++) {
         printf(" %s",t[random()%12]);
      }
      printf("\n");
   }

   for (s=1;s<(1<<12);s++) {
      T = (1<<12)-1;
      for (i=0;i<12;i++) {
         if (! (s & (1<<i))) continue;
         T &= mm[i];
      }
      if (!T) continue;
      fst=0;
      for (i=0;i<12;i++) {
         if (T & (1<<i)) {
            if(fst++) printf(" ");
            printf("%s",t[i]);
         }
      }
      printf("\n");
      j = random()%50+1;
      fst = 0;
      for (i=0;i<j || !fst;i++) {
         k = random()%12;
         if (T & (1<<k)) {
            if (fst++) printf(" ");
            printf("%s",t[k]);
         }
      }
      printf("\n");
   }

   printf("END\n");
}
