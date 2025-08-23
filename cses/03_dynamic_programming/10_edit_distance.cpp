#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b; cin >> a >> b;
    int n = a.length(), m = b.length();
    vector<vector<long long>> distance(m+1, vector<long long>(n+1));
    for (int j=0; j<=n; j++) distance[0][j] = j;

    for (int i=1; i<=m; i++) {
        distance[i][0] = i;
        for (int j=1; j<=n; j++) {
            int cost = (b[i-1] == a[j-1]) ? 0 : 1;
            distance[i][j] = min(distance[i][j-1]+1, min(distance[i-1][j]+1, distance[i-1][j-1] + cost));
        }
    }

    cout << distance[m][n] << "\n";
}
