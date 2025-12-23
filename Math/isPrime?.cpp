//Detectar si un numero es primo o no

bool isPrime(long long x) {
    if (x < 2) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    for (long long i = 3; i * i <= x; i += 2) {
        if (x % i == 0)
            return false;
    }
    return true;
}

main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
   int t,n;
    cin >> t;
    while (t--) {
        cin >> n;
        if(isPrime(n)) cout<<"YES"<<endl;
        else  cout << "NO" << endl;

    }

  return 0;
}
