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
int main(){
    int N; cin >> N;
    string s; cin >> s;
    if (s[0] == 'W' || s[2*N-1] == 'W'){
        cout << 0 << endl;
        return 0;
    }
    int b = 1, w = 2;
    int a[200020];
    for (int i = 0; i < 2*N; i++){
        if (s[i] == 'B'){
            a[i] = b;
            b += 2;
        } else {
            a[i] = w;
            w += 2;
        }
    }
    b = 1,w = 2;
    for (int i = 2*N-1; i >= 0; i--){
        if (s[i] == 'B'){
            a[i] = min(a[i],b);
            b += 2;
        } else {
            a[i] = min(a[i],w);
            w += 2;
        }
    }
    int bmx = 0,wmx = 0;
    for (int i = 2*N-1; i >= 0; i--){
        if (s[i] == 'B'){
            bmx = max(bmx, a[i]);
        } else {
            wmx = max(wmx,a[i]);
        }
    }
    init();
    cout << (long long)(bmx * wmx * fac[N]) % MOD << endl;
}