#include<iostream>
#include<map>
#include<math.h>
#include<vector>
using namespace std;


//素因数分解
map<long long, long long> PrimeFactor(long long n){
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
class IsPrimeSearch {
    private :
        static const int Maximum = 1e6;
        bool isPrime[Maximum+1];

    public :
        void init(){
            for(int i = 1; i <= Maximum; i++){
                isPrime[i] = true;
            }
        }
        
        //チェック
        bool IsPrimeSetting(int InputNumber){
            if(InputNumber < 2) return false;
            if(InputNumber == 2) return true;
            if(InputNumber % 2 == 0) return false;

            for(int i = 3; i*i <= sqrt(InputNumber); i += 2){
                if(InputNumber % i == 0) return false;
            }
            return true;
        }

        int PrimeCheck(){
            for(int i = 1; i < Maximum; i++){
                if(isPrime[i]){
                    return i;
                }
            }
            return -1;
        }

        void Eratosthenes(){
            isPrime[0] = false;
            isPrime[1] = false;
            for(int i = 2; i <= Maximum; i++){
                if(isPrime[i] == 1){
                    for(int j = 2*i; j <= Maximum; j += i){
                        isPrime[j] = false;
                    }
                }
            }
        }
        bool IsPrimeNumber(int InputNumber){
            if (isPrime[InputNumber]){
                return true;
            } else {
                return false;
            }
        }
};

int main(){
    //確認サンプルコードhttps://atcoder.jp/contests/abc149/tasks/abc149_c
    IsPrimeSearch isp = IsPrimeSearch();
    isp.init();
    isp.Eratosthenes();
    int N; cin >> N;
    while (true){
        if (isp.IsPrimeNumber(N)){
            cout << N << endl;
            break;
        }
        N++;
    }
}

