#include <iostream>
#include <bitset>
using namespace std;
int main(){
    long long a,b; cin >> a >> b;
    cout << bitset<32>(a&b) << endl; //00000000000000000000000000001000
    cout << bitset<32>(a|b) << endl; //00000000000000000000000000001010
    cout << bitset<32>(a^b) << endl; //00000000000000000000000000000010
}