#include <bits/stdc++.h>
#include <cstring>
using namespace std;
#define endl '\n'
#define f first
#define s second
#define ins insert
#define pb push_back
#define eb emplace_back
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
typedef long long ll;
typedef unsigned long long ull;
#define forn(i, n) for (int i = 0; i < n; ++i)
#define each(i, x) for (auto &&i : x)
#define forne(i, x, n) for (int i = x; i < n; ++i)
#define show(x)                                                                \
  for (auto &&i : x) {                                                         \
    cerr << i << ' ';                                                          \
  }                                                                            \
  cerr << endl;
void dbg_out() { cerr << ']' << endl; }
template <typename Head, typename... Tail> void dbg_out(Head H, Tail... T) {
  cerr << H;
  if (sizeof...(T))
    cerr << ',' << ' ';
  dbg_out(T...);
}
#ifdef LOCAL
#define dbg(...)                                                               \
  cerr << '|' << __LINE__ << '|' << '{' << #__VA_ARGS__ << '}' << ':' << ' '   \
       << '[',                                                                 \
      dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
#define int int64_t
//cordenadas para manejar x y y
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

constexpr int mxN = 1000;
char G[mxN][mxN];
bool vis[mxN][mxN];
int n, m;

int cont = 0;
void dfs(int x, int y) {
  vis[x][y] = 1;
  forn(i, 4) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    //condicion para verificar si se puede visitar y se cuenta
    if (ny >= 0 && ny < m && nx >= 0 && nx < n && vis[nx][ny] == 0 && G[nx][ny] != '#') {
      cont++;
      dfs(nx, ny);
    }
  }
}
main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t, k = 0;
  cin >> t;
  while (t--) {
    memset(vis, 0, sizeof vis);
    k++;
    cin >> n >> m;
    swap(n, m);
    forn(i, n) {
      forn(j, m) { cin >> G[i][j]; }
    }
    forn(i, n) forn(j, m) {
      if ((G[i][j] == '@') && vis[i][j] == 0) {
        dfs(i, j);
        cont++;
      }
    }
    cout << "case " << k << ": " << cont << endl;
    cont = 0;
  }
  cout << flush;
  return 0;
}
