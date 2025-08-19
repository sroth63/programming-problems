#include <iostream>
using namespace std;

const int MOD = 1000000007;

int modpow(int x, int n, int m) {
    if (n==0) return 1;
    long long u = modpow(x, n/2, m);
    u = (u * u) % m;
    if (n%2 == 1) u = (u * x) % m;
    return u;
}

int main() {
    int n, a, b, c;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a >> b >> c;
        int answer;
        if (a == 0 && b == 0 && c != 0) {
            answer = 1;
        } else if (a == 0) {
            answer = 0;
        } else {
            // MOD is prime so we can use Fermat's little theorem
            answer = modpow(a, modpow(b, c, MOD-1), MOD);
        }
        cout << answer << "\n";
    }
}
