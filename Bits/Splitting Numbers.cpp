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
  int n;
    while (cin >> n && n != 0) {
        int x = 0, y = 0;
        bool ban = true;  
        int pos = 0;     
        while (n > 0) {
            if (n & 1) {
                if (ban) {
                    x |= (1u << pos);
                } else {
                    y |= (1u << pos);
                }
                ban = !ban; 
            }
            n >>= 1; 
            pos++;
        }
        cout << x << " " << y << endl;
    }
    return 0;
}
