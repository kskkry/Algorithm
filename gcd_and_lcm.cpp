#define long long ll

ll gcd(ll a,ll b){
    if(b == 0) return a;
    return gcd(b,a%b);
}

ll lcm(ll a,ll b){
    ll g = gcd(a,b);
    return a*b/g;
}

/*  
    文字の大小に注意

    計算量が多い場合再起関数でなく繰り返し処理の方に適宣変えるべき　
*/
