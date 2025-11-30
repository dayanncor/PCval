

long long cont_divisors(long long x) {
    long long ans = 1;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            int cnt = 0;
            while (x % i == 0) {
                x /= i;
                cnt++;
            }
            ans *= (cnt + 1);
        }
    }
    if (x > 1) ans *= 2;

    return ans;
}
