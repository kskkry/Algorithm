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
int main(){
    int n,q; cin >> n >> q;
    queue<int> que[n];
    for(int i = 0; i < q; i++){
        int num; cin >> num;
        if (num == 0){
            int t,x; cin >> t >> x;
            que[t].push(x);
        } else if (num == 1){
            int t; cin >> t;
            if (que[t].size()){
                cout << que[t].front() << endl;
            }
        } else if (num == 2){
            int t; cin >> t;
            if (que[t].size()){
                que[t].pop();
            }
        }
    }
}
  

