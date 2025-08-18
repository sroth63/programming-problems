#include <stdio.h>
#include <stdlib.h>

int main(){
    int t;
    scanf("%d", &t);

    long long x, y;
    for (int i = 0; i < t; i++) {
        scanf("%lld %lld", &y, &x);
        if (x <= y) {
            if (y%2 == 0) {
                printf("%lld\n", y * y - x + 1);
            } else {
                printf("%lld\n", (y - 1) * (y - 1) + x);
            }
        } else {
            if (x%2 == 0) {
                printf("%lld\n", (x - 1) * (x - 1) + y);
            } else {
                printf("%lld\n", x * x - y + 1);
            }
        }
    }

    return EXIT_SUCCESS;
}
