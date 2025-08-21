#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9+7;

int main() {
    int n; cin >> n;
    vector<int> perm(n);
    for (int i=0; i<n; i++) {
        cin >> perm[i];
        perm[i]--; // index everything starting at 0
    }

    vector<int> max_val(n+1);

    vector<bool> visited(n, false);
    for (int i=0; i<n; i++) {
        if (visited[i]) continue;
        if (perm[i] == i) continue;
        int current = i;
        int cycle_order = 0;
        while (!visited[current]) {
            visited[current] = true;
            current = perm[current];
            cycle_order++;
        }

        for (int d = 2; d*d <= cycle_order; d++) {
            int val = 0;
            while (cycle_order % d == 0) {
                cycle_order /= d;
                val++;
            }
            max_val[d] = max(max_val[d], val);
        }
        // either the initial cycle_order is prime or the current cycle_order equals 1
        if (max_val[cycle_order] == 0) max_val[cycle_order] = 1;
    }

    long long order = 1;
    for (int x = 2; x <= n; x++) {
        for (int i = 0; i < max_val[x]; i++) order = (order * x) % MOD;
    }
    cout << order << "\n";
}
