#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <stack>
#include <numeric>
#include <algorithm>
#include <tuple>
#include <stdio.h>
#include <bitset>
#include <limits.h>
#include <complex>
#include <deque>
#include <iomanip>
#include <list>
using namespace std;
#define pi pair<int32,int32>
#define pl pair<int64,int64>
#define chmax(a,b) (a<b ? a=b:0)
#define chmin(a,b) (a>b ? a=b:0)
#define en cout << endl //セミコロンつけろ
//#define MM 1000000000
//#define MOD MM+7
const int MM = 1e9;
const int MOD = MM+7;
const long double PI = acos(-1);
const long long INF = 1e15;
int dx[8] = {-1,0,1,0,-1,-1,1,1};
int dy[8] = {0,-1,0,1,-1,1,1,-1};
// 'A' = 65, 'Z' = 90, 'a' = 97, 'z' = 122
template<typename T>
T GCD(T u,T v){
    return v ? GCD(v,u%v) : u;
}
template<typename T>
T LCM(T x,T y){
    T gc = GCD(x,y);
    return x*y/gc;
}


int main(){
    int N; cin >> N;
    vector<string> s(0);

    
    map<string,long long> mp;
    for(int i = 0; i < N; i++){
        string t; cin >> t;
        sort(t.begin(),t.end());
        s.push_back(t);
    }
    long long ans = 0;
    sort(s.begin(),s.end());
    for(int i = 1; i < N; i++){
        if (s[i-1] == s[i]) mp[s[i]]++;
    }
    for(int i = 1; i < N; i++){
        if (mp[s[i]] > 0){
            //cout << "mp[s[i] = " << mp[s[i]] << s[i] << endl;
            ans += mp[s[i]]*(mp[s[i]]+1)/2;
            mp[s[i]] = 0;
        }
    }

    cout << ans << endl;
}