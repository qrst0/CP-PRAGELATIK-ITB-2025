#include <bits/stdc++.h>

using namespace std;

const int K = 14;

int reduce(array<int, K> &b, int x) {  
	for (int i = K - 1; i >= 0; i--) {
		if (x & (1 << i)) { 
			x ^= b[i];
		}
	}
	return x;
}

bool add(array<int, K> &b, int x) {
	x = reduce(b, x);  
	if (x != 0) {
		for (int i = K - 1; i >= 0; i--) {
			if (x & (1 << i)) {
				b[i] = x;  // 
				return true;
			}
		}
	}
	return false;
}

bool check(array<int, K> &b, int x) {
	return (reduce(b, x) == 0); 
}

int main() {
    int N, Q;
    cin >> N;
    vector<int> A(N);
    vector<int> B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int X;
        cin >> X;
        int ans = INT_MAX;
        if (N >= 30) {
            cout << "-2\n";
            continue;
        }
        for (int mask = 0; mask < (1 << N); mask++) {
            array<int, K> b{0};
            int cur = 0;
            for (int j = 0; j < N; j++) {
                if (mask & (1 << j)) {
                    add(b, A[j]);
                    cur |= B[j];
                }
            }
            if (check(b, X)) {
                ans = min(ans, cur);
            }
        }
        if (ans == INT_MAX) {
            cout << "-1\n";
        } else {
            cout << ans << '\n';
        }
    }
}