#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

template<class T> struct UnionFind {
    const T sum = 0;
    vector<int> par;
    vector<T> weight;

    UnionFind(int n) : par(n,-1), diff_weight(n,sum);
    void init(int n) {
        par.assign(n,-1);
        diff_weight(n, sum);
    }

    int root(int x){
        if (par[x] < 0) return x;
        else {
            int r = root(par[x]);
            diff_weight[x] += diff_weight[par[x]];
            return par[x] = r;
        }
    }
     
    T function_weight(int x){
        root(x);
        return diff_weight[x];
    }

    bool same(int x,int y){
        return root(x) == root(y);
    }

    bool merge(int x,int y,T w = 0){
        w += function_weight(x); 
        w -= function_weight(y);

        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]){
            swap(x,y);
            w *= -1;
        }
        par[x] += par[y];
        par[y] = x;
        diff_weight[y] = w;
        return true;
    }

    T diff(int x,int y){
        return function_weight(y) - function_weight(x);
    }

    int size(int x){
        return -par[root(x)];
    }
};


//以下は引用
//ABC-087-D
int main() {
    int N, M;
    cin >> N >> M;
    UnionFind<long long> uf(N);
    for (int i = 0; i < M; ++i) {
        int l, r, d; cin >> l >> r >> d; --l, --r;
        if (uf.same(l, r)) {
            long long diff = uf.diff(l, r);
            if (diff != d) {
                puts("No");
                return 0;
            }
        }
        else {
            uf.merge(l, r, d);
        }
    }
    puts("Yes");
}


