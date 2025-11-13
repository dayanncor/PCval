constexpr int mxN = 2 * 1e5 + 100;
vector<int> G[mxN];
vector<bool> vis(mxN);
vector<int> tam(mxN);
int n, m, v=2, u;
int dfs(int u) {
  vis[u] = 1;
  int cont = 0;
  each(i, G[u]) {
    if (vis[i] == 0) {
      cont += dfs(i)+1;
    }
  }
  tam[u] = cont;
  return tam[u];
}

main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  forne(i,1, n) {
    cin >> u;
    G[u].pb(v);
    v++;
  }
//   forn(i,10){
//     cout << i << "   ";
//     each(j,G[i]) cout << j<<" ";

//     cout<< endl;
//   }

  dfs(1);
  forne(i,0,n){
    cout<<tam[i+1]<<" ";
  }
  return 0;
}
