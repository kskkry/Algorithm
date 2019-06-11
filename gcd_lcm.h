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
