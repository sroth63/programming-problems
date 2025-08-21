#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    map<int, int> values;

    for (int i=0; i<n; i++) {
        if (values.count(x-a[i])) {
            cout << i + 1 << " " << values[x-a[i]] + 1 << "\n";
            return EXIT_SUCCESS;
        }
        values[a[i]] = i;
    }

    cout << "IMPOSSIBLE\n";
}
