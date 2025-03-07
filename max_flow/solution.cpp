#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ii pair<int, int>
#define fi first
#define se second

const int N = 1e5 + 69;
int A[N];

struct ModificatedLine {
  int l, r, val;

  bool operator < (const ModificatedLine &other) const {
    return l < other.l;
  }
};

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  int d;
  vector<ModificatedLine> lines;
  cin >> d;

  int pref[n+5];
  pref[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> A[i];
    pref[i] = pref[i-1] + A[i];
  }

  for (int i = 1; i <= d; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    lines.push_back({a, b, c});
  }
  sort(lines.begin(), lines.end());

  //merge the lines
  vector<ModificatedLine> new_lines;
  for (int i = 0; i < d; i++) {
    int l = lines[i].l, r = lines[i].r, val = lines[i].val;
    int j = i + 1;

    while (j < d && lines[j].l <= r) {
      r = max(r, lines[j].r);
      val += lines[j].val;
      j++;
    }

    new_lines.push_back({l, r, val});
    i = j - 1;
  }

  int ans = 0;
  for (auto line : new_lines) {
    int sum = pref[line.r] - pref[line.l-1];
    ans += min(sum, line.val);
  }

  cout << ans << endl;
}