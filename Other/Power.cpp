#define MM 1e9
#define MOD MM+7





//べき乗関数 √x
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

//引用（ほぼ同じ）
long long pow_mod(long long n,long long k,long long m){
    if (k == 0){
        return 1;
    } else if (k % 2 == 1){
        return pow_mod(n,k-1,m)*n % m;
    } else {
        long long t = pow_mod(n,k/2,m);
        return t*t % m;
    }
}

//進数表現(写経)
long long POW_MOD(long long n,long long k,long long m){
    long long r = 1;
    //kの下の桁から処理、右シフトで処理し終えたら桁を追い出す
    //ゼロになるまで続ける
    for (; k > 0; k >>= 1){
        if (k & 1) r = (r*n)%m; //kの一番下の桁が立っていたらnをかける
        n = (n*n) % m;          //次のM桁の処理に向けてnを自乗しておく
    }
    return r;
}
