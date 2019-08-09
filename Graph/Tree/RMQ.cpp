#include <iostream>
#include <algorithm>

using namespace std;

const int SIZE = (1 << 15) - 1, MAX_N = (1 << 17), MAX_C = 1e5;
const int MM = 1e9, MOD = MM+7;
int n,c; 
int dat[2*MAX_N - 1];


//アリ本からの引用
void init(int N){
    n = 1;
    //要素数の作成、なお2のべき乗(easy)
    while (n < N){
        n *= 2;
    }
    for(int i = 0; i < 2*n - 1; i++){
        dat[i] = MM;
    }
}

void update(int k,int a){
    //節点
    k += n-1;
    dat[k] = a;
    
    //更新
    while (k > 0){
        k = (k-1) / 2;
        dat[k] = min(dat[k*2 + 1], dat[k*2 + 2]);
    }
}

/* 
区間[a,b}の最小値を求める
後ろの引数は計算を簡単にするための引数
kの節点の番号、l,rはその節点が[l,r)に対応する
外からはquery(a,b,0,0,n)として呼ぶ
*/
int query(int a,int b,int k,int l,int r){
    //[a,b)と[l,r)が交わるならばMMを返す
    if (r <= a || b <= l) return MM;

    //[a,b)が[l,r)を完全に含むならばこのときの節点の値
    if (a <= l && r <= b) return dat[k];
    else {
        //そうでないならば二つの次の根の最小値(範囲を絞る)
        int vl = query(a,b,k*2 + 1, l, (l+r)/2);
        int vr = query(a,b,k*2 + 2,(l+r)/2, r);
        return min(vl,vr);
    }
}
