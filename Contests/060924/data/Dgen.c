#include <stdio.h>
#include <stdlib.h>

char *ops = "NCAKEpqrstpqrstpqrstpqrtspppppppppptttttttttttttttttttt";

int i,j,k,m,n;
main(){
   for (i=0;i<strlen(ops);i++) {
      for (j=0;j<100;j++) {
         printf("%c",ops[random()%(i+1)]);
      }
      printf("\n");
   }
   printf("0\n");
}
