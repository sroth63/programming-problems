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
    vector<int> factorials(1e6+1);
    factorials[0] = 1;
    for (int i=1; i<=1e6; i++) {
        factorials[i] = ((long long) i * factorials[i-1]) % MOD;
    }

    int n;
    cin >> n;

    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        int coeff = factorials[a];
        coeff = ((long long) coeff * invmod(factorials[b], MOD)) % MOD;
        coeff = ((long long) coeff * invmod(factorials[a-b], MOD)) % MOD;
        cout << coeff << "\n";
    }
}
