#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d", &n);
    long long a = 28ll;
    for (long long k = 1; k <= n; k++) {
        switch (k) {
            case 1: printf("0\n"); break;
            case 2: printf("6\n"); break;
            case 3: printf("28\n"); break;
            default:
                a += 2*k*k*k - 3*k*k - 7*k + 16;
                printf("%lld\n", a);
        }
    }

    return EXIT_SUCCESS;
}
