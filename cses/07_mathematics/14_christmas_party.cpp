#include <iostream>
using namespace std;

const int MOD = 1e9+7;

int derangement_count(int n) {
    if (n<=2) return n-1;
    int a = 0; int b = 1;
    int temp;
    for (int i=3; i<=n; i++) {
        temp = b;
        b = ((long long)(i-1) * (a+b)) % MOD;
        a = temp;
    }
    return b;
}

int main() {
    int n; cin >> n;
    cout << derangement_count(n) << "\n";
}
