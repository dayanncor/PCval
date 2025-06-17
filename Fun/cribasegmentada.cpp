
#define int int64_t
vector<int> primes;

void numprim(int li) {
    vector<bool> prim(li + 1, true);
    prim[0] = false;
    prim[1] = false;
    for (int i = 2; i * i <= li; ++i) {
        if (prim[i]) {
            for (int j = i * i; j <= li; j += i)
                prim[j] = false;
        }
    }
    for (int i = 2; i <= li; ++i)
        if (prim[i])
            primes.push_back(i);
}

void segmcrib(int n, int m) {
       primes.clear();
    int limit = sqrt(m)+ 1;
    numprim(limit);

    vector<bool> prim(m - n + 1, true);
    for (int p : primes) {
        int start = max(p * p, (n + p - 1) / p * p);
        for (int j = start; j <= m; j += p)
            prim[j - n] = false;
    }

    for (int i = 0; i <=m - n; ++i) {
        if (prim[i] && (i + n) > 1)
            cout << (i + n) << endl;
    }
    cout << endl;
}
  main() {
  int n,m,t;
  cin>>t;
  while(t--){
    cin>>n>>m;
    segmcrib(n, m);
  }
    return 0;
}
