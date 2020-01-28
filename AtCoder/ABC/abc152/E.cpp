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
    ll N, A[10010]; 
    int maxIndex[1000100] = {0};
    vector<pair<int,int>> eachIndex(1000100); 

    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> A[i];
    }

    for (int i = 0; i < N; i++){
        ll now = A[i];
        if (i > 0 && A[i] == A[i-1]) continue;
        //素因数分解
        for (ll j = 2; j*j <= A[i]; j++){
            if (now % j == 0){
                int divCount = 0;
                while (now % j == 0){
                    now /= j;
                    divCount++;
                }
                maxIndex[j] = max(maxIndex[j], divCount);
            }
        }
        if (now > 1){
            maxIndex[now] = max(maxIndex[now], 1);
        }
    }

    //素因数分解の結果
    /*
    for (int i = 0; i < 1000100; i++){
        if (maxIndex[i]){
            cout << "NUM = " << i << ", INDEX = " << maxIndex[i] << endl;
        }
    }
    */
    

    ll ans = 0, mul = 1;
    for (int i = 2; i < 1000100; i++){
        if (maxIndex[i] > 0){
            ll tmp = 1;
            for (int j = 0; j < maxIndex[i]; j++){
                tmp *= i;
                tmp %= MOD;
            }
            mul *= tmp;
            mul %= MOD;
        }
    }
}