#include <iostream>
#include <bitset>
using namespace std;
int main(){
    long long a,b; cin >> a >> b;
    cout << bitset<32>(a&b) << endl; //00000000000000000000000000001000
    cout << bitset<32>(a|b) << endl; //00000000000000000000000000001010
    cout << bitset<32>(a^b) << endl; //00000000000000000000000000000010
}

//二進数変換(配列に格納)
void ToBinary(long long A){
    int binary[32]; fill(binary,binary+32,0); //32ビット
    long long tmp = A;
    for(int i = 0; A > 0; i++){
        binary[i] = A%2;
        A /= 2;
    }
    
    //確かめ
    for(int i = 0; i < 32; i++){
        cout << binary[32-i-1];
    }
    cout << endl;
}