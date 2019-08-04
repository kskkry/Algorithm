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
    string s; cin >> s;
    int n = s.size();
    int a[n];
    fill(a,a+n,0);
    int num = 1;
    vector<int> v;
    vector<int> R,L;
    int r = 1, l = 0;
    for(int i = 1; i < n; i++){
        if (s[i-1] == 'R' && s[i] == 'R'){
            r++;
        } else if (s[i-1] == 'R' && s[i] == 'L'){
            R.push_back(r);
            l = 1;
            r = 0;
        } else if (s[i-1] == 'L' && s[i] == 'R'){
            L.push_back(l);
            r = 1;
        } else {
            l++;
        }
    }
    L.push_back(l);
    int index = 0;
    for(int i = 0; i < n-1; i++){
        if (s[i] == 'R' && s[i+1] == 'L'){
            a[i] = R[index];
            a[i+1] = L[index]; 
            index++;
        }
    }
    



    for(int i = 0; i < n; i++){
        if (a[i] > 0){
            if ((a[i]+a[i+1]) % 2 == 0){
                a[i] = (a[i]+a[i+1])/2;
                a[i+1] = a[i];
            } else if (a[i] % 2 == 1){
                int tmp = (a[i]+a[i+1]);
                a[i] = tmp/2 + 1;
                a[i+1] = tmp/2;
            } else {
                int tmp = (a[i]+a[i+1]);
                a[i] = tmp/2;
                a[i+1] = tmp/2 + 1;
            }
            i++;
        }
    }
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}