#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <stack>
#include <numeric>
#include <algorithm>
#include <stdio.h>
#include <bitset>
#include <limits.h>
#include <complex>
#include <iomanip>
using namespace std;
#define MM 1000000000
#define MOD MM+7
#define pi pair<int32,int32>
#define pl pair<int64,int64>
#define chmax(a,b) (a<b ? a=b:0)
#define chmin(a,b) (a>b ? a=b:0)
#define en cout << endl //セミコロンつけろ
const long double PI = acos(-1);
const long long INF = 1e15;
int dx[8] = {-1,0,1,0,-1,-1,1,1};
int dy[8] = {0,-1,0,1,-1,1,1,-1};
template<typename T>
T GCD(T u,T v){
    return v ? GCD(v,u%v) : u;
}
template<typename T>
T LCM(T x,T y){
    T gc = GCD(x,y);
    return x*y/gc;
}

int main(){
    int n,m; cin >> n >> m;
    int c[m];
    int dp[200020];
    fill(dp,dp+200020,MM);
    for(int i = 0; i < m; i++){
        cin >> c[i];
    }
    dp[c[0]] = 1;
    dp[0] = 0;
    for(int i = 1; i < m; i++){
        for(int num = 0; num <= 2*n; num++){
            if (dp[num-c[i]] != MM) dp[num] = min(dp[num], dp[num-c[i]] + 1);
        }
    }
    cout << dp[n] << endl;
}
  

