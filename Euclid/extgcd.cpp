// 拡張ユークリッド
// ax + by = gcd(a,b) これを満たす(x, y)が格納される
//

int ext_gcd(int a,int b,int &x,int &y){
    int d = a;
    if (b == 0){
        x = 1; y = 0;
    } else {
        d = ext_gcd(b, a%b, y, x);
        y -= (a/b)*x;
    }
    return d;
}

//cout << ext_gcd(a,b,x,y) << endl;

/* void型として扱ってもよい
int main() {
    long long a, b; cin >> a >> b;
    long long x, y;
    //ここ！
    extGCD(a, b, x, y);
    cout << x << " " << y << endl;
}
*/