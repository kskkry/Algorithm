#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class WeightUnionFind {
    public :
        int N;
        vector<int> par, rank, cnt;

        void init(int N){
            par.resize(N);
            rank.resize(N);
            cnt.resize(N);
        }   
};