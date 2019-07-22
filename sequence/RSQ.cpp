#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 200020;
const int INF = (1LL << 31) - 1;


//Range Sum Query
//Segment treeで代替可能
struct BIT {
    int N;
    vector<int> dat;
    void init(int _N){
        N = _N;
        dat = vector<int>(N+1,0);
    }
    void add(int k,int val){
        k++;
        while (k <= N){
            dat[k] += val;
            k += k&-k;
        }
    }
    int getsum(int k){
        k++;
        int ret = 0;
        while (k){
            ret += dat[k];
            k -= k&-k;
        }
        return ret;
    }
};

/* 
//Range Sum Query
class BIT{
    public:
    //[1,i]
    int n;
    vi bit;
    // int bit[MAZ_N+1];
    BIT(int size){
        n=size;
        bit=vi(n+1);
    }
    int query(int i){//sum
        int s=0;
        while(i>0){
            s+=bit[i];
            i-=i&-i;
        }
        return s;
    }
    void add(int i,int x){
        while(i<=n){
            bit[i]+=x;
            i+=i&-i;
        }
    }
};
*/



int main(){
    int n,q; cin >> n >> q;
    BIT bit;
    bit.init(n);
    for(int i = 0; i < q; i++){
        int t,x,y; cin >> t >> x >> y;
        if (t == 1){
            cout << bit.getsum(y-1) - bit.getsum(x-2) << endl;;
        } else {
            bit.add(x-1,y);
        }
    }
    return 0;
}
