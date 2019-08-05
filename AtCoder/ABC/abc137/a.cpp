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
    int q; cin >> q;
    bitset<64> Bit(0);
    for(int i = 0; i < q; i++){
        int n; cin >> n;
        if (n == 0){
            int m; cin >> m;
            cout << Bit[m] << endl;
        } else if (n == 1){
            int m; cin >> m;
            Bit[m] = 1;
        } else if (n == 2){
            int m; cin >> m;
            Bit[m] = 0;
        } else if (n == 3){
            int m; cin >> m;
            Bit[m] = Bit[m]^1;
        } else if (n == 4){
            cout << Bit.all() << endl;
        } else if (n == 5){
            cout << Bit.any() << endl;
        } else if (n == 6){
            cout << Bit.none() << endl;
        } else if (n == 7){
            cout << Bit.count() << endl;
        } else {
            cout << Bit.to_ulong() << endl;
        }
    }
}