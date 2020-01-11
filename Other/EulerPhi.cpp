
//オイラー関数 √N
int Euler_phi(int n){
    int ret = n; 
    for(int i = 2; i*i <= n; i++){
        if (n%i == 0){
            ret -= ret/i;
            while(n % i == 0) n /= i;
        }
    }
    if (n != 1) ret -= ret/n;
    return ret;
}