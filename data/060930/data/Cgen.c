#include <stdio.h>
#include <stdlib.h>

int i,j;
main(){
   printf("99\n");
   for (i=0;i<99;i++) {
      for (j=0;j<1000;j++){
         printf("%c","aaaaaaaabbbbbbb"[random()%15]);
      }
      printf("\n");
   }
   printf("100\n");
   for (i=0;i<100;i++) {
      for (j=0;j<1000;j++){
         printf("%c","aaaaaaaabbbbbbb"[random()%15]);
      }
      printf("\n");
   }
   printf("100\n");
   for (i=0;i<100;i++) {
      for (j=0;j<1000;j++){
         printf("%c","abbcccddddeeee"[random()%14]);
      }
      printf("\n");
   }
   printf("100\n");
   for (i=0;i<100;i++) {
      for (j=0;j<1000;j++){
         printf("%c","abcccccccccccc"[random()%14]);
      }
      printf("\n");
   }
   printf("100\n");
   for (i=0;i<100;i++) {
      for (j=0;j<1000;j++){
         printf("%c","abcdefghijklmnopqrstuvwxyz"[random()%26]);
      }
      printf("\n");
   }
   printf("100\n");
   for (i=0;i<100;i++) {
      for (j=0;j<1000;j++){
         printf("x");
      }
      printf("\n");
   }
   printf("0\n");
}
