#include <iostream>
#include <bitset>
using namespace std;


int main(){
    int q; cin >> q;
    //64bitのBit(全て0)を定義
    bitset<64> Bit(0);
    for(int i = 0; i < q; i++){
        int n; cin >> n;
        if (n == 0){
            int m; cin >> m;
            //m番目を出力
            cout << Bit[m] << endl;
        } else if (n == 1){
            int m; cin >> m;

            //m番目の値を1に変更
            Bit[m] = 1;

        } else if (n == 2){
            int m; cin >> m;

            //m番目の値を0に変更
            Bit[m] = 0;

        } else if (n == 3){
            int m; cin >> m;

            //m番目の値を反転(XORで簡単にできる)
            Bit[m] = Bit[m]^1;

        } else if (n == 4){

            //全てのフラグが1ならば1,0ならば0を出力する
            cout << Bit.all() << endl;

        } else if (n == 5){

            //いずれかのフラグが1ならば1,全て0ならば0を出力する
            cout << Bit.any() << endl;

        } else if (n == 6){

            //全てのフラグが0ならば1,そうでないならば0を出力する
            cout << Bit.none() << endl;

        } else if (n == 7){

            //ON(1)になっているフラグの数を出力する
            cout << Bit.count() << endl;

        } else {

            //状態の整数値(10進数)を出力する
            cout << Bit.to_ulong() << endl;

        }
    }
}