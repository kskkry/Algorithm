//yet

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