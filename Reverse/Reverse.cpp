#include<iostream>
using namespace std;
const int MM = 1e9;
const int MOD = MM+7;


//ここから
const int COM_MAX = 500500;
long long fac[COM_MAX],finv[COM_MAX],inv[COM_MAX];
void init(){
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for(int i = 2; i < COM_MAX; i++){
        fac[i] = fac[i-1]*i%MOD;
        inv[i] = MOD - inv[MOD%i]*(MOD/i)%MOD;
        finv[i] = finv[i-1]*inv[i]%MOD;
    }
}
long long COM(int n,int k){
    if(n < k || n < 0 || k < 0) return 0;
    return fac[n]*(finv[k]*finv[n-k]%MOD)%MOD;
}
//ここまで



int main(){
    init();
    cout << COM(10,2) << endl;       //45
    cout << COM(100,5) << endl;      //75287520
    cout << COM(10000,2020) << endl; //762700078
}
