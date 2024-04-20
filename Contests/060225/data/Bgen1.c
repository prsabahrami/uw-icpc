main(){
   int i,j,k;
   printf("19 %d\n",17*17+17*4);
   for (i=-8;i<=8;i++) {
      for (j=-8;j<=8;j++) {
         printf("W(%d,%d)\n",i,j);
      }
      printf("B(-9,%d)\n",i);
      printf("B(9,%d)\n",i);
      printf("B(%d,9)\n",i);
      printf("B(%d,-9)\n",i);
   }
}
