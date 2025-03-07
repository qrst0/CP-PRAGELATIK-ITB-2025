#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e5 + 10;

int A[maxN], B[maxN];

const int M = (1 << 15);
const int K = 14;

int basis[M][K];

int reduce(int index, int x) {  
	for (int i = K - 1; i >= 0; i--) {
		if (x & (1 << i)) { 
			x ^= basis[index][i];
		}
	}
	return x;
}

void add(int index, int x) {
	x = reduce(index, x);  
	if (x != 0) {
		for (int i = K - 1; i >= 0; i--) {
			if (x & (1 << i)) {
				basis[index][i] = x;
				return;
			}
		}
	}
}

bool check(int index, int x) {
	return (reduce(index, x) == 0);
}

void merge(int i1, int i2) {
    for (int i = K - 1; i >= 0; i--) {
        if (basis[i2][i] != 0) {
            add(i1, basis[i2][i]);
        }
    }
}

int main() {
    int N, Q;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }
    for (int i = 0; i < N; i++) {
        add(B[i], A[i]);
    }
    for (int i = 0; i < 15; i++) {
        for(int mask = 0; mask < M; mask++){
            if (mask & (1 << i)) {
                merge(mask, mask ^ (1 << i)); 
            }   
        }
    }
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int X;
        cin >> X;
        if (!check(M - 1, X)) {
            cout << "-1\n";
            continue;
        }
        int ans = M - 1;
        for (int i = 14; i >= 0; i--) {
            if (check(ans ^ (1 << i), X)) {
                ans ^= (1 << i);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}