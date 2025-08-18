#include <stdio.h>
#include <stdlib.h>

int main(){
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        long long a, b;
        scanf("%lld %lld", &a, &b);
        if (a <= 2 * b && b / 2 <= a && (a + b) % 3 == 0) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return EXIT_SUCCESS;
}
