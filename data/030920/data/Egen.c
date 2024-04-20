#include <stdio.h>
#include <stdlib.h>

int i,j,k,m,n;

char *point[] = {
     "N","NbE","NNE","NEbN","NE","NEbE","ENE","EbN",
     "E","EbS","ESE","SEbE","SE","SEbS","SSE","SbE",
     "S","SbW","SSW","SWbS","SW","SWbW","WSW","WbS",
     "W","WbN","WNW","NWbW","NW","NWbN","NNW","NbW"};

main(){
   for (i=0;i<100;i++) {
      n = random()%1000;
      printf("%d\n",n);
      for (j=0;j<n;j++){
         k = random()%32;
         m = random()%10000+1;
         printf("%s %d\n",point[k],m);
      }
      printf("%0.2lf\n",(random()%180001-90000)/1000.0);
   }
   printf("0\n");
}
