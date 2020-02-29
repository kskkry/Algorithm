#include<iostream>
#include<algorithm>
#define MM 1e9+7; 
using namespace std;

int N; 

long long dist[100][100];
const long long INF = 1e15;
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
                dist[i][k] = min(dist[i][k], dist[i][j]+dist[j][k]);
            }
        }
    }
}


int main(){
    cin >> N;
    int num;
    for(int i = 0; i < num; i++){
        int length, vertex1, vertex2;
        dist[vertex1][vertex2] = length;
        dist[vertex2][vertex1] = length;
    }
    Warshall_Floyd();
    int start_point,end_point;
    return 0;
}
