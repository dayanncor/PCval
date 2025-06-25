#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define endl '\n'
#define sz(x) int((x).size())
using namespace std;

typedef long long ll;
const int MAXN = 2e5 + 5;

struct Intervalo {
    ll min_len, max_len;
    int index;
};

 int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;

    vector<pair<ll, ll>> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i].first >> vec[i].second;
    }

    vector<Intervalo> inte;
    for (int i = 0; i < n - 1; ++i) {
        ll min_len = vec[i + 1].first - vec[i].second;
        ll max_len = vec[i + 1].second - vec[i].first;
        if (min_len > max_len) swap(min_len, max_len); 
        inte.push_back({min_len, max_len, i});
    }

    sort(inte.begin(), inte.end(), [](const Intervalo &a, const Intervalo &b) {
        return a.min_len < b.min_len;
    });

    vector<pair<ll, int>> puentes(m);
    for (int i = 0; i < m; ++i) {
        ll a;
        cin >> a;
        puentes[i] = {a, i + 1};
    }

    sort(puentes.begin(), puentes.end());

    vector<int> ans(n - 1, -1);
    set<pair<ll, int>> candidatos;

    int j = 0;
    forn(i,m) {
        ll longitud = puentes[i].first;

       
        while (j < n - 1 && inte[j].min_len <= longitud) {
            candidatos.insert({inte[j].max_len, inte[j].index});
            ++j;
        }
        auto it = candidatos.lower_bound({longitud, -1});
        if (it != candidatos.end()) {
            int idx = it->second;
            ans[idx] = puentes[i].second;
            candidatos.erase(it);
        }
    }

    if (all_of(ans.begin(), ans.end(), [](int x) { return x != -1; })) {
        cout << "Yes"<<endl;
        forn(i, n - 1) {
            cout << ans[i] <<" ";
        }
        cout<<endl;
    } else {
        cout<< "No"<<endl;
    }

    return 0;
}
