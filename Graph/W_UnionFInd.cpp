#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class WeightUnionFind {
    public :
        vector<int> par, rank, cnt;

        void Init(int N){
            par.resize(N);
            rank.resize(N);
            cnt.resize(N);
        }   
};