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




int main(){

    //input
    int M,I,P,R,BL; cin >> M >> I >> P >> R >> BL;
    //M:設備数,I:品目数,P:最大工程数,R:オーダ数,BL:BOM行数

    int C[M]; //設備mの能力増加コスト(yen)
    for(int i = 0; i < M; i++){
        cin >> C[i];
    }

    int D[M]; //設備mの製造時間係数
    for(int i = 0; i < M; i++){
        cin >> D[i];
    }

    //BOM入力
    for(int i = 0; i < BL; i++){
        int i_num,p_num,m_num,s_num; cin >> i_num >> p_num >> m_num >> s_num;
        //i_num:品目番号,p_num:工程番号,m_num:設備番号,
        //s_num:製造スピード(設備の能力値が1のときの一個当たりの製造時間)
    }

    //Order入力
    for(int i = 0; i < R; i++){
        int r_num,i_num,e_num,d_num,q_num,pr_num;
        cin >> r_num >> i_num >> e_num >> d_num >> q_num >> pr_num;
        //r_num:オーダ番号,i_num:品目番号,e_num:最早開始日,d_num:納期日,
        //q_num:製造数量,pr_num:オーダの粗利金額
        //
    }
}