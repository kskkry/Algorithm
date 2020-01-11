#include <iostream>
using namespace std;

// a^n mod を計算する
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

// a^{-1} mod を計算する
long long modinv(long long a, long long mod) {
    return modpow(a, mod - 2, mod);
}

int main() {
    // mod. 13 での逆元を求めてみる
    for (int i = 1; i < 13; ++i) {
        cout << i << " 's inv: " << modinv(i, 13) << endl;
    }
}