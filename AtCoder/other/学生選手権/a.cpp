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
//#define MM 1000000000
//#define MOD MM+7
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

struct UnionFind {
	vector<int> par, rank, cnt;
	UnionFind(int n) : par(n), rank(n, 0), cnt(n, 1){
		for(int i=0; i<n; ++i) par[i] = i;
	}
 
	int find(int x) {
		if (x == par[x]) return x;
		return par[x] = find(par[x]);
	}
 
	void unite(int x, int y) {
		x = find(x); y = find(y);
		if (x == y) return;
 
		if (rank[x] < rank[y]) swap(x, y);
 
		par[y] = x;
		cnt[x] += cnt[y];
		if (rank[x] == rank[y]) rank[x]++;
	}
 
	bool same(int x, int y) {
		return find(x) == find(y);
	}
 
	int size(int x) {
		return cnt[find(x)];
	}
};


int main(){
    long long N,M; cin >> N >> M;
    vector<long long> a(M),b(M);
    vector<long long> ans(M);
    long long num = N*(N-1)/2;

    for (int i = 0; i < M; i++){
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
    }

    UnionFind uf(N);

    for (int i = M-1; i >= 0; i--){
        ans[i] = num;
        if (!uf.same(a[i],b[i])){
            num -= (long long)uf.size(a[i])*(long long)uf.size(b[i]);
            uf.unite(a[i],b[i]);
        }
    }

    for (int i = 0; i < M; i++){
        cout << ans[i] << endl;
    }
} 
