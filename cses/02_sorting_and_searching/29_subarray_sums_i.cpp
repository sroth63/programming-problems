#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    int n, x; cin >> n >> x;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    set<long long> prefix_sums; prefix_sums.insert(0);
    long long current_sum = 0;
    int count = 0;

    for (int i=0; i<n; i++) {
        current_sum += a[i];
        if (prefix_sums.count(current_sum-x)) count++;
        prefix_sums.insert(current_sum);
    }

    cout << count << "\n";
}
