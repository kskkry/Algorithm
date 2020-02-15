#include<vector>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int v,e;
vector<int> In[10001],Out[10001],ans(0);
queue<int> Q;

//In[]は辺の始点,Out[]は辺の終点
//ansを逆さに出力

vector<int> IsChecked;
vector<int> out;

void Topological(int now, vector<vector<int> > &graph){
    //更新
    IsChecked[now] = 1;

    //探索
    for (int i = 0; i < graph[now].size(); i++){
        int targetPosition = graph[now][i];
        /*
        探索済みの頂点から先は同様に探索済みである
        つまり既に out に格納されているためこれ以上探索する必要がない
        一方、まだ探索されていない頂点については再帰的に探索し、
        順に格納することで題意を満たせる
        */
        if (IsChecked[targetPosition]) continue;
        Topological(targetPosition, graph);
    }
    //終点近くの頂点から順に格納できる
    out.push_back(now);
}


int main(){
    int N, M; cin >> N >> M;
    vector<vector<int> > graph(N);
    for (int i = 0; i < M; i++){
        //頂点uから頂点vへの有向辺をつくる
        int u, v; cin >> u >> v; u--; v--;
        graph[u].push_back(v);
    }

    IsChecked.resize(N, 0); //未探索
    out.resize(N, 0); //出力するために格納するもの

    for (int now = 0; now < N; now++){
        if (IsChecked[now]) continue;
        else {
            IsChecked[now] = 1;
            Topological(now, graph);
        }
    }

    reverse(out.begin(), out.end());
    for (int i = 0; i < out.size(); i++){
        cout << out[i] << endl;
    }
    return;
}




/*
//Other Solution
void topological_sort(){
    for(int i = 0; i < v; i++){
        if(!In[i].size()) Q.push(i);
    }
    while(!Q.empty()){
        int t = Q.front(); 
        Q.pop();
        ans.push_back(t);
        for(int i = 0; i < Out[t].size(); i++){
            int nx = Out[t][i];
            int size = In[nx].size();
            for(int j = 0; j < size; j++){
                if(In[nx][j] == t){
                    In[nx].erase(In[nx].begin()+j);
                    break;
                }
            }
            if(!In[nx].size()) Q.push(nx);
        }
    }
}

*/