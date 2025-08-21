#include <cstdlib>
#include <iostream>
#include <vector>
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
    int n;
    cin >> n;

    if (n%2 == 1) {
        cout << "0\n";
        return EXIT_SUCCESS;
    }

    vector<int> factorials(1e6+1);
    factorials[0] = 1;
    for (int i=1; i<=1e6; i++) {
        factorials[i] = ((long long) i * factorials[i-1]) % MOD;
    }

    // we are looking for the n/2-th Catalan number
    long long count = factorials[n];
    count = (count * invmod(factorials[n/2], MOD)) % MOD;
    count = (count * invmod(factorials[n/2+1], MOD)) % MOD;

    cout << count << "\n";
}
