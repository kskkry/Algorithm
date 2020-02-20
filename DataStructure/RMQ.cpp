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
using namespace std;
#define pi pair<int32,int32>
#define pl pair<int64,int64>
#define chmax(a,b) (a<b ? a=b:0)
#define chmin(a,b) (a>b ? a=b:0)
#define en cout << endl //セミコロンつけろ
typedef long long ll;
const int MM = 1e9;
const int MOD = MM+7;
const long double PI = acos(-1);
const long long INF = 1e15;
int dx[8] = {-1,0,1,0,-1,-1,1,1};
int dy[8] = {0,-1,0,1,-1,1,1,-1};
// 'A' = 65, 'Z' = 90, 'a' = 97, 'z' = 122
// cout << fixed << setprecision(10);
template<typename T>
T GCD(T u,T v){
    return v ? GCD(v,u%v) : u;
}
template<typename T>
T LCM(T x,T y){
    T gc = GCD(x,y);
    return x*y/gc;
}



struct SegTree
{
    vector<int> pos;
    int limit;


    void Init(int _N){
        limit = 1;
        while (limit < _N){
            limit *= 2;
        }

        pos.resize(limit*2+1);
        for (int i = 0; i < limit*2-1; i++){
            pos[i] = MM;
        }
    }

    //index番目の値をnewNumに変更
    void Update(int index, int newNum){
        index += limit-1;
        pos[index] = newNum;
        while (index > 0){
            index = (index-1)/2;
            pos[index] = min(pos[index*2 + 1], pos[index*2 + 2]);
        }
    }

    //[givenLeft, givenRight]の最小値を求める
    int Query(int givenLeft, int givenRight, int now, int left, int right){
        if (right <= givenLeft || givenRight <= left) return MM;

        if (givenLeft <= left && right <= givenRight){
            return pos[now];
        } else {
            int leftUpdate = Query(givenLeft, givenRight, now*2 + 1, left, (left + right)/2);
            int rightUpdate = Query(givenLeft, givenRight, now*2 + 2, (left + right)/2, right);
            return min(leftUpdate, rightUpdate);
        }
    }
};


//Verify "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A&lang=jp"
int main(){
    int N, Q; cin >> N >> Q;
    const ll MAX = pow(2, 31)-1;
    SegTree segtree;
    segtree.Init(N);
    vector<ll> ans(0);
    for (int i = 0; i < Q; i++){
        int c, x, y; cin >> c >> x >> y;
        if (c == 0){
            segtree.Update(x, y);
        } else {
            int res = segtree.Query(x, y+1, 0, 0, segtree.limit);
            if (res == MM){
                ans.push_back(MAX);
            } else {
                ans.push_back(res);
            }
        }
    }
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }
}