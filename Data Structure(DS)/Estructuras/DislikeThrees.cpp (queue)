int t;
cin >> t;
int n;

while (t--) {
	queue<int> name;
	int cont = 1;
	cin >> n;
	while (name.size() < n) {
		if(cont%3 != 0 && cont%10 != 3) {
			name.push(cont);
		}
		cont++;
	}
	//el back() accede al ultimo valor de la cola
	cout << name.back() << endl;
}
