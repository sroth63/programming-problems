#include <iostream>
using namespace std;

const int MOD = 1000000007;

int modpow(int x, int n) {
    if (n==0) return 1;
    long long u = modpow(x, n/2);
    u = (u * u) % MOD;
    if (n%2 == 1) u = (u * x) % MOD;
    return u;
}

int main() {
    int n, a, b;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a >> b;
        cout << modpow(a, b) << "\n";
    }
}
