#define MM 1e9
#define MOD MM+7





//べき乗関数
long long Pow(long long base,long long x){
    //マクロ定義のままMODを使ったらエラーを起こした（多分long long の定義の問題かと）
    const long long mod = (long long)MOD;
    if (x == 0) return 1;
    //指数が奇数の時、x^(2n+1) -> x * x^(2n)と変換
    if (x%2 == 1) return base * Pow(base,x-1) % mod;
    //指数が偶数なら x^(2n) -> x^(2n) * x^(2n)と変換
    long long y = Pow(base, x/2);
    return y * y % mod;
}

//m^(n) cout << Pow(m,n) << endl;