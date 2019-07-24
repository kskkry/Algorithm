#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct edge {
    int to,weight,height;
};

typedef vector<edge> Edge;
typedef vector<Edge> Graph;

int Heightcalc(Graph &G,int i,int j){
    if (G[i][j].height > 0) return G[i][j].height;
    G[i][j].height = G[i][j].weight;
    int u = G[i][j].to;
    for(int k = 0; k < G[u].size(); k++){
        if (G[u][k].to == i) continue;
        G[i][j].height = max(G[i][j].height, Heightcalc(G,u,k) + G[i][j].weight);
    }
    return G[i][j].height;
}

int main(){
    int V,E,s,t,w;
    edge e;
    cin >> V;
    E = V-1;
    Graph G(V);
    vector<int> h(V,0);

    for (int i=0;i<E;i++){
        cin >> s >> t >> w;
        e.to=t;
        e.weight=w;
        e.height=-1;
        G[s].push_back(e);
        e.to=s;
        e.weight=w;
        e.height=-1;
        G[t].push_back(e);
    }
     
    for(int i=0;i<V;i++){
        for (int j=0;j<G[i].size();j++){
            Heightcalc(G,i,j);
        }
    }
     
    for (int i=0;i<V;i++){
        for (int j=0;j<G[i].size();j++){
            h[i]=max(h[i],G[i][j].height);
        }
        cout << h[i] <<endl;
    }
     
    return 0;
}