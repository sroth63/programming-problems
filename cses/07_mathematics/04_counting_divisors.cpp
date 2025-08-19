#include <iostream>
using namespace std;

int main() {
    int n, x, answer;
    cin >> n;
    for (int i=0; i<n; i++) {
        answer = 1;
        cin >> x;
        int y = x;
        for (int d = 2; d*d <= y; d++) {
            int v = 0;
            while (y % d == 0) {
                v += 1;
                y /= d;
            }
            answer *= v + 1;
        }
        // at this point, y has no factors between 2 and sqrt(y), so y = 1 or y is prime
        if (y > 1) {
            int v = 0;
            while (x % y == 0) {
                v += 1;
                x /= y;
            }
            answer /= v;
            answer *= v + 1;
        }
        cout << answer << "\n";
    }
}
