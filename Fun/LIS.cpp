/*Longest Increasing Subsequence (LIS)
La subsecuencia creciente mC!s larga (LIS) es aquella donde los elementos estC!n en orden estrictamente creciente
(cada uno mayor que el anterior), y la longitud
de esta subsecuencia es la mayor posible. */

//upper_bound -->devuelve un iterador a la primera posicion estrictamente mayor que el valor.
//lower_bound -->devuelve un iterador a la primera posicion mayor o igual.

int lis(vector<int>& a) {
	vector<int>vec;
	forn(i, sz(a)) {
		auto it = lower_bound(all(vec), a[i]);
		if (it != vec.end()) *it = a[i];
		else vec.push_back(a[i]);
	}
	return sz(vec);
}

constexpr int INF = ((1ULL << 63) - 1) >> 32;
template<typename T> vector<T> lis(vector<T>& v) {
	int n = sz(v), m = -1;
	vector<T> d(n + 1, INF);
	vector<int> l(n);
	d[0] = -INF;

	forn(i, n) {
		// Para non-decreasing use upper_bound()
		int t = lower_bound(all(d), v[i]) - begin(d);
		d[t] = v[i], l[i] = t, m = max(m, t);
	}

	int p = n;
	vector<T> ans;
	while (p--) if (l[p] == m) {
			ans.push_back(v[p]);
			m--;
		}
	reverse(all(ans));
	return ans;
}


int lis_2(int n, vector<int>& A, vector<int>& B) {

	vector<vector<int>>C(inf, vector<int>());
	reverse(all(A));
	reverse(all(B));
	for (int i = n - 1; i >= 0; i--) C[B[i]].pb(i);

	STree<int> dp(n); // Stree de max, neutro = INT_MIN

	for (int j = 0; j < n; j++) {
		for (auto&& i : C[A[j]]) {
			int mx_pre = dp.query(0, i);
			if (mx_pre != INT_MIN) dp.upd(i, mx_pre + 1);
			else dp.upd(i, 1);
		}
	}
	return dp.query(0, n);
}
