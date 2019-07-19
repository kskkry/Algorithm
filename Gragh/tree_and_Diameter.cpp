#include <vector>
using namespace std;

//木の直径
const int max_edge = 2;
vector<int> G[max_edge]; //頂点情報のみのグラフ

//treeDFS(親,現在地,根から現在地までの距離,根からの最大距離,根から最大の距離をとる頂点)
void treeDFS(int from,int current,int dist,int &maxDist,int &maxVertex){
    //距離と終点の更新
    if (dist > maxDist){
        maxDist = dist;
        maxVertex = current;
    }
    for (auto to : G[current]){
        //逆流を防ぐ
        if (to == from) continue;
        treeDFS(current,to,dist+1,maxDist,maxVertex);
    }
}

//直径を求める
int TreeDiameter(){
    int start = 0, end = 0,maxDist = 0;
    treeDFS(-1,start,0,maxDist,end);
    start = end,end = 0,maxDist = 0;
    treeDFS(-1,start,0,maxDist,end);
    return start;
}