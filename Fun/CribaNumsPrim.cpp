#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define endl '\n'
#define ll long long
#define sz(x) int((x).size())
using namespace std;
#define int int64_t
main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t, n, m;
  cin >> t;
  while (t--) {
    cin>>n>>m;
    vector<bool>prim(m+1, true);
    //se inicializa los dos primeros valores en false
    prim[0]=false;
    prim[1]=false;
    for(int i=2; i * i <= m; i++){
        if(prim[i]){
             for (int j = i * i; j <= m; j += i) {
                prim[j]=false;
        }
    }
    }
    for(int i=n; i<=m; i++){
          if (prim[i]){
            cout << i << endl;
          }
    }
    cout<<endl;

  }
}
