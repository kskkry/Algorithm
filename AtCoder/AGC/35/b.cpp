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
    pair<bool,bool> G[n+10][n+10]; //first=辺がある,second=もう有向か
    int a,b,w,edge[n+10]; //矢印をつけていない辺の数
    fill(edge,edge+n+5,0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            G[i][j] = {false,false};
        }
    }


    for(int i = 0; i < m; i++){
        cin >> a >> b;
        a--; b--;
        G[a][b] = make_pair(true,false);
        G[b][a] = make_pair(true,false);
        edge[a]++;
        edge[b]++;
    }
    vector<pair<int,int> > ans(0); //格納
    for(int i = 0; i < n; i++){
        if (edge[i] <= 1) continue;
        else if (edge[i] % 2 == 0){
            for(int j = 0; j < n; j++){
                if (G[i][j].first == true && G[i][j].second == false){
                    ans.push_back({i,j});
                    G[i][j].first = false;
                    G[j][i].first = false;

                    G[i][j].second = true;
                    G[j][i].second = true;
                    edge[i]--;
                    edge[j]--;
                }
            }
        } else if (edge[i] % 2 == 1){
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if (G[i][j].first == true && G[i][j].second == false){
                    cnt++;
                    ans.push_back({i,j});
                    G[i][j].first = false;
                    G[j][i].first = false;

                    G[i][j].second = true;
                    G[j][i].second = true;
                    edge[i]--;
                    edge[j]--;
                    if (edge[i] == 1) break;
                }
            }
        }
    }
    if (ans.size() < m){
        cout << -1 << endl;
        return 0;
    }
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i].first +1 << " " << ans[i].second+1 << endl;
    }
}
  

