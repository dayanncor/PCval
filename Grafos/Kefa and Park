// contar los caminos validos

constexpr int mxN = 2 * 1e5 + 100;
vector<int> G[mxN];
vector<bool> vis(mxN);
vector<int> ans(mxN);
int n, m, v, ct;

// se usa x=-1, como el nodo padre, y se usa para no volver a visitarlo, y contar un camino demas
void dfs(int u, int s, int x=-1) {
  bool ban=false;
  if(ans[u]==1) s++;
  else s=0;
  if (s > m)return;
  
   ban = true;

  each(i, G[u]) {
    if (i==x) continue;
   ban=false;
      dfs(i, s, u);
    
  }
  if (ban)  ct++;
}

main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int u;
  cin >> n >> m;
  forn(i, n) cin >> ans[i+1];
  forn(i, n-1) {
    cin >> u >> v;
    G[u].pb(v);
    G[v].pb(u);
  }

  dfs(1, 0);
  cout << ct << endl;
  return 0;
}
