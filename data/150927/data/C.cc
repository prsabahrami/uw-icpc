#include <iostream>

using namespace std;

long long dp[40][40];

int main() {
  for (int i = 1; i <= 32; i++) dp[1][i] = i;

  // Compute DP
  for (int i = 2; i <= 32; i++) {
    dp[i][0] = 0;
    for (int j = 1; j <= 32; j++) {
      dp[i][j] = dp[i-1][j-1] + dp[i][j-1] + 1;
    }
  }

  int t;
  cin >> t;
  for (int test = 0; test < t; test++) {
	int n,k;  	
  	cin >> n >> k;
  	int idx = 0;
  	for (;idx <= 32; idx++) {
  		if (dp[k][idx] >= n) break;
  	}

  	if (dp[k][idx] >= n) {
  		cout << idx << endl;
  	} else {
  		cout << "Impossible" << endl;
  	}
  }

  return 0;
}
