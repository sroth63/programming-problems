#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int main() {
    int n; cin >> n;

    if (n <= 6) {
        cout << (1 << (n-1)) % MOD << "\n";
        return EXIT_SUCCESS;
    }

    deque<long long> window;
    for (int i=0; i<6; i++) window.push_back(1 << i);
    long long window_sum = accumulate(window.begin(), window.end(), 0);

    for (int i=0; i<n-6; i++) {
        window.push_back(window_sum % MOD);
        window_sum = ((2*window_sum - window[0]) % MOD + MOD) % MOD;
        window.pop_front();
    }

    cout << window[5] % MOD << "\n";
}
