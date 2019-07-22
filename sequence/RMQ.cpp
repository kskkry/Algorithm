#include <iostream>
#include <algorithm>
using namespace std;

const int N = 200020;
const int INF = (1LL << 31) - 1;
//Range Minimum Query

class RMQ{
    public:
        int n,dat[2*N-1];
    //初期化
    void init(int _n){
        n = 1;
        while(n < _n) n *= 2;
        fill(dat,dat + 2*n - 1, INF);
    }

    //区間ごとの範囲の更新
    void update(int k,int a){
        k += n-1;
        dat[k] = a;
        while(k > 0){
            k = (k-1)/2;
            dat[k] = min(dat[k*2+1], dat[k*2+2]);
        }
    }
    //この関数の必要性はk,lが更新されるから
    int query(int a,int b){ return query(a,b,0,0,n);}
    //
    int query(int a,int b,int k,int l,int r){
        if (r <= a || b <= l) return INF;
        if (a <= l && r <= b) return dat[k];
        else {
            int vl = query(a,b,k*2+1,l,(l+r)/2);
            int vr = query(a,b,k*2+2,(l+r)/2,r);
            return min(vl,vr);
        }
    }
};


int main(){
    int n,q; cin >> n >> q;
    //
    RMQ rmq;
    //
    rmq.init(n);
    //
    while (q--){
        int x,y,z; cin >> x >> y >> z;
        if (x == 0) rmq.update(y,z);
        else cout << rmq.query(y,z+1) << endl;
    }
    return 0;
}