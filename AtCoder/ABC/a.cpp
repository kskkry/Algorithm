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

long long pow_mod(long long n,long long k,long long m){
    if (k == 0){
        return 1;
    } else if (k % 2 == 1){
        return pow_mod(n,k-1,m)*n % m;
    } else {
        long long t = pow_mod(n,k/2,m);
        return t*t % m;
    }
}

vector<long long> divisor(long long x){
    vector<long long> res;
    for(long long i = 1; i*i <= x; i++){
        if (x % i == 0){
            res.push_back(i);
            if (i*i != x) res.push_back(x/i);
        }
    }
    sort(res.begin(),res.end());
    return res;
}


int main(){
    int n,a,b; cin >> n >> a >> b;
    cout << n*(100+b)/100 - n*(100+a)/100 << endl;
}
