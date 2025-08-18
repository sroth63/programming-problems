#include <stdio.h>
#include <stdlib.h>

int main(){
    long long n;
    scanf("%lld", &n);

    long long sum = 0;
    int current;
    for (int i = 1; i<n; i++) {
        scanf("%d", &current);
        sum += current;
    }
    printf("%lld\n", (n * (n+1))/2 - sum);
    return EXIT_SUCCESS;
}
