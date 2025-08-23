#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<long long> value(x+1, LLONG_MAX);
    value[0] = 0;

    for (int i=0; i<n; i++) {
        int coin; cin >> coin;
        for (int i=coin; i<=x; i++) {
            if (value[i-coin] < LLONG_MAX && value[i-coin]+1 < value[i]) {
                value[i] = value[i-coin] + 1;
            }
        }
    }

    if (value[x] == LLONG_MAX) {
        cout << "-1\n";
    } else {
        cout << value[x] << "\n";
    }
}
