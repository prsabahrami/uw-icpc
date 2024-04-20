#include <stdio.h>
#include <string.h>

int board[200][200];
int visit[200][200];
#define b(i,j) board[(i)+100][(j)+100]
#define v(i,j) visit[(i)+100][(j)+100]

int i,j,k,m,n,x,y,z,cookie = 1;
char P;

dump(){
   int i,j;
   for (i=-z;i<=z;i++) {
      for (j=-z;j<=z;j++) {
         if (b(i,j)) printf("%c",b(i,j));
         else printf("+");
      }
      printf("\n");
   }
   printf("\n");
   return;
   for (i=-z;i<=z;i++) {
      for (j=-z;j<=z;j++) {
         printf("%3d",v(i,j));
      }
      printf("\n");
   }
   printf("\n");
}

dofilled(int x, int y, int c, int B){
   //printf("dofilled %d %d %d %d\n",x,y,c,B);
   if (v(x,y) == cookie) return 1;
   if (b(x,y) == -1) return 1;
   if (b(x,y) == B) return 1;
   if (b(x,y) != c) return 0;
   v(x,y) = cookie;
   return dofilled(x+1,y,c,B) && dofilled(x-1,y,c,B)
       && dofilled(x,y+1,c,B) && dofilled(x,y-1,c,B); 
}

dofill(int x, int y, int d) {
   if (v(x,y) != cookie) return 0;
   if (b(x,y) == d) return 0;
   b(x,y) = d;
   v(x,y) = 0;
   return 1 + dofill(x+1,y,d) + dofill(x-1,y,d)
      + dofill(x,y+1,d) + dofill(x,y-1,d);
}

int reach(int x, int y, int c, int B, int d){
   cookie++;
   if (!dofilled(x,y,c,B)) return 0;
   return dofill(x,y,d);
}
int owns[256], caps[256];
update(int x, int y, int P, int Q){
   int cap = reach(x,y,Q,P,0);
   caps[P] += cap;
}
final(){
   int x,y;
   for (x=-z;x<=z;x++) {
      for (y=-z;y<=z;y++) {
         owns['W'] += reach(x,y,0,'W','w');
         owns['B'] += reach(x,y,0,'B','b');
      }
   }
}
int ii;
main(){
   //while (2 == scanf("%d%d",&n,&m) && n) {
   for (ii=0;ii<30;ii++){
      n = 19; m = 200;
      printf("%d %d\n",n,m);
      z = (n-1)/2;
      memset(board,0,sizeof(board));
      memset(owns,0,sizeof(owns));
      memset(caps,0,sizeof(owns));
      for (i=-z;i<=z;i++) b(i,-z-1) = b(i,z+1) = b(-z-1,i) = b(z+1,i) = -1;
      for (i=0;i<m;i++) {
         P = "WB"[random()%2];
         do { again:
            x = random()%n-n/2;
            y = random()%n-n/2;
         } while (b(x,y));
         b(x,y) = P;
         update(x+1,y,P,'B'+'W'-P);
         update(x-1,y,P,'B'+'W'-P);
         update(x,y+1,P,'B'+'W'-P);
         update(x,y-1,P,'B'+'W'-P);
         cookie++;
         if (update(x,y,'B'+'W'-P,P)) printf("bad move!");

 
         printf("%c(%d,%d)\n",P,x,y);
         //dump();
      }
      final();
      //dump();
      //printf("%d %d %d %d\n",owns['B'],caps['B'], owns['W'],caps['W']);
   }
   if (n || m) printf("missing/mangled end delimiter\n");
}
