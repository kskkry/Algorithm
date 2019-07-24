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
#include <math.h>
#include <iomanip>
using namespace std;
//using ll = long long;
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

//First
//クラスカル法 <= UnionFind
#define MAX 100000

int par[MAX],rank_[MAX];
void init(int n){
    for(int i = 0; i < n; i++){
        par[i] = i;
        rank_[i] = 0;
    }
}
int find(int x){
    if (par[x] == x) return x;
    return par[x] = find(par[x]); 
}

void unite(int x,int y){
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (rank_[x] < rank_[y]){
        par[x] = y;
    } else {
        par[y] = x;
        if (rank_[x] == rank_[y]){
            rank_[x]++;
        }
    }
}
bool same(int x,int y){
    return (find(x) == find(y));
}

struct edge{ int u,v,cost; };

//sort用
bool comp(const edge &e1, const edge &e2){
    return e1.cost < e2.cost;
}
int V,E;
edge es[MAX];

int kruskal(){
    sort(es,es+E,comp); //comp使う（sort）
    init(V);
    int res = 0;
    for (int i = 0; i < E; i++){
        edge e = es[i];
        if (!same(e.u, e.v)){
            unite(e.u, e.v);
            res += e.cost; //結合＋コスト増加
        }
    }
    return res;
}

int main(){
    cin >> V >> E;
    for (int i = 0; i < E; i++){
        int s,t,w; cin >> s >> t >> w;
        es[i] = (edge){s,t,w};
    }
    cout << kruskal() << endl;
    return 0;
}
  





//Second



// Union Find用
class DisjointSet {
private:
  vector<int> p;
  
public:
  DisjointSet(int size) : p(size, -1) {}

  bool unite_set(int x, int y) {
    x = root(x);
    y = root(y);
    
    if (x != y) {
      if (x > y) { swap(x, y); }
      p[x] += p[y];
      p[y] = x;
    }   

    return x != y;
  }

private:
  int root(int x) {
    return p[x] < 0 ? x : p[x] = root(p[x]);
  }
};

// 通路
struct corridor {
  int a, b;     // 繋がっているcell
  double len;   // 通路の長さ
  corridor(int a, int b, double len) : a(a), b(b), len(len) {}

  // ソート用
  bool operator <(const corridor& rhs) const {
    if (len != rhs.len) { return len < rhs.len; }
    if (a != rhs.a) { return a < rhs.a; }
    return b < rhs.b;
  }
};

double dist(double x1, double y1, double z1, double x2, double y2, double z2) {
  return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + (z1-z2)*(z1-z2));
}

int main() {
  int n;
  while (cin >> n && n) {
    double x[100], y[100], z[100], r[100];
    for (int i = 0; i < n; i++) {
      cin >> x[i] >> y[i] >> z[i] >> r[i];
    }

    // 全ての通路を長さでソートする
    vector<corridor> cor;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        cor.push_back(corridor(i, j, max(0.0, dist(x[i], y[i], z[i], x[j], y[j], z[j]) - r[i] - r[j])));
      }
    }
    sort(cor.begin(), cor.end());

    DisjointSet ds(n);
    double ans = 0;   // 通路の長さの総和
    int count = 0;    // 選んだ通路の数

    for (vector<corridor>::iterator itr = cor.begin(); count < n - 1; itr++) {
      // aとbが別々の集合に属しているならばその通路を採用する
      if (ds.unite_set(itr->a, itr->b)) {
        ans += itr->len;
        count++;
      }
    }

    printf("%.3f\n", ans);
  }
  return 0;
}
