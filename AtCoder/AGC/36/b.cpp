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
    long long n; cin >> n;
    long long t = n;
    bool flg = true;
    for(long long i = 2; i*i <= n; i++){
        if (t % i == 0){
            flg = false;
            break;
        }
    }
    if (n == 1){
        cout << "Not Prime" << endl;
        return 0;
    }
    if (flg){
        cout << "Prime" << endl;
        return 0;
    } else {
        long long in = t % 10;
        long long sum = 0;
        while(t > 0){
            sum += (t%10);
            t /= 10;
        }
        if (in % 2 != 0 && in != 5 && sum % 3 != 0){
            cout << "Prime" << endl;
            return 0;
        }
    }
    cout << "Not Prime" << endl;
}
  

