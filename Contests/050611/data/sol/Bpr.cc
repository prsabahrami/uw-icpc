// PR, May 14, 2005

// 1 2
// 2 4  6
//   6  9 12
//     12 16 20
//        20 25 30
//           30 36 42
//              42 49 56

// Set 1 to 0, whatever is 2 then 4 has to be 0 because of the first
// two raws. 4 and 9 have to be the same bacause of raws 2 and 3
// and so on for all squares.

// find smallest binary magic string of lenght p-1 where p is prime 
// Set the diagonal of the magic square to 0's the rest to 1's.
// Indices that are quadratic residues mod p appear on the diagonal
// and p has the same number od residues and non-residues unless
// p is 2.
// there are 4 magic strings of any length except 2.

// The string must be a palindrom or its reverse is its complement.

#include <stdio.h>
#include <assert.h>
#include <math.h>

#define MAXP 100000

int isPrime(int a) {
  if (a < 2) return 0;
  for (int i = 2; i <= sqrt(a); i++) if (!(a%i)) return 0;
  return 1;
}

char A[MAXP+10];

int main () {
  while (1) {
    int p;
    scanf("%d",&p);
    if (!p) break;
    assert(isPrime(p) && p <= MAXP);
    if (p == 2) { printf("Impossible\n"); continue; }
    for (int i=1;i<p;i++) A[i] = '1';
    for (unsigned long long i=1;i<p;i++) 
      A[(i*i)%p]='0';
    for (int i=1;i<p;i++)
      printf("%c",A[i]);
    printf("\n");
  }
}
