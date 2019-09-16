/*


*/

#include <string> 
#include <iostream>
#include <algorithm>
using namespace std;


int R[500010];
void Zalgorithm(const string &s){
    int c = 0;
    for (int i = 1; i < s.size(); i++){
        if (i + R[i-c] < c + R[c]){
            R[i] = R[i-c];
        } else {
            int j = max(0, c + R[c] - i);
            while (i+j < s.size() && R[j] == R[i+j]){
                j++;
            }
            R[i] = j;
            c = i;
        }
    }
}

int main(){
    int N; cin >> N;
    string s; cin >> s;
    R[0] = s.size();
    Zalgorithm(s);
    int ans = 0;
    for (int i = 1; i <= N; i++){
        cout << R[i];
        ans = max(ans,R[i]);
    }
    cout << endl;
    cout << ans << endl;
}
