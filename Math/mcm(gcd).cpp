//halla el minimo comun multiplo aplicando su respectiva formula
ll mcm(ll a, ll b) {
    return a / __gcd(a, b) * b;
}

//se aplica para hallar el minimo comun multiplo de los numeros de un vector
ll mcm_vector(const vector<ll> &v) {
    ll ans = v[0];
    forn(i, v.size()) {
        ans = mcm(ans, v[i]);
    }
    return ans;
}
