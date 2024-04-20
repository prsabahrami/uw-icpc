#include <stdio.h>
#include <assert.h>

int main () {
  int ns, i, j, s;
  int shuffles[110][55];
  int od[55], nd[55];
  scanf("%d",&ns);
  for(i=1;i<=ns;i++)
    for(j=1;j<=52;j++) {
      scanf("%d",&shuffles[i][j]);
      assert(1 <= shuffles[i][j] && shuffles[i][j] <= 52);
  }
  for(i=1;i<=52;i++) od[i]=i-1;
  while(scanf("%d",&s) == 1) {
    assert(1 <= s && s <= ns);
    for(i=1;i<=52;i++) {
      nd[i] = od[shuffles[s][i]];
    }
    for(i=1;i<=52;i++) {
      switch (nd[i]%13) {
      case 9: printf("Jack"); break;
      case 10: printf("Queen"); break;
      case 11: printf("King"); break;
      case 12: printf("Ace"); break;
      default:
	printf("%d",(nd[i]%13)+2);
      }
      printf(" of ");
      switch(nd[i]/13) {
      case 0: printf("Clubs"); break;
      case 1: printf("Diamonds"); break;
      case 2: printf("Hearts"); break;
      case 3: printf("Spades"); break;
      }
      printf("\n");
    }
    for (i=1;i<=52;i++) od[i]=nd[i];
    printf("\n");
  }
  return 0;
}
