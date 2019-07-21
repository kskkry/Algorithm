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
#include <math.h>
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
    return x*y/(T)GCD(x,y);
}

inline void bfs(int start,int end,vector<vector<int> > G,int dist[]){
    //if (G[start].size() == 0) return;
    if (start == end) return;
    for(int i = 0; i < G[start].size(); i++){
        if (dist[G[start][i]] >= dist[start]+1){
            dist[G[start][i]] = min(dist[G[start][i]],dist[start]+1);
            bfs(G[start][i],end,G,dist);
        }
    }
}
int main(){
}





