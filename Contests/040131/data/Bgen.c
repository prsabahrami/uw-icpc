#include <stdio.h>
#include <stdlib.h>

int m[] = {1,10,100,1000};

int sz,i,j,k;

main(int argc, char **argv){
   if (argc == 2) sz = atoi(argv[1]); else sz = 100000;
   printf("%d\n",k=sizeof(m)/sizeof(int));
   for (i=0;i<k;i++){
      printf("%d %d\n",sz,m[i]);
      for (j=0;j<sz;j++) printf("%d %d\n",random()%(1000000*2+1)-1000000,
                     random()%(1000000*2+1)-1000000);
   }
}
