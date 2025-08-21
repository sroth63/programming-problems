#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;

    long long sum = -1e9, best = -1e9;
    for (int i=0; i<n; i++) {
        long long x; cin >> x;
        sum = max(sum+x, x);
        best = max(best, sum);
    }

    cout << best << "\n";
}
