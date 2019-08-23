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

int n,q; 
const int MAX = 1 << 17;
int dat[MAX*2];
void SegT(){
    int tmp = 1;
    while (tmp < n) tmp >>= 1;
    n = tmp;
    for (int i = 0; i < n*2-1; i++){
        dat[i] = INT_MAX;
    }
}
void update(int k,int x){
    k += n-1;
    dat[k] = x;
    while (k > 0){
        k = (k-1)/2;
        dat[k] = min(dat[k*2 + 1], dat[k*2 + 2]);
    }
}
int find(int a,int b,int k,int l,int r){
    if (r <= a || b <= l) return INT_MAX;
    if (a <= l && r <= b) return dat[k];
    int v1 = find(a,b,k*2 + 1, l, (l+r)/2);
    int v2 = find(a,b,k*2 + 2, (l+r)/2, r);
    return min(v1,v2);
}

int main(){
    cin >> n >> q;
    SegT();
    for (int i = 0; i < q; i++){
        int c,x,y; cin >> c >> x >> y;
        if (c == 0) {
            update(x,y);
        } else {
            cout << find(x,y+1,0,0,n) << endl;
        }
    }
}