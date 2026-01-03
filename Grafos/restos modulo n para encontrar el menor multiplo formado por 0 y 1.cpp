/*
Se nos da un entero positivo n y debemos encontrar el menor multiplo de n cuyo numero decimal
este formado solo por los digitos 0 y 1
empiece con 1
y sea divisible exactamente por n

El problema no pide convertir a binario
el numero sigue siendo decimal solo que con digitos restringidos

El principal desafio es que el numero buscado puede tener muchisimos digitos por lo que no cabe
en ningun tipo numerico y no puede generarse directamente


En lugar de construir el numero completo se trabaja unicamente con su resto al dividirlo entre n
Esto es posible porque para cualquier numero solo existen n restos posibles 0 1 ... n menos 1
si conocemos el resto de un numero podemos calcular el resto del numero al agregar un digito

agregar 0 da resto igual a resto por 10 modulo n
agregar 1 da resto igual a resto por 10 mas 1 modulo n

Asi el problema se transforma en recorrer un grafo de restos
*/

constexpr int mxN = 1e5 + 100;
vector<int> G[mxN];
vector<bool> vis;
vector<int> parent;
vector<char> digit;

void bfs(int start) {
  queue<int> q;
  q.push(start);
  vis[start] = 1;
  digit[start] = '1';
  parent[start] = -1;

  while (!q.empty()) {
    int v = q.front();
    q.pop();

    if (v == 0)
      return;

    each(to, G[v]) {
      if (!vis[to]) {
        vis[to] = true;
        parent[to] = v;

        
        if ((v * 10) % sz(parent) == to)
          digit[to] = '0';
        else
          digit[to] = '1';

        q.push(to);
      }
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    forn(i, n) G[i].clear();

    vis.assign(n, false);
    parent.assign(n, -1);
    digit.assign(n, '?');

  
  forn(r, n) {
      G[r].pb((r * 10) % n);
      G[r].pb((r * 10 + 1) % n);
    }

    int start = 1 % n;
    bfs(start);

    string ans;
    for (int c = 0; c != -1; c = parent[c])
      ans.pb(digit[c]);

    reverse(all(ans));
    cout << ans << endl;
  }

  return 0;
}
