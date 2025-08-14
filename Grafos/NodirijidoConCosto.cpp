//Grafo no dirijido, donde busca 1 solo camino, con el mayor costo donde el costo es w y se le suma lo que se recorre
constexpr int mxN = 1e4 + 100;
vector<array<int,2>> g[mxN];
vector<int>vis(mxN);
int n, m; 

int dfs(int u){

    vis[u] = 1;
    int ans = 0;
    each(i,g[u]){
        if(vis[i[0]]==0){
            ans = max (ans, dfs(i[0])+i[1]);
        }
    }

    return ans;

}



main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


    cin>>n;
    forn(i,n-1){
        int u, v, w; cin>>u>>v>>w;
        g[u].pb({v,w});
        g[v].pb({u,w});
    }    
    cout<< dfs(0)<<endl;


    cout << flush;
    return 0;
}
