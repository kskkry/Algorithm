#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <stack>
#include <numeric>
#include <algorithm>
#include <stdio.h>
#include <bitset>
#include <limits.h>
#include <complex>
#include <iomanip>
using namespace std;
#define MM 1000000000
#define MOD MM+7
#define pi pair<int32,int32>
#define pl pair<int64,int64>
#define chmax(a,b) (a<b ? a=b:0)
#define chmin(a,b) (a>b ? a=b:0)
const long double PI = acos(-1);
const long long INF = 1e15;
int dx[8] = {-1,0,1,0,-1,-1,1,1};
int dy[8] = {0,-1,0,1,-1,1,1,-1};
template<typename T>
T GCD(T u,T v){
    return v ? GCD(v,u%v) : u;
}
template<typename T>
T lcm(T x,T y){
    return x*y/GCD(x,y);
}
int main(){
    int n,m; cin >> n >> m;
    vector<vector<pair<int,bool> > > G(n);
    int a,b,w,edge[n]; //矢印をつけていない辺の数
    fill(edge,edge+n,0);
    bool visited = false;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        a--; b--;
        G[a].push_back({b,false});
        G[b].push_back({a,false});
        edge[a]++;
        edge[b]++;
    }
    vector<pair<int,int> > ans(0); //格納
    for(int i = 0; i < n; i++){
        if (edge[i] <= 1){
            continue;
        } else if (edge[i] % 2 == 0){
            for(int num = 0; num <= G[i].size(); num++){
                if (i == G[i][num].first) continue;
                if (G[i][num].second == false){
                    G[i][ G[i][num].first ].second = true;
                    G[ G[i][num].first ][i].second = true;
                    ans.push_back({i,G[i][num].first});
                    edge[i]--;
                    edge[G[i][num].first]--;
                    cout << "1:" << i << " " << G[i][num].first << endl;
                }
            }
        } else {
            int cnt = 0;
            for(int num = 0; num <= G[i].size(); num++){
                if (i == G[i][num].first) continue;
                if (G[i][num].second == false){
                    cnt++;
                    G[i][ G[i][num].first ].second = true;
                    G[ G[i][num].first ][i].second = true;
                    ans.push_back({i,G[i][num].first});
                    edge[i]--;
                    edge[G[i][num].first]--;
                    cout << "2:" << i << " " << G[i][num].first << endl;
                    if(cnt+1 == G[i].size()){
                        break;
                    }
                }
            }
        }
    }
    cout << endl;
    //check
    for(int i = 0; i < n; i++){
        if(edge[i] > 0){
            cout << "-1" << endl;
            return 0;
        }
    }
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i].first+1 << " " << ans[i].second+1 << endl;
    }
}
  

