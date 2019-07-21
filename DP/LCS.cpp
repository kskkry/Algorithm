#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 10010;
const int MAX_M = 10010;
int n,m; string s,t;



//LCS
int dp[MAX_N+1][MAX_M+1];
void LCS1(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if (s[i] == t[j]){
                dp[i+1][j+1] = dp[i][j] + 1;
            } else {
                dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
            }
        }
    }
    //cout << dp[n][m] << endl;
}

//LCS2
int lcs[MAX_N][MAX_M];
char dir[MAX_N][MAX_M];
string s1,s2;
void LCS2(){
    memset(dir,'A',sizeof(dir));
    n=0;
    for(int i=0;i<=s2.size();i++)
    {
        for(int j=0;j<=s1.size();j++)
        {
            if(i==0 || j==0)
                lcs[i][j]=0;
            else if(s1[j-1]==s2[i-1])
            {
                lcs[i][j]=lcs[i-1][j-1]+1;
                dir[i][j]='C';
                n=max(n,lcs[i][j]);
            }
            else
            {
                if(lcs[i-1][j]>lcs[i][j-1])
                {
                    lcs[i][j]=lcs[i-1][j];
                    dir[i][j]='U';
                }
                else if(lcs[i-1][j]<lcs[i][j-1])
                {
                    lcs[i][j]=lcs[i][j-1];
                    dir[i][j]='L';
                }
                else
                {
                    lcs[i][j]=lcs[i-1][j];
                    dir[i][j]='U';
                }
            }
        }
    }
}


