#include<bits/stdc++.h>  
using namespace std;  

int gcd(int a,int b){
    if(b == 0) return a;
    return gcd(b,a%b);
}

int lcm(int a,int b){
    int g = gcd(a,b);
    return a*b/g;
}

/*  
    文字の大小に注意
    計算量が多い場合再起関数でなく繰り返し処理の方に適宣変えるべき　
*/
