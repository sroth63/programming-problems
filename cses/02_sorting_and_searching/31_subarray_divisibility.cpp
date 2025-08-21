#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    map<int, int> sums;
    sums[0] = 1;
    long long count = 0, prefix_sum = 0;

    for (int i=0; i<n; i++) {
        prefix_sum = (prefix_sum + a[i]) % n;
        if (prefix_sum < 0) prefix_sum += n;
        if (sums.count(prefix_sum)) {
            count += sums[prefix_sum];
            sums[prefix_sum]++;
        } else {
            sums[prefix_sum] = 1;
        }
    }

    cout << count << "\n";
}
