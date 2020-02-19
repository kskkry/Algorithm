#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


template<class T> struct UnionFind {
	vector<T> par, rank, cnt;
	UnionFind(T n) : par(n), rank(n, 0), cnt(n, 1){
		for(int i = 0; i < n; ++i) par[i] = i;
	}
 
	T find(T x) {
		if (x == par[x]) return x;
		return par[x] = find(par[x]);
	}
	
 
	void unite(T x, T y) {
		x = find(x); y = find(y);
		if (x == y) return;
 
		if (rank[x] < rank[y]) swap(x, y);
 
		par[y] = x;
		cnt[x] += cnt[y];
		if (rank[x] == rank[y]) rank[x]++;
	}
 
	bool same(T x, T y) {
		return find(x) == find(y);
	}
 
	T size(T x) {
		return cnt[find(x)];
	}
};


