//任意定数
const int MAX = 1e5;

//親と深さ
int parent[MAX],depth[MAX];

//初期化
void init(int n){
    for(int i = 0; i < n; i++){
        parent[i] = i;
        depth[i] = 0;
    }
}

//親の探索
int find(int x){
    if(parent[x] == x) return x;
    else return parent[x] = find(parent[x]);
}


//木の深さを減らし計算量を抑える
void unite(int x,int y){
    x = find(x);
    y = find(y);
    if(x == y) return;
    else if (depth[x] < depth[y]) parent[x] = y;
    else if (depth[x] == depth[y]){
        depth[x]++;
        parent[y] = x;
    }
    else parent[y] = x;
}

//確認
bool check(int x,int y){
    return find(x) == find(y);
}

//不要な場合あり
int size(int x){
    return -parent[find(x)];
}


