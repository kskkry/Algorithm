#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

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

int main(int argc, char const* argv[]) {
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
