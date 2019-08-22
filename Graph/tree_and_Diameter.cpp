#include <vector>
#include <queue>
#include <iostream>
using namespace std;

//木の直径
const int max_edge = 2;
vector<int> G[max_edge]; //頂点情報のみのグラフ

//treeDFS(親,現在地,根から現在地までの距離,根からの最大距離,根から最大の距離をとる頂点)
void treeDFS(int from,int current,int dist,int &maxDist,int &maxVertex){
    //距離と終点の更新
    if (dist > maxDist){
        maxDist = dist;
        maxVertex = current;
    }
    for (auto to : G[current]){
        //逆流を防ぐ
        if (to == from) continue;
        treeDFS(current,to,dist+1,maxDist,maxVertex);
    }
}

//直径を求める
int TreeDiameter(){
    int start = 0, end = 0,maxDist = 0;
    treeDFS(-1,start,0,maxDist,end);
    start = end,end = 0,maxDist = 0;
    treeDFS(-1,start,0,maxDist,end);
    return start;
}



//2つ目
const int INF = 1e9;
int n; vector<vector<pair<int,int>>> V;
int dist[100010];

void Treebfs(int s){
    queue<pair<int,int> > que;
    for (int i = 0; i < n; i++){
        dist[i] = INF;
    }
    dist[s] = 0;
    int t,wei;
    que.push(make_pair(s,0));
    while (que.size()){
        t = que.front().first;
        wei = que.front().second;
        que.pop();

        for (int i = 0; i < V[t].size(); i++){
            if (dist[V[t][i].first] == INF){
                dist[V[t][i].first] = wei + V[t][i].second;
                que.push(make_pair(V[t][i].first, dist[V[t][i].first]));
            }
        }
    }
}

int main(){
    cin >> n;
    int s,t,w;
    V.resize(n);
    for (int i = 0; i < n-1; i++){
        cin >> s >> t >> w;
        V[s].push_back(make_pair(t,w));
        V[t].push_back(make_pair(s,w));
    }
    Treebfs(0);
    int x = -1,mx = 0;
    for (int i = 0; i < n; i++){
        if (dist[i] == INF) continue;
        if (mx < dist[i]){
            x = i;
            mx = dist[i];
        }
    }
    Treebfs(x);
    mx = 0;
    for (int i = 0; i < n; i++){
        if (dist[i] == INF) continue;
        if (mx < dist[i]){
            mx = dist[i];
        }
    }
    cout << mx << endl;
}