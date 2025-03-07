#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MAXN = 1e6;
const ll MOD = 1e9 + 7;

ll binpow(ll a, ll b, ll mod = MOD) {
    ll res = 1;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res % mod;
}

int main() {
    ll n;
    vector<ll> freq(MAXN + 1);
    vector<ll> dp(MAXN + 1);

    cin >> n;
    for (ll i = 0; i < n; i++) {
        ll a; cin >> a;
        freq[a]++;
    }   

    for (ll i = 1; i <= MAXN; i++) {
        for (ll j = 2 * i; j <= MAXN; j += i) {
            freq[i] += freq[j];
        }
    }

    for (ll i = 1; i <= MAXN; i++) {
        if (!freq[i]) continue;
        dp[i] = (binpow(2, freq[i]) - 1 + MOD) % MOD;
    }

    for (ll i = MAXN; i >= 1; i--) {
        if (dp[i]) {
            for (ll j = 2 * i; j <= MAXN; j += i) {
                dp[i] = (dp[i] - dp[j] + MOD) % MOD;
            }
        }
    }

    ll res = 0;
    for (ll i = 1; i <= MAXN; i++) {
        res = (res + (i * dp[i]) % MOD) % MOD;
    }
    cout << res << '\n';
}