#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, x; cin >> n >> x;
    vector<int> weights(n);
    for (int i=0; i<n; i++) cin >> weights[i];

    sort(weights.begin(), weights.end());

    int p1 = 0, p2 = n-1;
    int count = 0;

    while (p1 < p2) {
        if (weights[p1] + weights[p2] <= x) { // p1 and p2 are placed together
            p1++; p2--;
            count++;
        } else { // p2 is placed alone
            p2--;
            count++;
        }
    }

    if (p1 == p2) count++; // p1 is placed alone

    cout << count << "\n";
}
