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
T lcm(T x,T y){
    return x*y/GCD(x,y);
}
const int SIZE = 100005;
vector<int> vec[SIZE];

bool use[SIZE]; //その頂点を使ったか判定
int dep[SIZE],deg[SIZE]; //


//全域木の構成をイメージ
void dfs(int v = 0,int p = -1,int d = 0){
    use[v] = true;
    dep[v] = d;
    //まずある頂点の出次数について考える
    for(int i = 0; i < vec[v].size(); i++){
        int to = vec[v][i];
        if (to != p){
            //未使用の頂点ならば再帰
            if (!use[to]) dfs(to,v,d+1);
            //頂点を使用済みならば比較(dep[v]=d)
            else if (dep[to] < dep[v]){
                cout << v+1 << " " << to+1 << endl;
                deg[v]++;
            }
        }
    }
    if (p != -1){
        //偶奇で分けて出力する頂点を選択
        if (deg[v]%2 == 1){
            cout << v+1 << " " << p+1 << endl;
            deg[v]++;
        } else {
            cout << p+1 << " " << v+1 << endl;
            deg[p]++;
        }
    }
}

int main(){
}

  

