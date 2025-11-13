
constexpr int mxN = 1e5 + 100;
vector<int> G[mxN];
vector<bool> vis(mxN);

main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  forn(i, m) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    G[u].pb(v);
    G[v].pb(u);
  }
  auto bfs=[&](int u) -> void{
    queue<int> q;
    q.push(u);
    vis[u] = 1;
    while (sz(q)) {
      int v = q.front();
      q.pop();
      each(i, G[v]) {
        if (!vis[i]) {
          q.push(i);
          vis[i] = 1;
        }
      }
    }
  };
  vector<int>ans;
  bfs(0);
  forn(i, n){
    if(!vis[i]){
        ans.pb(i);
        bfs(i);   
    }
  }
  cout<<sz(ans)<<endl;
  forn(i,sz(ans)) cout<<1<<" "<<ans[i]+1<<endl;
  
  return 0;
}
