#include <cstdlib>
#include <iostream>
using namespace std;

const int MOD = 1e9+7;

int modpow(int x, long long n) {
    if (n==0) return 1;
    long long u = modpow(x, n/2);
    u = (u * u) % MOD;
    if (n%2 == 1) u = (u * x) % MOD;
    return u;
}

int main() {
    long long n; cin >> n;

    if (n == 1) {
        cout << "2\n";
        return EXIT_SUCCESS;
    }

    long long count;

    // Burnside's formula
    if (n % 2 == 0) {
        count = (modpow(2, n*n-2) + modpow(2, n*n/2-2) + modpow(2, n*n/4-1)) % MOD;
    } else {
        count = (modpow(2, n*n-2) + modpow(2, (n*n-3)/2) + modpow(2, (n*n-1)/4)) % MOD;
    }

    cout << count << "\n";
}
