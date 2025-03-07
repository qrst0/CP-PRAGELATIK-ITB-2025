#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;

int main() {
    vector<int> lp(N + 1);
    vector<int> pr;
    vector<int> pref(N + 1, 0);

    for (int i = 2; i <= N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; i * pr[j] <= N; ++j) {
            lp[i * pr[j]] = pr[j];
            if (pr[j] == lp[i]) {
                break;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        pref[i] = pref[i - 1] + (lp[i] == i);
    }

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << pref[r] - pref[l - 1] << '\n';
    }
}