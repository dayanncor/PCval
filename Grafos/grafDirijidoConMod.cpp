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
#define forne(i,x,n) for (int i = x; i < n; ++i)
#define show(x) for (auto &&i : x) {cerr << i <<' ';} cerr<< endl;
void dbg_out() { cerr << ']' << endl; }
template<typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) { cerr << H;if (sizeof...(T)) cerr << ',' << ' '; dbg_out(T...); }
#ifdef LOCAL 
#define dbg(...) cerr << '|' << __LINE__ << '|'<< '{' << #__VA_ARGS__ << '}'<<':'<<' '<<'[', dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
#define int int64_t

constexpr int MOD = 1e9 + 7;

int64_t binpow(int64_t a, int64_t b, int64_t m) {
    a %= m;
    int64_t res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
inline int inv_mod(int a) { return binpow(a, MOD - 2, MOD); }
inline int add(int a, int b) { return ((a % MOD) + (b % MOD)) % MOD; }
inline int res(int a, int b) { return ((a % MOD) - (b % MOD) + MOD) % MOD; }
inline int mul(int a, int b) { return ((a % MOD) * (b % MOD)) % MOD; }
inline int divm(int a, int b) { return  mul(a, inv_mod(b)); }


constexpr int mxN = 1e5+100;
vector<int>g[mxN];
int vis[mxN];
int ans[mxN];
int n,m;


int dfs(int u){

    if(u == n-1) return 1;
    if(vis[u]) return ans[u];
    vis[u] = 1;

    int new_ans = 0;    
    each(v,g[u]){
        new_ans = add(new_ans,dfs(v));
    }

    ans[u] = add(ans[u],new_ans);


    return ans[u];
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin>>n>>m;

    forn(i,m){
        int u ,v; cin>>u>>v;
        u--,v--;
        g[u].pb(v);
    }

    int ans = dfs(0);
    cout << ans <<endl;
    cout << flush;
    return 0;
}
