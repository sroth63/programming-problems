#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<m; i++) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int p1 = 0, p2 = 0, count = 0;
    while (p1 < n && p2 < m) {
        if (a[p1]-k <= b[p2] && b[p2]<=a[p1]+k) {
            p1++; p2++; count++;
        } else if (a[p1]-k > b[p2]) {
            p2++;
        } else {
            p1++;
        }
    }

    cout << count << "\n";
}
