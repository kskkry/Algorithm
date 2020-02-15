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
#include <cstring>
using namespace std;
#define pi pair<int,int>
#define pl pair<long long,long long>
#define chmax(a,b) (a<b ? a=b:0)
#define chmin(a,b) (a>b ? a=b:0)
#define en cout << endl //セミコロンつけろ
//#define MM 1000000000
//#define MOD MM+7
typedef long long ll;
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
    ll N, D, A; cin >> N >> D >> A;
    vector<ll> x(N), h(N);
    vector<pair<ll,ll>> vp(N);
    for (int i = 0; i < N; i++){
        cin >> x[i] >> h[i];
        vp[i] = {x[i], h[i]};
    }
    sort(vp.begin(), vp.end());
    vector<ll> used(N, 0);
    int nowIndex = 0;
    for (int i = 0; i < N; i++){
        if (used[i] < vp[i].second){
            while (vp[i].first + 2*D < vp[i+nowIndex].first){
                nowIndex++;
            }
        }
    }
}


