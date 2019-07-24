#include<vector>
#include<algorithm> 
#include<iostream>

using namespace std;

#define pi pair<int,int>
#define pl pair<long long,long long>
#define ll long long
#define INF 1e9
#define MAX 1e5;
struct edge {ll from,to,cost;};

priority_queue<pi,vector<pi>,greater<pi>> que; //que.firstは最短距離,que.secondはindex
int N,M;                                       // Nは頂点数, Mは辺の数
int dist[N];                                   //ある頂点までの最短距離
vector<edge> G[MAX];                           //グラフ（問題によってはedgeの変数は減らせる）

void dijkstra(int n){
    fill(dist,dist+N,INF);  //初期化
    dist[n] = 0;          　//初期化
    
    que.push(pl(0,n));
    while(que.size()){
        pl p = que.top(); que.pop();
        int v = p.second;
        
        if(dist[v] < p.first) continue;
        for(int i = 0; i < G[v].size(); i++){
            edge e = G[v][i];
            if(dist[e.to] > dist[e.from]+e.cost){
                dist[e.to] = dist[e.from] + e.cost; //更新
                que.push(pl(dist[e.to],e.to));
            }
        }
    }
}
