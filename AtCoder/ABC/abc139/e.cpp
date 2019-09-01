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
#include <cstring>
using namespace std;
typedef long long ll;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; scanf("%d", &N);
    int a[1000][999];
    bool graph[1000][999];
    memset(graph,false,sizeof(graph));
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N-1; j++){
            scanf("%d", &a[i][j]);
            a[i][j]--;
        }
    }
    int in[1000]; fill(in,in+1000,0);

    int day = 0;
    int time = 0;
    while (true){
        bool game = false; //試合を行ったか
        bool flg = true;
        day++;
        bool used[1000]; fill(used,used+1000,false);
        for (int i = 0; i < N; i++){
            int dest = a[i][in[i]];
            if (in[i] >= N-1) continue;
            if (graph[i][dest] == true || graph[dest][i] == true){
                //cout << "i : " << i << ", day = " << day << ", ";
                //cout << "dest = " << dest << endl;
                cout << -1 << endl;
                return 0;
            }
            if (used[i] || used[dest]) continue;
            //graph[i][a[i][in[i]]] = true;
            //graph[a[i][in[i]]][i] = true;
            
             //目的地の目的地
            int dest_of_dest = a[dest][in[dest]];
            if (in[dest] >= N-1) continue;
            if (dest_of_dest == i && used[i] == false && used[dest] == false){
                //cout << "day = " << day << ", i = " << i << ", dest = " << dest << endl;
                //cout << "";
                used[i] = true;
                used[dest] = true;
                graph[i][dest] = true;
                graph[dest][i] = true;
                
                in[dest]++;
                in[i]++;
                game = true;
            }
        }
        if (flg) break;
        if (day >= 499500){
            cout << -1 << endl;
            return 0;
        }
        if (!game){
            cout << -1 << endl;
            return 0;
        }
    }
    printf("%d", day);
}