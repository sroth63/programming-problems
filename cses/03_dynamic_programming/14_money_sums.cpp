#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> values(n);
    for (int i=0; i<n; i++) cin >> values[i];

    int S = accumulate(values.begin(), values.end(), 0);
    vector<bool> possible(S+1, false);
    possible[0] = true;

    int count = 0;

    for (int i=0; i<n; i++) {
        for (int x=S-values[i]; x>=0; x--) {
            if (possible[x] && !possible[x+values[i]]) {
                possible[x+values[i]] = true;
                count ++;
            }
        }
    }

    cout << count << "\n";
    for (int x=1; x<=S; x++) {
        if (possible[x]) cout << x << " ";
    }
    cout << "\n";
}
