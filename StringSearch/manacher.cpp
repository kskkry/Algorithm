/*
文字列が与えられたとき、各文字 i を
中心とする最長の回文の半径を記録した
配列Rを記録するアルゴリズム

文字列のうちの一文字についての計算量 O(N)
各々の文字列について計算 O(N^2)
*/

#include <string> 
#include <iostream>
#include <algorithm>
using namespace std;

int R[100010];
int manacher(int now,string &s){
    int i = 0,j = 0;
    while (i < s.size()){
        while (i-j >= 0 && i+j < s.size() && s[i-j] == s[i+j]){
            j++;
        }
        R[i] = j;
        int k = 1;
        while (i-k >= 0 && i+k < s.size() && k+R[i-k] < j){
            R[i+k] = R[i-k];
            k++;
        }
        i += k;
        j -= k;
    }
    return R[now];
}


//sample 
int main(){
    int N; cin >> N;
    string s; cin >> s;
    //各々の文字列について考えるのでO(N*N)
    for (int i = 0; i < s.size(); i++){
        cout << manacher(i,s);
    }
}

/*
 txt.in  abaaababa
 txt.out 121412321
*/