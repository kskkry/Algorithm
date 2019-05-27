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
    時にはlong long などへの必要
    計算量が多い場合再起関数でなくmain関数内での繰り返し処理の方に適宣変えるべき　
*/

/*shorter gcd*/
int GCD(int x,int y){
    return y ? GCD(y,x%y):x;
}

