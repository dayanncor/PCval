/*arbol de segmentos especializado para resolver consultas sobre la longitud de la subsecuencia mas larga de
parentesis balanceados */

struct node {
	int start, end, maxLen;
};
struct STregularBracket {
	vector<node> vecSegmentos;
	int size;

	STregularBracket(string S) {
		S = "0" + S;
		size = sz(S);
		vecSegmentos.resize(4 * size); //modifica el tamanio del vector
		build(1, 1, size - 1, S); // construye el arbol de segmentos.
	}
	void build(int idx, int s, int e, string& S) {
		/*idx: indice del nodo actual en el arbol (almacenado en el vector seg).
		s, e: el rango [s, e] de la cadena que este nodo cubre.
		S: la cadena de parC)ntesis (se pasa por referencia para eficiencia).*/
		if (s == e) {
/* Si es '(', hay 1 paretesis abierto sin pareja: {start = 1, end = 0}.
Si es ')', hay 1 parentesis cerrado sin pareja: {start = 0, end = 1}.
maxLen es 0 porque no hay pareja posible. */
			if (S[s] == '(') vecSegmentos[idx] = { 1, 0 };
			else vecSegmentos[idx] = { 0, 1 };
			return;
		}

//Hijo izquierdo: indice idx * 2 (idx << 1), cubre [s, mid].
//Hijo derecho: indice idx * 2 + 1 (idx << 1 | 1), cubre [mid+1, e].
		build(idx << 1, s, (s + e) / 2, S);
		build(idx << 1 | 1, (s + e) / 2 + 1, e, S);
/*Aqui- se inicializa el nodo idx con:
start = vecSegmentos[hijo derecho].start
end = vecSegmentos[hijo izquierdo].end*/

		vecSegmentos[idx] = { vecSegmentos[idx << 1 | 1].start, vecSegmentos[idx << 1].end };
		int dif = vecSegmentos[idx << 1].start - vecSegmentos[idx << 1 | 1].end;
		int mini = min(vecSegmentos[idx << 1].start, vecSegmentos[idx << 1 | 1].end);

		vecSegmentos[idx].maxLen += mini * 2 + vecSegmentos[idx << 1 | 1].maxLen + vecSegmentos[idx << 1].maxLen;
		if (dif > 0) vecSegmentos[idx].start += dif;
		else vecSegmentos[idx].end -= dif;
	}

	node query(int idx, int s, int e, int l, int r) {
		if (l > e || s > r) return { 0, 0 };
		if (s >= l && e <= r) return vecSegmentos[idx];
		node p1 = query(idx << 1, s, (s + e) / 2, l, r);
		node p2 = query(idx << 1 | 1, (s + e) / 2 + 1, e, l, r);
		node ans = { p2.start, p1.end };
		int dif = p1.start - p2.end;
		ans.maxLen += p1.maxLen + p2.maxLen;
		ans.maxLen += min(p1.start, p2.end) * 2;
		if (dif > 0) ans.start += dif;
		else ans.end -= dif;
		return ans;
	}
	// [1, n]
	node query(int l, int r) {
		return query(1, 1, size - 1, l, r);
	}
};

main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string S;
	cin >> S;
	STregularBracket name(S);
	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		node ans = name.query(l, r);
		cout << ans.maxLen << endl;
	}
	cout << flush;
	return 0;
}
