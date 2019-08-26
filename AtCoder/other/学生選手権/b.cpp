#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const long long MM = 1e9;
const long long MOD = MM+7;

int main(){
    int N; long long K; cin >> N >> K;
    vector<int> a(N);
    for (int i = 0; i < N; i++){
        cin >> a[i];
    }

    long long a1 = 0,a2 = 0,sum = 0;
    for (int i = 0; i < N; i++){
        a1 = 0,a2 = 0;
        for (int j = 0; j < N; j++){
            if (i == j) continue;
            if (a[i] > a[j] && j < i){
                a1++;
            } else if (a[i] > a[j] && i < j){
                a2++;
            }
        }
        //cout << a1 << " " << a2 << endl;
        sum += ((a1 + a2)*((K*(K-1)/2)%MOD) + a2*K);
        sum %= MOD;
    }
    cout << sum << endl;
}