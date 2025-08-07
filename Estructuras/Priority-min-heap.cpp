//Usa una min-heap (priority_queue con greater<int>), que siempre tiene arriba el nC:mero mC!s pequeC1o.

int AddAll(vector<int>& A) {

/*declara una cola de prioridad (priority queue) en C++, pero con una caracterC-stica especial:
se comporta como una min-heap, es decir, siempre coloca el valor
mas pequenio arriba. */

	priority_queue<int>, vector<int>, greater<int>> colMin;

	for (int x : A) {
//para ingresar datos name.push()
		colMin.push(x);
	}
	int sum, seg, prim, ans = 0;

	while (colMin.size() > 1) {
		prim = colMin.top();
//para borrar la cola o un valor es con name.pop(), pero se guarda en un temporal
		colMin.pop();
		seg = colMin.top();
		colMin.pop();
		sum = prim + seg;
		ans += sum;
		colMin.push(sum);
	}

	return ans;
}

main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		vector<int> vec(n);
		for (int i = 0; i < n; i++) {
			cin >> vec[i];
		}

		cout << AddAll(vec) << endl;

	}
