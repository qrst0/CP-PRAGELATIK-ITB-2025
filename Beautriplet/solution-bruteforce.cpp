#include <bits/stdc++.h>

using namespace std;
using ll = long long;


int main(){
    int n;
    cin >> n;
    vector<int> arr(2*n);
    for (int i = 0; i < 2*n; i++) cin >> arr[i];

    vector<int> idx(n+1, -1);
    ll ans = 0;

    for (int i = 0; i < 2*n; i++){
        if (idx[arr[i]] == -1){
            idx[arr[i]] = i;
            continue;
        }   
        vector<bool> visited(n+1);
        for (int j = idx[arr[i]]+1; j < i; j++){
            if (visited[arr[j]]) continue;
            ans += arr[j] + arr[i]*2;
            visited[arr[j]] = 1;
        }
    }

    cout << ans << endl;
    return 0;
}
