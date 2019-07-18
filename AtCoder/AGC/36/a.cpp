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
#include <deque>
#include <iomanip>
using namespace std;
#define MM 1000000000
#define MOD MM+7
#define pi pair<int32,int32>
#define pl pair<int64,int64>
#define chmax(a,b) (a<b ? a=b:0)
#define chmin(a,b) (a>b ? a=b:0)
const long double PI = acos(-1);
const long long INF = 1e15;
int dx[8] = {-1,0,1,0,-1,-1,1,1};
int dy[8] = {0,-1,0,1,-1,1,1,-1};
template<typename T>
T GCD(T u,T v){
    return v ? GCD(v,u%v) : u;
}
template<typename T>
T lcm(T x,T y){
    return x*y/GCD(x,y);
}
long long Pow(long long base,long long x){
    if (x == 0) return 1;
    if (x%2 == 1) return (base*Pow(base,x-1))%MOD;
    long long y = Pow(base, x/2);
    return y*y%MOD;
}
long long fac[100010],finv[100010],inv[100010];

const int MAX = 1010;
void init(){
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for(int i = 2; i < MAX; i++){
        fac[i] = fac[i-1]*i%MOD;
        inv[i] = MOD - inv[MOD%i]*(MOD/i)%MOD;
        finv[i] = finv[i-1]*inv[i]%MOD;
    }
}

long long COM(int n,int k){
    if(n < k || n < 0 || k < 0) return 0;
    return fac[n]*(finv[k]*finv[n-k]%MOD)%MOD;
}

long long Euler_phi(int n){
    long long ret = n; 
    for(long long i = 2; i*i <= n; i++){
        if (n%i == 0){
            ret -= ret/i;
            while(n % i == 0) n /= i;
        }
    }
    if (n != 1) ret -= ret/n;
    return ret;
}

int main(){
    long long n; cin >> n;
    cout << Euler_phi(n) << endl;
}
  

