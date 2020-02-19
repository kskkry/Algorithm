#include <iostream>
#include <algorithm>
#define INF 1e9
using namespace std;
const int MAX_V = 1e4;
int cost[MAX_V][MAX_V];
int mincost[MAX_V];
bool used[MAX_V];
int v;

//出典「蟻本」
int prim(){
    for(int i = 0; i < v; i++){
        mincost[i] = INF;
        used[i] = false;
    }
    int res = 0;
    mincost[0] = 0;
    while(true){
        int v = -1;
        //今存在する木から、最小距離かつまだ接続していない点を探す
        for(int u = 0; u < v; u++){
            if(!used[u] && (v == -1 || mincost[u] < mincost[v])) v = u;
        }

        if(v == -1) break;
        used[v] = true;
        res += mincost[v];

        for(int u = 0; u < v; u++){
            mincost[u] = min(mincost[u],cost[v][u]);
        }
        return res;
    }
}