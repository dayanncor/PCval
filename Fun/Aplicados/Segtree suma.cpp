template<typename T>
struct STree {
    int n; vector<T> st;
    T neutro = T(0);

    STree(vector<T>& a) {
        n = sz(a);
        st.resize(n * 4);
        build(1, 0, n - 1, a);
    }

    T oper(T a, T b) {return a + b; } //aqui se modifica la operacion, ya sea max, min o sumas ya asi

    void build(int v, int tl, int tr, vector<T>& a) {
        if (tl == tr) {
            st[v] = a[tl];
            return;
        }
        int tm = (tr + tl) / 2;
        build(v * 2, tl, tm, a);
        build(v * 2 + 1, tm + 1, tr, a);
        st[v] = oper(st[v * 2], st[v * 2 + 1]);
    }

    T query(int v, int tl, int tr, int l, int r) {
        if (tl > r || tr < l) return neutro;
        if (l <= tl && tr <= r) return st[v];
        int tm = (tl + tr) / 2;
        return oper(query(v * 2, tl, tm, l, r), query(v * 2 + 1, tm + 1, tr, l, r));
    }

    void upd(int v, int tl, int tr, int pos, T val) {
        if (tl == tr) {
            st[v] = val;
            return;
        }
        int tm = (tr + tl) / 2;
        if (pos <= tm) upd(v * 2, tl, tm, pos, val);
        else upd(v * 2 + 1, tm + 1, tr, pos, val);
        st[v] = oper(st[v * 2], st[v * 2 + 1]);
    }
    void upd(int pos, T val) { upd(1, 0, n - 1, pos, val); }
    T query(int l, int r) { return query(1, 0, n - 1, l, r); }
};
main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n,m,p,l,r;
    cin>>n;
    cin>>m;
    vector<int> vec(n);
    for (int& x : vec) cin>>x;

    STree st(vec);

    for (int i = 0; i < m; i++) {
        cin>>p;
        if (p == 1) {
            int a,v;
            cin>>a;
            cin>>v;
            st.upd(a, v);
        } else if (p == 2) {
            cin>>l;
            cin>> r;
            cout<<st.query(l, r-1)<<endl;
        }
    }
