#include<bits/stdc++.h>
using namespace std;


//素因数分解
map<long long, long long> prime_factor(long long n){
    map<long long,long long> mp;
    for(long long i = 2; i*i <= n; i++){
        while(n % i == 0){
            mp[i]++;
            n /= i;
        }
    }
    if (n != 1) mp[n]++;
    return mp;
}

//basic
const int N = 1e5;
bool isprime(int N){
    if(N < 2) return false;
    if(N == 2) return true;
    if(N % 2 == 0) return false;

    for(int i = 3; i*i <= sqrt(N); i += 2){
        if(N % i == 0) return false;
    }
    return true;
}

//Sieve of Eratosthenes

bool isPrime[N+1];
void init(){
    for(int i = 1; i <= N; i++){
        isPrime[i] = true;
    }
}
int Prime_check(){
    for(int i = 1; i < N; i++){
        if(isPrime[i]){
            return i;
        }
    }
    return -1;
}

bool Eratosthenes(int N){
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i = 2; i <= N; i++){
        if(isPrime[i] == 1){
            for(int j = 2*i; j <= N; j += i){
              isPrime[j] = false;
            }
        }
    }
}

