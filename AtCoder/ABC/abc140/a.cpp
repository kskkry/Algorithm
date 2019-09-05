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
int main(){
    int N; cin >> N;
    ll u,v,w;
    vector<vector<edge> > g(N);
    vector<ll> dist(N,-1);
    for (int i = 0; i < N-1; i++){
        cin >> u >> v >> w; u--; v--;
        w %= 2;
        g[u].push_back({v,w});
    }
    dist[0] = 0;
    queue<ll> que;
    que.push(0);
    while (que.size()){
        int top = que.front();
        que.pop();
        for (auto e : g[top]){
            if (dist[e.to] != -1) continue;
            if (dist[top] == 0){
                if (dist[e.cost]%2 == 0) dist[e.to] = 0;
                else dist[e.to] = 1;
            } else if (dist[top] == 1){
                if (dist[e.cost]%2 == 0) dist[e.to] = 1;
                else dist[e.to] = 0;
            }
            que.push(e.to);
        }
    }
    for (auto e : dist){
        if (e == -1) cout << 0 << endl;
        else cout << e << endl;
    }
}