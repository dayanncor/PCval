//se trabaja con punteros l y r
#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define endl '\n'
#define ll long long
#define int int64_t
main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//Tener en cuenta que para trabajar con punteros, r siempre va a tener la respuesta
//por otro lado, l contiene el numero anterior a la respuesta
	int n, x;
	cin >> n >> x;
	vector<pair<int, int>> vec(n);
	forn(i, n) {
		// al ser un vector pair, se llena la primera caja con i
		cin >> vec[i].first;
		//y el segundo espacio se llena con el valor de i+1
		vec[i].second = (i + 1);
	}
	//se organizan los datos del vector, de menor a mayor
	sort(vec.begin(), vec.end());
	for (int i = 0; i < n; i++) {
		int l = 0, r = (n - 1);
		while (l <= r) {
			//se suman los valores que se encuentran en la primera caja de pair
			int sum = vec[l].first + vec[r].first+vec[i].first;
			auto a=vec[i];
			auto b=vec[l];
			auto c=vec[r];
			if((a.second!=b.second && a.second!=c.second && b.second!=c.second) &&(( vec[l].first + vec[r].first+vec[i].first)==x)) {
				if(sum==x) {
					cout<<a.second<<" "<<b.second<<" "<<c.second<<endl;
					return 0;
				}
			}
			if(sum>x) {
				r--;
			} else {
				l++;
			}
		}

	}
	cout<<"-1"<<endl;
	return 0;
}
