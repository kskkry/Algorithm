#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



//ABC120での解法
struct UnionFind {
	vector<int> par, rank, cnt;
	UnionFind(int n) : par(n), rank(n, 0), cnt(n, 1){
		for(int i = 0; i < n; ++i) par[i] = i;
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
