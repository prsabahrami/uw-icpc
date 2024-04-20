/**
 * Deon Nicholas' solution to "Enumerating Brackets"
 *
 * We construct the desired string incrementally by appending "(" and ")".
 * At any point in time we define the 'balance' (b) of the partial string
 * to be: ([number of open brackets] minus [number of close brackets]).
 *
 * It can be proven that a string constructed incrementally is "balanced"
 * if and only if the balance is always >= 0 at any time, and ends up as 0.
 *
 * Now, let W(n,b) to be the number of ways to append n more characters
 * to make a balanced bracket sequence, given that the current "balance" is b.
 *
 * We can compute W(n,b) using dynamic programming (aka recursion with
 * memoization). That is, W(n,b) can be computed in terms of W(n-1,b+1)
 * and W(n-1,b-1), and the base cases are W(0,0) = 1, W(0,b>0) = 0.
 *
 * Once we have a way to compute W(n,b) for all n and b, the problem is
 * much simpler, using W(n,b) as a "sub-routine".
 *
 * We construct the string incrementally. At each stage, we try appending
 * a "(" first (because "(" is lexicographically smaller than ")").
 * If there are enough strings such that we can still reach
 * the Mth string, then we move on. Otherwise, we try appending
 * a ")" instead. One of these must work, and then we move on.
 *
 * We keep going, keeping careful track of n,b, and the number of valid
 * strings with this prefix (plus number of strings we've "skipped", etc.)
 * until the string has length N. By the way we constructed it,
 * it *must* be the Mth lexicographical string.
 *
 * Sorry for the weird explanation... but it works.
 **/

#include <iostream>
#include <ctime>
#include <fstream>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

#define INF 1000000000000000005ll
#define MAXN 2002

#define add(x,y) (((x)+(y)) >= INF ? INF : ((x) + (y)))

ll dp[MAXN][MAXN];
ll ways(int n, int b) {
  ll& ans = dp[n][b];

  if (ans >= 0) return ans;
  if (n==0 && b==0) return ans = 1;
  if (n==0 && b>0) return ans = 0;
  assert(n>0 && b>=0);

  // try an open bracket (increases "balance" by 1)
  ll place_open_bracket = ways(n-1, b+1);

  // try a close bracket (decreases "balance" by 1... if possible)
  ll place_close_bracket = (b>0 ? ways(n-1,b-1) : 0);

  ans = add(place_open_bracket, place_close_bracket);
  return ans;
}

char S[MAXN];

int main() {
  int N;
  ll M;

  cin >> N >> M;

  memset(dp,-1,sizeof(dp));
  memset(S,0,sizeof(S));

  assert((N%2) == 0);

  ll TOTAL_WAYS = ways(N,0);
  assert(M <= TOTAL_WAYS);

  M--;  // easier for me to do 0-indexed

  // constructively build up the solution
  // using the dp table / "ways" function as a guide
  int n = N;
  int b = 0;
  ll skipped = 0;

  while(n) {
    ll with_open_bracket = ways(n-1, b+1);
    
    if (skipped + with_open_bracket > M) {
      // the desired string must have an open bracket next
      S[N-n] = '(';
      b++;
    } else {
      // not enough strings with an open bracket next. must have closed bracket
      skipped += with_open_bracket;
      S[N-n] = ')';
      b--;
    }

    assert(b>=0);
    n--;
  }

  assert(skipped == M);
  assert(n == 0 && b==0);

  printf("%s\n",S);
}