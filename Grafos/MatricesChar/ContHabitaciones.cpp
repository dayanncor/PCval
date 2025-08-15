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

constexpr int mxN = 1000+100;
char g[mxN][mxN];
int vis[mxN][mxN];
int n,m;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
void dfs(int x, int y){

    vis[x][y] = 1;

    forn(i,4){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >=0 && nx < n && ny>=0 && ny < m && vis[nx][ny]==0 && g[nx][ny]!='#'){
            dfs(nx,ny);
        }
    }
}
main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n>>m;
    forn(i,n)forn(j,m){
        cin>>g[i][j];
    }

    int ans = 0;
    forn(i,n){
        forn(j,m){
            if(vis[i][j]==0 && g[i][j]!='#'){
                ans++;
                dfs(i,j);
            }
        }
    }
    cout << ans <<endl;
    cout << flush;
    return 0;
}
