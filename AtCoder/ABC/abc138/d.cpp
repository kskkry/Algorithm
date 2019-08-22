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
#include <time.h>
using namespace std;
#define pi pair<int,int>
#define pl pair<long long,long long>
#define chmax(a,b) (a<b ? a=b:0)
#define chmin(a,b) (a>b ? a=b:0)
#define en cout << endl //セミコロンつけろ
//#define MM 1000000000
//#define MOD MM+7
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

long long N,Q;
long long wei[200020];
vector<vector<long long> > vp(200020);
void dfs(long long st){
    for (long long i = 0; i < vp[st].size(); i++){
        long long end = vp[st][i];
        wei[end] += wei[st];

        dfs(end);
    }
}

int main(){
    cin >> N >> Q;
    
    fill(wei,wei+200002,0);
    long long a,b;

    for (long long i = 1; i < N; i++){
        cin >> a >> b;
        vp[a].push_back(b);
    }
    //long long ans = 0;
    for (long long i = 1; i <= Q; i++){
        long long p,x; cin >> p >> x;
        wei[p] += x;
    }
    dfs(1LL);
    for (long long i = 1; i <= N; i++){
        cout << wei[i] << (i == N ? "\n" : " ");
    }


    cout << endl;
}
