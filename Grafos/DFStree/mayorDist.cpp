#include <bits/stdc++.h>
using namespace std;
#define endl     '\n' 
#define f        first
#define s        second
#define ins      insert
#define pb       push_back
#define eb       emplace_back
#define sz(x)    int((x).size())
#define all(x)   begin(x), end(x)
typedef long long ll;
typedef unsigned long long ull;
#define forn(i, n) for (int i = 0; i < n; ++i)
#define each(i, x) for (auto &&i : x)
#define forne(i,n) for (int i = 1; i <= n; ++i)
#define show(x) for (auto &&i : x) {cerr << i <<' ';} cerr<< endl;


void dbg_out() { cerr << ']' << endl; }
template<typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) { cerr << H;if (sizeof...(T)) cerr << ',' << ' '; dbg_out(T...); }
#ifdef LOCAL 
#define dbg(...) cerr << '|' << _LINE_ << '|'<< '{' << #_VA_ARGS_ << '}'<<':'<<' '<<'[', dbg_out(_VA_ARGS_)
#else
#define dbg(...)
#endif


#define int int64_t
constexpr int mxN = 2 * 1e5 + 100;
vector<int> G[mxN];
int dist[mxN];
vector<int> vis(mxN);
int n, m, x;

void dfs(int u, int d) {
    vis[u]=1;
    dist[u]=d;
    each(i, G[u]){
        if(!vis[i]){
            dfs(i, d+1);
        }

    }    
}



signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
     cout.tie(0);
     int u, v,mx=0;    
     cin>>n;
    
      forn(i, n-1){
    cin>>u>>v;
    G[u].pb(v);
    G[v].pb(u);
   }
//el fill 
   fill(all(vis), 0);
    dfs(1, 0);

    int c = 1;
    forne(i, n) {
        if (dist[i] > dist[c]) c = i;
    }

    fill(all(vis), 0);
    dfs(c, 0);

    forne(i, n) {
        mx = max(mx, dist[i]);
    }

    cout << mx << endl;

    return 0;
}
