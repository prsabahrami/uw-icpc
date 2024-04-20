#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char buf[1000];
int i,j;
spew(int n){
   printf("%d\n",n);
   for (i=0;i<n;i++) {
      sprintf(buf,"%d",i);
      for (j=0;buf[j];j++) buf[j] = 'a'+buf[j]-'0';
      printf("%s %0.0lf\n",buf,random()/(float)0x7fffffff*10000);
   }
}

main(){
   spew(2);
   spew(3);
   spew(1024);
   spew(1025);
   spew(1023);
   spew(2047);
   spew(2048);
   spew(2049);
   spew(2050);
   spew(2500);
   printf("0\n");
}
