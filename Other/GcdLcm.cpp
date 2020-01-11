template<typename T>
T GCD(T u,T v){
    return v ? GCD(v,u%v) : u;
}
template<typename T>
T lcm(T x,T y){
    return x*y/GCD(x,y);
}

int gcd(int a,int b){
    if(b == 0) return a;
    return gcd(b,a%b);
}

int lcm(int a,int b){
    int g = gcd(a,b);
    return a*b/g;
}

/*short gcd*/
int GCD(int x,int y){
    return y ? GCD(y,x%y):x;
}

#include <iostream>
//#include "set_name.h"
int main(){
    //std::cout << TR << std::endl;
}
