/*
MP(Morris-Pratt) に比べ文字列検索の効率が向上したもの
文字列の各文字について文字列の接頭辞と接尾辞が
最大何文字一致するかを記録する配列をつくるアルゴリズム
参考文献 "https://snuke.hatenablog.com/entry/2014/12/01/235807"

計算量 O(N)
*/

#include <string> 
#include <iostream>
#include <algorithm>
using namespace std;

int R[500050];

//接尾辞は自身の文字からカウントすることに注意
void MP(const string &s){
    R[0] = -1;
    int j = -1;
    for (int i = 0; i < s.size(); i++){
        while (j >= 0 && s[i] != s[j]){
            j = R[j];
        }
        j++;
        R[i+1] = j;
    }
}



int main(){
    string s; cin >> s;
    MP(s);
    for (int i = 0; i < s.size()+1; i++){
        if (R[i] == -1) cout << '_';
        else cout << R[i];
    }
    cout << endl;
}

/*
input  : aabaabaaa
output : _010123452
*/