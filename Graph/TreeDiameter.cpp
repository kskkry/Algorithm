#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<bool> visited;
vector<vector<int> > g;
vector<int> dist;

// 'N'を頂点数として...
pair<int, int> DFS_for_TreeDiameter(int now, int from, vector<vector<int> > &G, int maxDist, int maxDistPos){
    for (int i = 0; i < G[now].size(); i++){
        int to = G[now][i];
        if (to == from) continue; //逆流を防ぐ
        if (dist[to] == 0){
            dist[to] = dist[now] + 1;
            if (dist[to] > maxDist){
                maxDist = dist[to];
                maxDistPos = to;
            }
            DFS_for_TreeDiameter(to, now, G, maxDistPos);
        }
    }
    pair<int,int> re = {maxDist, maxDistPos};
    return re;
}


void Implement(){
    int start = 0, fin = 0, maxDistPos = 0, maxDist = 0;
}

int main(){
    int N; cin >> N;
    g.resize(N);
    dist.assign(N, 0);
}





