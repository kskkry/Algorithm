#include <iostream>
#include <algorithm>
using namespace std;
#define MM 1e9

int main(){
    int N,W; cin >> N >> W;
    int dp[101][100100]; //N,N*v;
    for(int i = 0; i < 101; i++){
        for(int j = 0; j < 100010; j++){
            dp[i][j] = MM;
        }
    }
    int v[101],w[101];
    for(int i = 0; i < N; i++){
        cin >> v[i] >> w[i];
    }
    //初期化
    dp[0][v[0]] = w[0];
    dp[0][0] = 0;
    //
    for(int i = 1; i < N; i++){
        for(int val = 0; val <= 10010; val++){
            dp[i][val] = dp[i-1][val];
            if (dp[i-1][val] != MM && val >= v[i]){
                //価値は同じなので重みを最小化(-1を除く)
                dp[i][val] = min(dp[i][val], dp[i-1][val-v[i]] + w[i]); 
            }
        }
    }
    int mx = 0;
    for(int i = 0; i <= W; i++){
        mx = max(mx,dp[N-1][i]);
    }
    cout << mx << endl;
    return 0;
}