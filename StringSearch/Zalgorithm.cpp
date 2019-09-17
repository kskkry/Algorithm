/*
文字列の各文字iについてSS[i:|S-1|]の
最長共通接頭辞の長さを記録した配列を作るアルゴリズム
計算量 O(N)

参考文献 "https://snuke.hatenablog.com/entry/2014/12/03/214243"
*/

#include <string> 
#include <iostream>
#include <algorithm>
using namespace std;


int R[500010];
int Z_algorithm(int now,const string &s){
    R[0] = s.size();
    int i = 1,j = 0;
    while (i < s.size()){
        while (i+j < s.size() && s[j] == s[i+j]) j++;
        R[i] = j;
        if (j == 0){
            i++;
            continue;
        }
        int k = 1;
        while (i+k < s.size() && k+R[k] < j){
            R[i+k] = R[k];
            k++;
        }
        i += k;
        j -= k;
    }
    return R[now];
}

int main(){
    int N; cin >> N;
    string s; cin >> s;

    int ans = 0;
    for (int i = 0; i < N; i++){
        ans = max(ans, Z_algorithm(i,s));
    }
    //cout << endl;
    cout << ans << endl;
}
