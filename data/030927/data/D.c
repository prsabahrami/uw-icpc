/*

   XYZZY ADVEN Game Solution

   Method:

      1.  V steps of Ford Fulkerson
      2.  If no progress after V steps we have
            the least-cost path (no cycles)
      3.  At the Vth cycle, one vertex of every
            strongly connected component with
            a negative cycle will be updated.
            All vertices that are updated are
            either members of or reachable from
            a negative cycle.  We can set all 
            other vertices to 'infeasible'
      4.  At the Vth cycle we can also set all
            edge costs to 0, because we don't
            care about the cost any more; only
            connectivity
      5.  Another V steps tells us if we can
            reach our goal

*/

#include <stdio.h>
#include <string.h>

int cost[101];
int best[101];
int last[101];
char adj[101][101];

int z,i,j,k,m,n,e,progress;
main(){
   while ((1 == scanf("%d",&n)) && n != -1){
      memset(adj,0,sizeof(adj));
      memset(last,0,sizeof(last));
      for (i=1;i<=n;i++) best[i] = 0x3fffffff;
      for (i=1;i<=n;i++) {
         scanf("%d%d",&e,&m);
         cost[i] = -e;
         for (j=0;j<m;j++) {
            scanf("%d",&k);
            adj[i][k] = 1;
         }
      }
      best[1] = -100;
      for (z=0;;z++) {
         progress = 0;
         for (i=1;i<=n;i++) for (j=1;j<=n;j++) {
            if (adj[i][j] &&
                best[i] < 0 && best[i] + cost[j] < 0 &&
                best[i] + cost[j] < best[j]){
                   best[j] = best[i] + cost[j];
                   progress = 1;
                   last[j] = z;
            }
         }
         if (!progress || best[n] < 0) break;
         if (z == n) {
            for (i=1;i<=n;i++) if (last[i] != z) best[i] = 0x3fffffff;
            for (i=1;i<=n;i++) cost[i] = 0;
         }
      }
      if (best[n] < 0 /*|| z == n*/) printf("winnable\n");
      else printf("hopeless\n");
   }
   if (n != -1) printf("missing end delimiter\n");
}
