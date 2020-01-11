#include <bits/stdc++.h>
/* 

Minkowski's distance (ミンコフスキー距離)は以下のように表される
D_{xy} = { \sum_{i-1}^{n} |x_i - y_i|^{p} }^{1/p}

*/

/*

a^{小数}も同様にpow()関数で使える

p=1のときマンハッタン距離
p=2のときユークリッド距離
p=∞のときチェビチェフ距離
を表す
*/

//問題http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_10_D&lang=jp

using namespace std;
int n;
double x[100],y[100];
double Distance(double p){
    double ans = 0;
    for(int i = 0; i < n; i++){
        double w = abs(x[i]-y[i]);
        ans += pow(w,p);
    }
    return pow(ans, 1.0/p);
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x[i];
    }
    for(int i = 0; i < n; i++){
        cin >> y[i];
    }
    cout << fixed << setprecision(10);
    cout << Distance(1) << endl;
    cout << Distance(2) << endl;
    cout << Distance(3) << endl;

    double mx = 0;
    for(int i = 0; i < n; i++){
        mx = max(abs(x[i]-y[i]), mx);
    }
    cout << mx << endl;
}