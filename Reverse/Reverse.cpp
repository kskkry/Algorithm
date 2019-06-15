#include<bits/stdc++.h>
using namespace std;
const int MM = 1e9;
const int MOD = MM+7;
long long fac[100010],finv[100010],inv[100010];

const int MAX = 100000;
void init(){
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for(int i = 2; i < MAX; i++){
        fac[i] = fac[i-1]*i%MOD;
        inv[i] = MOD - inv[MOD%i]*(MOD/i)%MOD;
        finv[i] = finv[i-1]*inv[i]%MOD;
    }
}

long long COM(int n,int k){
    if(n < k || n < 0 || k < 0) return 0;
    return fac[n]*(finv[k]*finv[n-k]%MOD)%MOD;
}
int main(){
    init();
    cout << COM(100,5) << endl;
    cout << COM(10000,2020) << endl;
}