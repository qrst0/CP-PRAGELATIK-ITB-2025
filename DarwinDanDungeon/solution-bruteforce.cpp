#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        
        int cnt = 0;
        for (int i = l; i <= r; i++) {
            if (isPrime(i)) {
                cnt++;
            }
        }
        
        cout << cnt << '\n';
    }
}
