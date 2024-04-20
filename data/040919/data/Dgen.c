#include <stdio.h>
#include <stdlib.h>

int i,j,k,a,b,c;
char tmp[1000];

main(){
   printf("150\n");
   for (i=0;i<100;i++) {
      a = random()%100+1;
      if (i%2) {
         for (j=0;j<a+1;j+=2) {
           tmp[j] = tmp[j+1] = "abcdefghijklmnopqrstuvwxyz"[random()%26];
         }
         tmp[a] = 0;
         for (j=0;j<a;j++) {
            k = random()%a;
            b = tmp[j];
            tmp[j] = tmp[k];
            tmp[k] = b;
         }
         printf("%s\n",tmp);
         for (j=0;j<a/2;j++) {
            b = tmp[j];
            tmp[j] = tmp[a-j-1];
            tmp[a-j-1] = b;
         }
         printf("%s\n",tmp);
      } else {
         for (j=0;j<a;j++) tmp[j] = "abcdefghijklmnopqrstuvwxyz"[random()%26];
         tmp[a] = 0;
         printf("%s\n",tmp);
      }
   }
}
