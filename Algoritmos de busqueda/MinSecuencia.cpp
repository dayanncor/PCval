 #include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define endl '\n'
#define ll long long
#define sz(x)    int((x).size())
using namespace std;
#define int int64_t
main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
 int n,m;
 int l=0,acu=0;
int mini=1e18;
 cin>>n>>m;
 vector <int> vec(n);
forn(i,n)cin>>vec[i];
forn(i,n) {
        acu += vec[i];
        while (acu >= m) {
            mini = min(mini, i - l + 1);
            acu -= vec[l];
            l++;
        }
    }
    cout<<mini<<endl;


    return 0;
}
 
