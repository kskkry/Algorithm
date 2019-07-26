#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//最長増加部分列(Longest Increase Subsequence)の長さ
const int MM = 1e9+7;

//
int LIS(int n,vector<int> a){
    //dp
    vector<int> dp(n+1,MM);

    //dp[i]はi個の増加部分列が作れるときに
    //その部分列の末尾の項の最小値を表す
    
    for(int i = 0; i < n; i++){
        *lower_bound(dp.begin(),dp.end(),a[i]) = a[i];
    }
    return lower_bound(dp.begin(),dp.end(),MM) - dp.begin();
}

//可読性大
int lis(vector<int> a){
    int n = a.size();
    int length = 1;
    vector<int> out(n+1,MM);
    out[0] = -1;
    for(int i = 0; i < n; i++){
        for(int j = length; j >= 0; j--){
            if (out[j] < a[i]){
                out[j+1] = a[i];
                length = max(length,j+1);
                break;
            }
        }
    }
    return length;
}