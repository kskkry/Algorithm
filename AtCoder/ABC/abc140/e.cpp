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
struct edge {
    ll to,cost;
};
/*
const int COM_MAX = 500500;
long long fac[COM_MAX],finv[COM_MAX],inv[COM_MAX];
void init(){
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for(int i = 2; i < COM_MAX; i++){
        fac[i] = fac[i-1]*i%MOD;
        inv[i] = MOD - inv[MOD%i]*(MOD/i)%MOD;
        finv[i] = finv[i-1]*inv[i]%MOD;
    }
}
long long COM(int n,int k){
    if(n < k || n < 0 || k < 0) return 0;
    return fac[n]*(finv[k]*finv[n-k]%MOD)%MOD;
}
*/

int main(){
    int N; cin >> N;
    vector<int> p(N),inv(N);
    for (int i = 0; i < N; i++){
        cin >> p[i];
        inv[p[i]-1] = i;
    }
    set<int> s;
    ll ans = 0;
    for (int i = -2; i < N+2; i++){
        s.insert(i);
    }
    for (int i = 0; i < N; i++){
        int k = inv[i];
        s.erase(k);
        auto it1 = s.upper_bound(k);
        auto it2 = it1;
        int r1 = *it1;
        int r2 = *++it1;
        int l1 = *--it2;
        int l2 = *--it2;
        if (r1 < N){
            ans += (ll)(r2-r1)*(ll)(k-l1)*(i+1);
        }
        if (l1 >= 0){
            ans += (ll)(l1-l2)*(ll)(r1-k)*(i+1);
        }
        s.erase(k);
    }
    cout << ans << endl;
}