/*Para este caso, se requiere contar letras contantes en un cadena s, donde
al final se busca tener la cadena mas larga de letras consecutivas*/
//metodo agregar letra
void agregar(char c, int &cb, int &cw) {
	if (c == 'W') {
		cw++;
	} else {
		cb++;
	}
}
//metodo eliminar letra
void eliminar(char c, int &cb, int &cw) {
	if (c == 'W') {
		cw--;
	} else {
		cb--;
	}
}
main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	string s;
	cin >> t;
	while (t--) {
		int n, k, cb=0, cw=0, l=0;
		cin >> n >> k;
		int mini=n;
		cin >> s;
		forn(i, n) {
			//se llama al metodo, y se le dan sus respectivos parametros
			agregar(s[i], cb, cw);
			if((cb+cw)>=k) {
				//se saca el minimo
				mini=min(mini, cw);
				eliminar(s[l], cb, cw);
				l++;

			}
		}
		cout<<mini<<endl;

	}


	return 0;
}
