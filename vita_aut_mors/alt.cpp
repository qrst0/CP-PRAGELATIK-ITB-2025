#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ii pair<int, int>
#define fi first
#define se second

int xx[] = {-1, 1, 0, 0};
int yy[] = {0, 0, 1, -1};


signed main() {
  int n, m, k;
  cin >> n >> m >> k;

  int radius[k+5];
  ii pos[k+5];
  for (int i = 1; i <= k; i++) {
    cin >> pos[i].fi >> pos[i].se >> radius[i];
  }

  int radiation[n+5][m+5];
  memset(radiation, 0, sizeof radiation);

  for (int i = 1; i <= k; i++) {
    for (int x = 1; x <= n; x++) {
      for (int y= 1; y <= m; y++) {
        if (abs(x - pos[i].fi) + abs(y - pos[i].se) <= radius[i]) {
          radiation[x][y]++;
        }
      }
    }
  }

  // for (int i = 1; i <= n; i++) {
  //   for (int j = 1; j <= m; j++) {
  //     cout << radiation[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  int l = 1, r = 1e18, ans = -1;
  while (l <= r) {
    int mid = (l+r)/2;

    int dis[n+5][m+5];
    memset(dis, -1, sizeof(dis));

    priority_queue<tuple<int, int, int>> q;
    q.push({1, 1, mid});
    dis[1][1] = mid - radiation[1][1];

    while (!q.empty()) {
      auto [x, y, curHp] = q.top();
      q.pop();

      if (dis[x][y] > curHp) continue;

      for (int i = 0; i < 4; i++) {
        int nx = x + xx[i];
        int ny = y + yy[i];

        if (nx <= 0 || ny <= 0 || nx > n || ny > m) continue;

        int damage = radiation[nx][ny];
        int newHp;
        if (damage == 0) newHp = mid;
        else newHp = curHp - damage;

        if (newHp <= 0) continue;

        if (newHp > dis[nx][ny]) {
          dis[nx][ny] = newHp;
          q.push({nx, ny, newHp});
        }
      }
    }

    if (dis[n][m] == -1) l = mid+1;
    else {
      ans = mid;
      r = mid-1;
    }
  }

  cout << ans << endl;
}