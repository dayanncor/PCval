
struct conta {
    int mini;
    int ct;
    conta(int val = 1e18, int cont = 0) : mini(val), ct(cont) {}
};

conta oper(conta a, conta b) {
    if (a.mini < b.mini) return a;
    if (a.mini > b.mini) return b;
    return conta(a.mini, a.ct + b.ct);
}

template<typename T>
struct STree {
    int n;
    vector<T> st;
    T neutro;

    STree(vector<T>& a, T neutro_val) : neutro(neutro_val) {
        n = sz(a);
        st.resize(n * 4);
        build(1, 0, n - 1, a);
    }

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
        return oper(query(v * 2, tl, tm, l, r),
                    query(v * 2 + 1, tm + 1, tr, l, r));
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

    int n, m;
    cin >> n >> m;

    vector<conta> vec(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        vec[i] = conta(x, 1);
    }

    STree<conta> st(vec, conta(1e18, 0));

    for (int i = 0; i < m; i++) {
        int p, l, r, a, v;
        cin >> p;
        if (p == 1) {
            cin >> a >> v;
            st.upd(a, conta(v, 1));
        } else if (p == 2) {
            cin >> l >> r;
            conta ans = st.query(l, r - 1);
            cout << ans.mini << " " << ans.ct << endl;
        }
    }

    return 0;
}
