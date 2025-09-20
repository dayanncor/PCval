#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define endl '\n'
#define ll long long
#define sz(x)    int((x).size())
#define each(i,x) for(auto &&i:x)
using namespace std;
#define int int64_t
int n, m;
vector<string> vec;
int hx, hy; 
//coordenadas
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
 
bool bfs(vector<string> g) {
    queue<pair<int,int>> q;
    vector<vector<bool>> vis(n, vector<bool>(m,false));
    q.push({hx,hy});
    vis[hx][hy] = true;
 
    while(!q.empty()) {
        auto [x,y] = q.front(); q.pop();
        forn(k,4){
            int nx=x+dx[k], ny=y+dy[k];
            if(nx<0||ny<0||nx>=n||ny>=m) continue;
            if(vis[nx][ny]) continue;
            if(g[nx][ny]=='Q' || g[nx][ny]=='H'){
                vis[nx][ny]=true;
                q.push({nx,ny});
            }
        }
    }
 
    
    forn(i,n){
        forn(j,m){
            if(g[i][j]=='Q' && !vis[i][j]) return true; 
        }
    }
    return false; 
}
 
 
 main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    cin>>n>>m;
   vec.resize(n);
    forn(i,n){
        cin >> vec[i];
        forn(j,m){
            if(vec[i][j]=='H'){ hx=i; hy=j; }
        }
    }
 
    int totalQ=0;
    for(auto &row: vec)
        totalQ += count(row.begin(), row.end(), 'Q');
 
   
 
    if(bfs(vec)){
        cout << 0 << endl;
        return 0;
    }
 
    forn(k,4){
        int nx=hx+dx[k], ny=hy+dy[k];
        if(nx<0||ny<0||nx>=n||ny>=m) continue;
        if(vec[nx][ny]=='Q'){
            auto g2 = vec;
            g2[nx][ny]='.'; 
            if(bfs(g2)){
                cout << 1 << endl;
                return 0;
            }
        }
    }
    for (int k1=0;k1<4;k1++){
        int x1=hx+dx[k1], y1=hy+dy[k1];
        if(x1<0||y1<0||x1>=n||y1>=m) continue;
        if(vec[x1][y1]!='Q') continue;
 
        for (int k2=k1+1;k2<4;k2++){
            int x2=hx+dx[k2], y2=hy+dy[k2];
            if(x2<0||y2<0||x2>=n||y2>=m) continue;
            if(vec[x2][y2]!='Q') continue;
 
            auto g3 = vec;
            g3[x1][y1]='.';
            g3[x2][y2]='.';
            if(bfs(g3)){
                cout << 2 << endl;
                return 0;
            }
        }
    }
 
    cout << -1 << endl;
    return 0;
 }
