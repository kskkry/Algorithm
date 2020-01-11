#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/* 

レーベンシュタイン距離(編集距離)
編集距離とは操作によって一つの文字列を別の文字列に
変形するのに必要な最小手順を表す

・挿入　文字列に別の文字を挿入
・削除　文字列から一つの文字を削除する
・置換　文字列の中の一文字を別の文字に置き換える

*/


int LevenshteinDistance(string s1,string s2) {
  int n = (int)s1.size(), m = (int)s2.size();
  vector<vector<int> > dp(n+1,vector<int>(m+1));
  for(int i=0;i<=n;++i) dp[i][0] = i;
  for(int i=0;i<=m;++i) dp[0][i] = i;
  for(int i=1;i<=n;++i) {
    for(int j=1;j<=m;++j) {
      dp[i][j] = min(dp[i-1][j]+1,
                     min(dp[i][j-1]+1,dp[i-1][j-1]+(s1[i-1]!=s2[j-1])));
    }
  }
  return dp[n][m];
}

int main(){
    string s1,s2; cin >> s1 >> s2;
    cout << LevenshteinDistance(s1,s2) << endl;
    return 0;
}
