#include<iostream>
using namespace std;

//basic
bool isPrime(int N){
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

isPrime[0] = false;
isPrime[1] = false;

bool Eratosthenes(int N){
    for(int i = 2; i < N; i++){
        if(isPrime[i] == 1){
            for(int j = 2*i; j < N; j += i){
              isPrime[j] = false;
            }
        }
    }
}

