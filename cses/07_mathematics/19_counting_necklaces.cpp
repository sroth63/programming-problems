#include <cstdlib>
#include <iostream>
#include <numeric>
#include <assert.h>
using namespace std;

const int MOD = 1e9+7;

int modpow(int x, int n, int m) {
    if (n==0) return 1;
    long long u = modpow(x, n/2, m);
    u = (u * u) % m;
    if (n%2 == 1) u = (u * x) % m;
    return u;
}

int invmod(int x, int m) { // m has to be prime
    assert (x % MOD != 0);
    return modpow(x, m-2, m);
}

int main() {
    int n, m;
    cin >> n >> m;

    long long count = 0;

    for (int i=0; i<n; i++) {
        count += modpow(m, gcd(i, n), MOD);
        count %= MOD;
    }

    count *= invmod(n, MOD);
    count %= MOD;

    cout << count << "\n";
}
