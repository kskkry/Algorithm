#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define pi pair<int,int>
#define pl pair<long long,long long>
#define chmax(a,b) (a<b ? a=b:0)
#define chmin(a,b) (a>b ? a=b:0)

//aoj:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C&lang=en
//ForthGraph, ReverseGraph
vector<vector<int> > fG, rG;
vector<int> visited, order, group; 

void fDFS(int u){
    visited[u] = true;
    for (int i = 0; i < fG[u].size(); i++){
        int to = fG[u][i];
        if (!visited[to]){
            fDFS(to);
        }
    }
    order.push_back(u);
}

void rDFS(int u, int k){
    visited[u] = true;
    group[u] = k;
    for (int i = 0; i < rG[u].size(); i++){
        int to = rG[u][i];
        if (!visited[to]){
            rDFS(to, k);
        }
    }
}

int main(){
    int V, E, Q; cin >> V >> E;
    fG.resize(V); rG.resize(V);
    visited.assign(V, 0); order.clear(); group.assign(V, -1);

    for (int i = 0; i < E; i++){
        int s, t; cin >> s >> t;
        fG[s].push_back(t);
        rG[t].push_back(s);
    }

    //帰りがけ順を求める
    for (int i = 0; i < V; i++){
        if (!visited[i]){
            fDFS(i);
        }
    }

    //強連結成分分解
    reverse(order.begin(), order.end());
    visited.assign(V, 0);
    int k = 0;
    for (int i = 0; i < order.size(); i++){
        int now = order[i];
        if (!visited[now]){
            rDFS(now, k);
            k++;
        }
    }

    cin >> Q;
    vector<int> ans(0);

    for (int i = 0; i < Q; i++){
        int u, v; cin >> u >> v;
        if (group[u] == group[v]){
            ans.push_back(1);
        } else {
            ans.push_back(0);
        }
    }

    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }
}