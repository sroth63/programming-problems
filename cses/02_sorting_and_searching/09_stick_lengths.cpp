#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> p(n);
    for (int i=0; i<n; i++) cin >> p[i];

    sort(p.begin(), p.end());
    int median = p[n/2];

    long long total = 0;
    for (int i=0; i<n; i++) total += abs(p[i] - median);
    cout << total << "\n";
}
