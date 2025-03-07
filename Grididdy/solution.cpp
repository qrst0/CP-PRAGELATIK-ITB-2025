#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    int N, first;
    cin >> N >> first;
    vector<string> grid(N);
    for (int i = 0; i < N; i++) cin >> grid[i];
    if (N == 1){
        if (grid[0][0] == '0') cout << "MIRIS" << endl;
        else cout << "CIRAN" << endl;
    }
    else {
        if (first) cout << "MIRIS" << endl;
        else cout << "CIRAN" << endl; 
    }
    return 0;
}
