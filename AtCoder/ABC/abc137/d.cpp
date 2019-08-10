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
    long long N,M; cin >> N >> M;
    long long a,b;
    //int dp[100010]; fill(dp,dp+100010,MM);
    long long ans = 0;
    vector<pair<long long,long long>> p;
    for(int i = 0; i < N; i++){
        cin >> a >> b;
        p.push_back({a,b});
    }
    long long mx = 0,cnt = 0;

    sort(p.begin(),p.end());

    priority_queue<long long> pq;
    int pn = 0;
    for(int i = M-1; i >= 0; i--){
        int day = M-i;
        while(pn <= N && p[pn].first <= day){
            pq.push(p[pn++].second);
        }
        if (!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans << endl;



}
