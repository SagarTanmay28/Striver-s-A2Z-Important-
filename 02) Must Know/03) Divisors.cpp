int countDivisors(int n) {
    int cnt = 0;
    for (int i = 1; i * 1LL * i <= n; i++) {
        if (n % i == 0) {
            cnt++;
            if (i != n / i) cnt++;
        }
    }
    return cnt;
}
