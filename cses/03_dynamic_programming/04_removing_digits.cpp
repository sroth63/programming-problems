#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main() {
    int n; cin >> n;

    vector<long long> steps(n+1, LLONG_MAX);
    steps[0] = 0;

    for (int i=1; i<=n; i++) {
        long long new_val = LLONG_MAX;
        int j = i;
        while (j > 0) {
            if (i >= j%10) new_val = min(new_val, steps[i-(j%10)]);
            j /= 10;
        }
        steps[i] = new_val + 1;
    }

    cout << steps[n] << "\n";
}
