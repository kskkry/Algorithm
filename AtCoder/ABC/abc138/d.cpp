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
#include <time.h>
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

const int MAX = 2e5;

//親と深さ
int parent[MAX],depth[MAX];

//初期化
void init(int n){
    for(int i = 0; i < n; i++){
        parent[i] = i;
        depth[i] = 0;
    }
}

//親の探索
int find(int x){
    if(parent[x] == x) return x;
    else return parent[x] = find(parent[x]);
}


//木の深さを減らし計算量を抑える
void unite(int x,int y){
    x = find(x);
    y = find(y);
    if(x == y) return;
    else if (depth[x] < depth[y]) parent[x] = y;
    else if (depth[x] == depth[y]){
        depth[x]++;
        parent[y] = x;
    }
    else parent[y] = x;
}

//確認
bool check(int x,int y){
    return find(x) == find(y);
}

//不要な場合あり
int size(int x){
    return -parent[find(x)];
}


int main(){
    int N,Q; cin >> N >> Q;
    long long weight[200020];
    fill(weight,weight+200002,0);
    int a,b;
    init(N);
    for (int i = 1; i < N; i++){
        cin >> a >> b;
        unite(a,b);
    }
    long long ans = 0;
    for (int i = 1; i <= Q; i++){
        int p,x; cin >> p >> x;
        int tmp = find(p);
        weight[tmp] += x;
    }
    for (int i = 1; i <= N; i++){
        int tmp = find(i);
        cout << weight[tmp];
        if (i != N) cout << " ";
        else cout << endl;
    }
}