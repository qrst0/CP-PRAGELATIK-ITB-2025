#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll res = 0;

    for (ll mask = 1; mask < (1LL << n); mask++) {
        ll subs = 0;

        for (ll i = 0; i < n; i++) {
            if (mask & (1LL << i)) {
                subs = __gcd(subs, a[i]);
            }
        }
        res = (res + subs) % MOD;
    }

    cout << res << '\n';
    return 0;
}
