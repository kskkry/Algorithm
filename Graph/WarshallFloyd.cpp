//そのまま使えます(多分)
#include<iostream>
#include<algorithm>
#define MM 1e9+7; // とても大きい数
using namespace std;

int N; // Nは頂点数

long long dist[100][100]; //各点ごとの距離、便宜的に N = 100としてみた
const long long INF = 1e15;
//初期化のための関数
void init(){  
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
          dist[i][j] = MM;
        }
    }
}

void Warshall_Floyd(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < N; k++){
                if(dist[i][j] == INF || dist[j][k] == INF) continue;
                
                /*
                indexが等しいときは無視できる
                もしくは距離0に更新
                dist[i][k] = 0;
                */
           
                
                dist[i][k] = min(dist[i][k], dist[i][j]+dist[j][k]);
                /*
                距離が最小になるように更新
                */
            }
        }
    }
}
/* ワ―シャルフロイド法を使う際の個人的な注意点
   他のグラフアルゴリズムに比べ実装が簡単（個人の感想）なので使える問題のときは非常に便利 
   ただ頂点数をNとすると、計算量がN^3になる。そのためNが1000の時ですら競プロに使うことが難しい。
   計算量が多くなる時は、ダイクストラ法やベルマンフォード法、DFSなどの計算量が減らせるアルゴリズムを
   用いるとよい。
   そちらのアルゴリズムの方が応用が効きやすい（？）のでそっちを理解する方がよい。
*/


int main(){
    //以下入力
    cin >> N; // 頂点数の入力
    
    int num; // 辺の数を設定
    
    for(int i = 0; i < num; i++){
        int length, vertex1, vertex2; //vertexは入力された頂点番号, lengthは頂点間距離
        // cin >> >> >> >> ; //lenght, vertex1, vertex2の入力
        dist[vertex1][vertex2] = length;
        dist[vertex2][vertex1] = length;
    }
    //計算
    Warshall_Floyd();
    
    int start_point,end_point;　//start_point,end_pointはそれぞれ始点、終点を表す。
    // cin >> >> ; // 入力  
    
    //cout << dist[start_point][end_point] << endl;
    return 0;
}
