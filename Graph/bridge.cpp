//ライブラリにするほどか？
//橋
#include<bits/stdc++.h>

using namespace std;
#define MAX_N 100001
vector<int> G[MAX_N];
vector<pair<int,int> > ans;
int cnt[MAX_N],dep[MAX_N];

void dfs(int pos,int pre){
    for(int i = 0; i < G[pos].size(); i++){
        //各枝
        int nx = G[pos][i];
        if (nx == pre || dep[nx] > dep[pos]) continue;
        
        if (dep[nx] != -1 && dep[nx] < dep[pos]){
            cnt[nx]--;
            cnt[pos]++;
        } else {
            dep[nx] = dep[pos] + 1;
            dfs(nx,pos);
            if (cnt[nx] == 0){
                ans.push_back({min(pos,nx),max(pos,nx)});
            }
            cnt[pos] += cnt[nx];
        }
    }
}


int main(){
    int n,m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a,b; cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    memset(dep,-1,sizeof(dep));
    dep[0] = 0;
    dfs(0,-1);
    sort(ans.begin(),ans.end());
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    //return 0;
}