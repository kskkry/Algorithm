#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N,W; cin >> N >> W;
    int dp[10010];
    fill(dp,dp+W+1,-1);
    dp[0] = 0;
    for(int i = 0; i < N; i++){
        int v,w; cin >> v >> w;
        for(int j = w; j <= W; j++){
            if (dp[j-w] != -1) dp[j] = max(dp[j - w] + v, dp[j]);
        }
    }
    int ans = 0;
    for(int i = 0; i <= W; i++){ // i <= W+1 だとWA
        ans = max(ans, dp[i]);
    }
    //cout << *max_element(dp,dp+W+1) << endl;
    cout << ans << endl;
}