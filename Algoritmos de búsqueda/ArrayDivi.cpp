int n, x,ans;
cin >> n >> x;
vector<int> vec(n);
forn(i, n) cin >> vec[i];
//funcion *max_element  devuelve el valor mas grande entre el rango dando
// el * se usa para que trabaje con lo que contiene esas pocisiones y no con los iteradores

int l = *max_element(vec.begin(), vec.end());

//se hace la multiplicacion, para que en cualquier cosa agarre el valor mas grande que puede tomar un caso
int r = (2*1e5)*(1e9);
ans=r;
while (l <= r) {
	//se aplica la ecuacion de busqueda binaria
	int mid = l + (r - l) / 2;
	int acu=0, cont=1;
	forn(i, n) {
		if (acu + vec[i] > mid) {
			cont++;
			acu = vec[i];
		} else {
			acu += vec[i];
		}
	}
	if (cont<=x) {
		ans=mid ;
		r = mid-1;
	} else {
		l = mid + 1;
	}
}
cout << ans << endl;
