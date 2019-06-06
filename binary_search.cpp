#include<bits/stdc++.h>
using namespace std;
#define MM 1e9

template<typename T>
T binary_search(T key,T N,T L,T R){
	L = 0;
	R = N;
	while(L < R){
		mid = (L+R)/2;
		if(a[mid] == key) return mid;
		else if(key < a[mid]) R = mid;
		else L = mid+1; //注意
	}
	return -1;
}


//以下は例
int L,R,mid;
//要素数Nの場合を考える
//例 N = 10
int a[10] = {1,2,4,6,7,9,11,14,17,19};
int binary_search(int key,int N){
	L = 0;
	R = N;
	while(L < R){
		mid = (L+R)/2;
		if(a[mid] == key) return mid;
		else if(key < a[mid]) R = mid;
		else L = mid+1; //注意
	}
	return -1;
}

int main(){
	cout << binary_search(6,10) << endl;//3
	cout << binary_search(17,10) << endl;//8
	cout << binary_search(99,10) << endl;//-1
}
