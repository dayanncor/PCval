#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < n; i++)
#define forne(i, x, n) for (int i = x; i <= n; i++)
#define all(x) x.begin(), x.end()
#define endl '\n'
#define pb push_back
#define ll long long
#define sz(x) int((x).size())
#define each(i, x) for (auto &&i : x)
using namespace std;
#define int int64_t

constexpr int mxN = 1e5 + 100;
vector<int> G[mxN];
vector<bool> vis;
vector<int> parent;
vector<char> digit;

void bfs(int start) {
  queue<int> q;
  q.push(start);
  vis[start] = 1;
  digit[start] = '1';
  parent[start] = -1;

  while (!q.empty()) {
    int v = q.front();
    q.pop();

    if (v == 0)
      return;

    each(to, G[v]) {
      if (!vis[to]) {
        vis[to] = true;
        parent[to] = v;

        
        if ((v * 10) % sz(parent) == to)
          digit[to] = '0';
        else
          digit[to] = '1';

        q.push(to);
      }
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    forn(i, n) G[i].clear();

    vis.assign(n, false);
    parent.assign(n, -1);
    digit.assign(n, '?');

  
  forn(r, n) {
      G[r].pb((r * 10) % n);
      G[r].pb((r * 10 + 1) % n);
    }

    int start = 1 % n;
    bfs(start);

    string ans;
    for (int c = 0; c != -1; c = parent[c])
      ans.push_back(digit[c]);

    reverse(all(ans));
    cout << ans << endl;
  }

  return 0;
}
