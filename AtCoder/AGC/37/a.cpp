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
#include <tuple>
#include <stdio.h>
#include <bitset>
#include <limits.h>
#include <complex>
#include <deque>
#include <iomanip>
using namespace std;
#define pi pair<int32,int32>
#define pl pair<int64,int64>
#define chmax(a,b) (a<b ? a=b:0)
#define chmin(a,b) (a>b ? a=b:0)
#define en cout << endl //セミコロンつけろ
//#define MM 1000000000
//#define MOD MM+7
const int MM = 1e9;
const int MOD = MM+7;
const long double PI = acos(-1);
const long long INF = 1e15;
int dx[8] = {-1,0,1,0,-1,-1,1,1};
int dy[8] = {0,-1,0,1,-1,1,1,-1};
// 'A' = 65, 'Z' = 90, 'a' = 97, 'z' = 122
// cout << fixed << setprecision(10);
template<typename T>
T GCD(T u,T v){
    return v ? GCD(v,u%v) : u;
}
template<typename T>
T LCM(T x,T y){
    T gc = GCD(x,y);
    return x*y/gc;
}

long long N,K;
long long dp[60][2],a[100010];
int main(){
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    for(int i = 0; i < 59; i++){
        long long z = 0, o = 0;
        for(int j = 0; j < N; j++){
            if ((a[j] & (1LL << i)) == 0) z++;
            else o++;
        }
        if ((K & (1LL << i)) == 0) dp[i][0] = dp[i-1][0] + (o << i);
        else dp[i][0] = max(dp[i-1][0] + (z << i), dp[i-1][1] + (o << i));
        dp[i][1] = dp[i-1][1] + (max(z,o) << i);
    }
    cout << dp[58][0] << endl;
}