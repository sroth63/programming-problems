#include <stdio.h>
#include <stdlib.h>

long long pow2(int n, long long m) { // returns 2^n % m
    if (n == 0) { return 1; }
    long long a = pow2(n/2, m);
    if (n % 2 == 0) { return (a * a) % m; }
    else { return (2 * a * a) % m; }
}

int main(){
    int n;
    scanf("%d", &n);
    const long long m = 1000000007;
    printf("%lld\n", pow2(n, m));
    return EXIT_SUCCESS;
}
