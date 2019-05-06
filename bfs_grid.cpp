#include<bits/stdc++.h>
using namespace std;
#define MM 1e9
#define Pair pair<int,int>

int H,W;
char a[1001][1001];
int dist[1001][1001];
queue<Pair> que;

void init(){
	for(int i = 0; i < H; i++){
		for(int j = 0; j < W; j++){
			dist[i][j] = MM; // initialize
		}
	}
}

void bfs(){
	while(que.size()){
		Pair p = que.front();
		que.pop();
		int h = p.first;
		int w = p.second;
		if(h+1 < H && dist[h+1][w] == MM){
			dist[h+1][w] = dist[h][w]+1;
			que.push(Pair(h+1,w));
		}
		if(w+1 < W && dist[h][w+1] == MM){
			dist[h][w+1] = dist[h][w]+1;
			que.push(Pair(h,w+1));
		}
		if(h >= 1 && dist[h-1][w] == MM){
			dist[h-1][w] = dist[h][w]+1;
			que.push(Pair(h-1,w));
		}
		if(w >= 1 && dist[h][w-1] == MM){
			dist[h][w-1] = dist[h][w]+1;
			que.push(Pair(h,w-1));
		}
	}
}

void input(){
	cin >> H >> W; 
	init();
	for(int i = 0; i < H; i++){
		for(int j = 0; j < W; j++){
			cin >> a[i][j];
			if(a[i][j] == '#'){
				dist[i][j] = 0;
				que.push(Pair(i,j));
			}
		}
	}
}

void check(){
	int mx = 0;
	for(int i = 0; i < H; i++){
		for(int j = 0; j < W; j++){
			mx = max(mx,dist[i][j]);
		}
	}

    /*for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cout << dist[i][j] << " ";
        }
        cout << endl;
    } */

	cout << mx << endl;
}

int main(){
	input();
	bfs();
	check();
}
