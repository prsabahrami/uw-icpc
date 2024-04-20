#include "testlib.h"

using namespace std;

const int MAX = 2000;
int dp[2][MAX + 1];

int main(int argc, char** argv) {
  registerTestlibCmd(argc, argv);
  const int N = inf.readInt();
  const int K = inf.readInt();
  const auto A = inf.readToken();
  const auto B = ouf.readToken();
  const auto jury = ans.readToken();
  if (jury == "WRONGANSWER") {
    quitif(B != jury, _wa, "WRONGANSWER not printed");
    quit(_ok, "");
  }
  quitif((int) B.size() != N, _wa, "B is not length N");
  for (char c : B)
    quitif(!islower(c), _wa, "B has non lowercase letter");
  int* cur = dp[0], * pred = dp[1];
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (A[i] == B[j])
        cur[j + 1] = pred[j] + 1;
      else
        cur[j + 1] = max(cur[j], pred[j + 1]);
    }
    swap(cur, pred);
  }
  printf("%d\n", pred[N]);
  quitif(pred[N] != K, _wa, "LCS of A and B is not K");
  quit(_ok, "");
}
