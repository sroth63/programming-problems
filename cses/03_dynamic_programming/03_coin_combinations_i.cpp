#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int main() {
    int n, x; cin >> n >> x;
    vector<int> coins(n);
    for (int i=0; i<n; i++) cin >> coins[i];

    vector<long long> count(x+1, 0);
    count[0] = 1;

    for (int i=1; i<=x; i++) {
        for (int c: coins) {
            if (i >= c) {
                count[i] = (count[i-c] + count[i]) % MOD;
            }
        }
    }

    cout << count[x] << "\n";
}
