#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//最長増加部分列(Longest Increase Subsequence)の長さ
const int INF = 1e9;
int LIS(int n,vector<int> a){
    //dp的思考
    vector<int> dp(n+1,INF);
    for(int i = 0; i < n; i++){
        *lower_bound(dp.begin(),dp.end(),a[i]) = a[i];
    }
    return lower_bound(dp.begin(),dp.end(),INF) - dp.begin();
}

//cout << LIS(n,a) << endl;