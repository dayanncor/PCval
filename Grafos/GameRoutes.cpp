
const int MOD = 1e9 + 7;
int64_t binpow(int64_t a, int64_t b, int64_t m) {
  a %= m;
  int64_t res = 1;
  while (b > 0) {
    if (b & 1)
      res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
inline int inv_mod(int a) { return binpow(a, MOD - 2, MOD); }
inline int add(int a, int b) { return ((a % MOD) + (b % MOD)) % MOD; }
inline int res(int a, int b) { return ((a % MOD) - (b % MOD) + MOD) % MOD; }
inline int mul(int a, int b) { return ((a % MOD) * (b % MOD)) % MOD; }
inline int divm(int a, int b) { return mul(a, inv_mod(b)); }

constexpr int mxN = 1e5 + 100;
vector<int> G[mxN];
vector<int> vis(mxN);
vector<int> cont(mxN);
int n, m, v, u;
int dfs(int u) {
  if (u == n)
    return 1;
  if (vis[u])
    return cont[u];
  vis[u] = 1;
  each(i, G[u]) { cont[u] = add(cont[u], dfs(i)); }
  return cont[u];
}
main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  forn(i, m) {
    cin >> u >> v;
    G[u].pb(v);
  }

  cout << dfs(1) << endl;

  return 0;
}
