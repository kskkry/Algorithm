#include<vector>
#include<iostream>
#include<queue>
using namespace std;
int v,e;
vector<int> In[10001],Out[10001],ans(0);
queue<int> Q;

//In[]は辺の始点,Out[]は辺の終点
//ansを逆さに出力

void toporogical_sort(){
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
