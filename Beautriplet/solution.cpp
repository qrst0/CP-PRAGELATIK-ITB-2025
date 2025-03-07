#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// sum segtree
struct Tree{
    typedef ll T;
    static constexpr T unit = 0;
    T f(T a, T b) { return a + b; }
    vector<T> s; int n;
    Tree(int n = 0, T def = unit): s(2*n, def), n(n){}
    void update (int pos, T val){
        for(s[pos += n] = val; pos /=2;)
        s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
    }
    T query(int b, int e){ // query [b, e)
        T ra = unit, rb = unit;
        for(b += n, e += n; b < e; b /= 2, e /= 2){
            if (b%2) ra = f(ra, s[b++]);
            if (e%2) rb = f(s[--e], rb);
        }
        return f(ra,rb);
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> arr(2*n);
    for (int i = 0; i < 2*n; i++) cin >> arr[i];

    vector<int> idx(n+1, -1);
    Tree tsum(2*n), tdistinct(2*n);
    ll ans = 0;

    for (int i = 0; i < 2*n; i++){
        tsum.update(i, arr[i]);
        tdistinct.update(i, 1);
        if (idx[arr[i]] == -1){
            idx[arr[i]] = i;
            continue;
        }   
        tsum.update(idx[arr[i]], 0);
        tdistinct.update(idx[arr[i]], 0);

        ans += tsum.query(idx[arr[i]]+1, i);
        ans += tdistinct.query(idx[arr[i]]+1, i)*2*arr[i];
    }

    cout << ans << endl;
    return 0;
}
