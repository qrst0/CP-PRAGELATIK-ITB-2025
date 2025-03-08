#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ii pair<int, int>
#define fi first
#define se second

int xx[] = {-1, 1, 0, 0};
int yy[] = {0, 0, 1, -1};

int radiation[1005][1005];
int rotated_radiation[2005][2005];
int radius[100005];
ii pos[100005];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m, k;
  cin >> n >> m >> k;

  for (int i = 1; i <= k; i++) {
    cin >> pos[i].fi >> pos[i].se >> radius[i];
  }

  
  memset(radiation, 0, sizeof radiation);
  memset(rotated_radiation, 0, sizeof rotated_radiation);

  for (int i = 1; i <= k; i++) {
    int centerx = pos[i].fi + pos[i].se;
    int centery = pos[i].fi - pos[i].se + m;

    int lefthighx = max(1LL, centerx - radius[i]);
    int lefthighy = max(1LL, centery - radius[i]);
    int rightlowx = min(n+m, centerx + radius[i]);
    int rightlowy = min(n+m, centery + radius[i]);

    rotated_radiation[lefthighx][lefthighy]++;
    rotated_radiation[rightlowx + 1][rightlowy + 1]++;
    rotated_radiation[lefthighx][rightlowy + 1]--;
    rotated_radiation[rightlowx + 1][lefthighy]--;
  }

  for (int i = 1; i <= n+m; i++) {
    for (int j = 1; j <= n+m; j++) {
      rotated_radiation[i][j] = rotated_radiation[i][j] + rotated_radiation[i-1][j] + rotated_radiation[i][j-1] - rotated_radiation[i-1][j-1];
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int posx = i+j;
      int posy = i-j+m;

      radiation[i][j] = rotated_radiation[posx][posy];
    }
  }
  

  int l = 1, r = 1e18, ans = -1;
  while (l <= r) {
    int mid = (l+r)/2;

    int dis[n+5][m+5];
    memset(dis, -1, sizeof(dis));

    queue<tuple<int, int, int>> q;
    q.push({1, 1, mid - radiation[1][1]});
    dis[1][1] = mid - radiation[1][1];

    if (dis[1][1] <= 0) {
      l = mid+1;
      continue;
    }

    while (!q.empty()) {
      auto [x, y, curHp] = q.front();
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