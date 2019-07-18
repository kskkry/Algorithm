#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long MOD = 1e9+7;


//約数列挙 √N
vector<long long> divisor(long long x){
    vector<long long> res;
    for(long long i = 1; i*i <= x; i++){
        if (x % i == 0){
            res.push_back(i);
            if (i*i != x) res.push_back(x/i);
        }
    }
    sort(res.begin(),res.end());
    return res;
}


//因数分解 √N
vector<int> prime_decomposition(long long x){
    vector<int> res;
    for(int i = 2; i*i <= x; i++){
        while(x % i == 0){
            x /= i;
            res.push_back(i);
        }
    }
    if (x != 1) res.push_back(x);
    return res;
}