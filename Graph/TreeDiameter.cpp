#include <vector>
#include <queue>
#include <iostream>
using namespace std;




// AC : http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A&lang=jp
struct Edge
{
    int to, cost;
};

vector<bool> visited;
vector<vector<Edge> > g;
vector<int> dist;

// 'N'を頂点数として...
void DFS_for_TreeDiameter(int now, int from, vector<vector<Edge> > &G, int &maxDist, int &maxDistPos){
    visited[now] = true;
    if (dist[now] > maxDist){
        maxDist = dist[now];
        maxDistPos = now;
    }
    for (int i = 0; i < G[now].size(); i++){
        int To = G[now][i].to;
        if (To == from){
            continue;
        }
        dist[To] = dist[now] + G[now][i].cost;
        DFS_for_TreeDiameter(To, now, G, maxDist, maxDistPos);
    }
}


struct treeDiameterInfo
{
    int start, end, maxDist;
};

//始点、終点、最大距離を返す
treeDiameterInfo Implement(int N, vector<vector<Edge> > &G){
    int st = 0, fin = 0, maxDistPos = 0, maxDist = 0;
    visited.assign(N, false);
    dist.assign(N, 0);
    //始点情報を入手
    DFS_for_TreeDiameter(st, -1, G, maxDist, maxDistPos);
    //
    st = maxDistPos;
    //cout << "maxDistPos : " << maxDistPos << endl;
    maxDist = 0;
    maxDistPos = 0;
    visited.assign(N, false);
    dist.assign(N, 0);
    //終点情報を入手
    DFS_for_TreeDiameter(st, -1, G, maxDist, maxDistPos);
    
    treeDiameterInfo res;
    res.start = st, res.end = maxDistPos, res.maxDist = maxDist;
    return res;
}

int main(){
    int N; cin >> N;
    g.resize(N);
    dist.assign(N, 0);
    visited.assign(N, false);
    for (int i = 0; i < N-1; i++){
        int s, t, w; cin >> s >> t >> w;
        Edge e; e.to = t; e.cost = w;
        g[s].push_back(e);
        //無向グラフ
        e.to = s;
        g[t].push_back(e);
    }
    treeDiameterInfo result = Implement(N, g);
    cout << result.maxDist << endl;
}





