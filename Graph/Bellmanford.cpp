#include <iostream>
#include <vector>
using namespace std;


const int MM = 1e9;
struct edge {int from,to,cost;};
int N,M,S;
vector<edge> v;
int dist[100010];

void Bellman(){
    fill(dist,dist+100010,MM);
    dist[S] = 0;
    for(int i = 0; i < N; i++){
        int update = 0;
        for(int j = 0; j < M; j++){
            edge e = v[j];
            if (dist[e.from] != MM && dist[e.to] > dist[e.from] + e.cost){
                dist[e.to] = dist[e.from] + e.cost;
                update = 1;
                if (i == N-1){
                    cout << "NEGATIVE CYCLE" << endl;
                    return;
                }
            }
        }
        if (!update) break;
    }
    for(int i = 0; i < N; i++){
        if (dist[i] == MM) cout << "INF" << endl;
        else cout << dist[i] << endl;
    }
    return;
}

int main(){
    cin >> N >> M >> S;
    for(int i = 0; i < M; i++){
        int a,b,c; cin >> a >> b >> c;
        v.push_back({a,b,c});
    }
    Bellman();
}