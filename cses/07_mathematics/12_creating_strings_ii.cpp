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

    string s; cin >> s;
    int length = 0;
    vector<int> occ(26,0);
    for (char c: s) {
        occ[c-'a']++;
        length++;
    }

    int count = factorials[length];
    for (int i=0; i<26; i++) {
        count = ((long long) count * invmod(factorials[occ[i]], MOD)) % MOD;
    }
    cout << count << "\n";
}
