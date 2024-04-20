#include <stdio.h>

double cost[110][201], price[110];
int dist[110];

int i,j,k,n,d,stop,next;

main(){
   scanf("%d",&d);
   dist[0] = 0;
   price[0] = 1e99;
   for (n=1;2==scanf("%d%lf",&dist[n],&price[n]);n++);
   dist[n] = d;
   price[n++] = 1e99;
   for (i=0;i<n;i++) for (j=0;j<=200;j++) cost[i][j] = 1e99;
   cost[0][100] = 0;

   for (stop=0;stop<n;stop++) {
      for (i=0;i<=200;i++) {
         for (next=stop; next<n && dist[next]-dist[stop] <= i; next++) {
            if (cost[stop][i] < cost[next][i-dist[next]+dist[stop]]) {
               cost[next][i-dist[next]+dist[stop]] = cost[stop][i];
            }
         }
         for (j=i+1;j<=200;j++) {
            if (cost[stop][i] + (j-i)*price[stop] < cost[stop][j]) {
               cost[stop][j] = cost[stop][i] + (j-i)*price[stop];
            }
         }
      }
   }
   if (cost[n-1][100] < 1e98) printf("%0.0lf\n",cost[n-1][100]);
   else printf("Impossible\n");
}
