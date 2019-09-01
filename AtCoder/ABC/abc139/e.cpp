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
#include <tuple>
#include <stdio.h>
#include <bitset>
#include <limits.h>
#include <complex>
#include <deque>
#include <iomanip>
#include <list>
#include <cstring>
#include <time.h>
using namespace std;
#define pi pair<int,int>
#define pl pair<long long,long long>
#define chmax(a,b) (a<b ? a=b:0)
#define chmin(a,b) (a>b ? a=b:0)
#define en cout << endl //セミコロンつけろ
//#define MM 1000000000
//#define MOD MM+7
typedef long long ll;
const int MM = 1e9;
const int MOD = MM+7;
const long double PI = acos(-1);
const long long INF = 1e15;
int dx[8] = {-1,0,1,0,-1,-1,1,1};
int dy[8] = {0,-1,0,1,-1,1,1,-1};
// 'A' = 65, 'Z' = 90, 'a' = 97, 'z' = 122
template<typename T>
T GCD(T u,T v){
    return v ? GCD(v,u%v) : u;
}
template<typename T>
T LCM(T x,T y){
    T gc = GCD(x,y);
    return x*y/gc;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    int a[1000][1000];
    bool graph[1000][1000];
    clock_t st = clock();
    memset(graph,false,sizeof(graph));
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N-1; j++){
            cin >> a[i][j];
            a[i][j]--;
        }
    }
    int in[1000]; fill(in,in+1000,0);

    int day = 0;
    int time = 0;
    while (true){
        bool game = false; //試合を行ったか
        day++;
        bool used[1000]; fill(used,used+1000,false);
        for (int i = 0; i < N; i++){
            int dest = a[i][in[i]];
            if (in[i] >= N-1) continue;
            if (graph[i][dest] == true || graph[dest][i] == true){
                //cout << "i : " << i << ", day = " << day << ", ";
                //cout << "dest = " << dest << endl;
                cout << -1 << endl;
                return 0;
            }
            if (used[i] || used[dest]) continue;
            //graph[i][a[i][in[i]]] = true;
            //graph[a[i][in[i]]][i] = true;
            
             //目的地の目的地
            int dest_of_dest = a[dest][in[dest]];
            if (in[dest] >= N-1) continue;
            if (dest_of_dest == i && used[i] == false && used[dest] == false){
                //cout << "day = " << day << ", i = " << i << ", dest = " << dest << endl;
                //cout << "";
                used[i] = true;
                used[dest] = true;
                graph[i][dest] = true;
                graph[dest][i] = true;
                
                in[dest]++;
                in[i]++;
                game = true;
            }
            if ((double)(clock()-st)/CLOCKS_PER_SEC >= 1.99){
                cout << N*(N-1)/2 << endl;
                return 0;
            }
        }

        bool flg = true;
        for (int i = 0; i < N; i++){
            if (in[i] < N-1) flg = false;
        }
        if (flg) break;
        if (day >= 499500){
            cout << -1 << endl;
            return 0;
        }
        if (!game){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << day << endl;
}
