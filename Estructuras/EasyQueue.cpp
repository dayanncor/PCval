int t,n;
cin >> t;
int c;
//se declara la cola con su queue<tipo>name;
queue<int> col;
for (int i = 0; i < t; i++) {
	cin >> c;
	switch (c) {
	case 1:
		cin >> n;
//push es para ingresar n dato en la cola, teniendo en cuenta que el primero que entra es el primero que sale
		col.push(n);
		break;
	case 2:
//la funcion empty es para verificar si la cola esta vacia, esta funcion devuelve un true o false dpd del caso
		if (!col.empty()) {
			col.pop();
		}
		break;
	case 3:
		if (!col.empty() == false) {
			cout << "Empty!" << '\n';
		} else {
			cout << col.front() << '\n';
		}
	}
}

