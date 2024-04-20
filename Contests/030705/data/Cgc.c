#include <stdio.h>
#include <string.h>

int i,j,k,m, mm[12];
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
      
   while (gets(buf)) {
      if (!strcmp(buf,"END")) break;
      m = 0;
      for (p=strtok(buf," ");p;p=strtok(NULL," ")) {
         for (i=0;i<12 && strcmp(p,t[i]);i++);
         m |= (1<<i);
      }
      for (k=i=0;i<12;i++) {
         if (!(m & (~mm[i]))) {
            if (k++) printf(" ");
            printf("%s",t[i]);
         }
      }
      printf("\n");
   }
}
