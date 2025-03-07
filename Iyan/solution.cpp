#include <bits/stdc++.h>

using namespace std;
using ll = long long;

map<ll, ll> parent;

ll find_set(ll v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void make_set(ll v) {
    parent[v] = v;
}

void union_sets(ll a, ll b) {
    if (!parent.count(a)) return;
    if (!parent.count(b)) make_set(b);
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (a < b)
            swap(a, b);
        parent[b] = a;
    }
}

int main(){
    ll n, q;
    cin >> n >> q;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (auto x: arr) make_set(x);
    ll a, b, c;
    for (int i = 0; i < q; i++){
        cin >> a;
        if (a == 1){
            cin >> b >> c;
            union_sets(b, b+c);
        }
        else {
            cin >> b;
            cout << find_set(arr[--b]) << endl;
        }
    }

    return 0;
}
