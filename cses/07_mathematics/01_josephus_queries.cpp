#include <iostream>
using namespace std;

// position of the k-th child that will be removed
int u(int n, int k) {
    if (n == 1) return 1;
    if (k <= n/2) return 2*k;
    if (n%2 == 0) return 2 * u(n/2, k-n/2) - 1;
    int pos = 2 * u((n+1)/2, k-n/2) - 3;
    if (pos == -1) return n;
    return pos;
}

int main() {
    int q, k, n; cin >> q;
    for (int i=0; i<q; i++) {
        cin >> n >> k;
        cout << u(n,k) << "\n";
    }
}
