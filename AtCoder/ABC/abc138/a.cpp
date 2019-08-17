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
#include <list>
#include <time.h>
using namespace std;
#define pi pair<int,int>
#define pl pair<long long,long long>
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
template<typename T>
T GCD(T u,T v){
    return v ? GCD(v,u%v) : u;
}
template<typename T>
T LCM(T x,T y){
    T gc = GCD(x,y);
    return x*y/gc;
}

long long func(long long a,long long b){
    return a/b;
}

int main(){
    int N,M; cin >> N >> M;
    int a[100010],st[100010];
    fill(st,st+100010,1);
    long long dp[100010];
    fill(dp,dp+100010,0);
    dp[0] = 1;
    for (int i = 0; i < M; i++){
        cin >> a[i];
        st[a[i]] = 0;
    }
    for (int i = 0; i < N+10; i++){
        if (st[i] == 0) continue;
        if (st[i+2] == 1){
            dp[i+2] += dp[i];
            dp[i+2] %= MOD;
        }
        if (st[i+1] == 1){
            dp[i+1] += dp[i];
            dp[i+1] %= MOD;
        }
    }
    cout << dp[N] << endl;
}



