#include<bits/stdc++.h>
using namespace std;


int ans = 0;
int num = 0; //処理回数

//たとえば返り値がないとき
void dfs(int count, int x){
    if(count == num){
        break;
    }
    //処理（xの更新など）
    dfs(count++,x);
}


int main(){
    cin >> ; // 入力
    // 処理
    cout << ans << endl; // 出力
}
