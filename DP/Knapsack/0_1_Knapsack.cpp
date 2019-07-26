#include <iostream>
#include <algorithm>
using namespace std;
#define MM 1e9
#define MAX_N 100
#define MAX_V 100
#define INF 2000000000
using namespace std;

int n, W;
int v[MAX_N + 1], w[MAX_N + 1];
long long dp[MAX_N + 1][MAX_N * MAX_V + 1];

void solve() {
  for (int i = 0; i < MAX_N + 1; i++) {
    for (int j = 0; j < MAX_N * MAX_V + 1; j++) {
      dp[i][j] = INF;
    }
  }

  for (int i = 0; i <= n; i++) {
    dp[i][0] = 0;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < MAX_N * MAX_V + 1; j++) {
      if (j - v[i] < 0) dp[i][j] = dp[i - 1][j];
      else dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i]);
    }
  }

  int max = 0;
  for (int i = 1; i < MAX_N * MAX_V + 1; i++) {
    if (dp[n][i] <= W) max = i;
  }
  cout << max << endl;
}