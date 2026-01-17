//busca la mitad de una matriz en orden asendente

main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n;
  //halla el numero media, tomando el entero siempre
  m = ((n * n) + 1) / 2;

  int l = 1, r = (n * n);
  while (l < r) {
    int mid, cont=0;
    mid = (l + r) / 2;
    //halla los numeros menores a x, los cuales si la cantidad de numeros menos es igual a m, significa que ese es el numero medio
    forne(i, 1, n) cont += min(n, mid / i);

    if (cont >= m) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << l << endl;

  return 0;
}
