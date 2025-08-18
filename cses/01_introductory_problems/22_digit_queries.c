#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    int q; scanf("%d", &q);
    long long k;
    for (int i=0; i<q; i++) {
        scanf("%lld", &k);
        k--;
        // the corresponding number x is between a included and b excluded
        long long a = 1; long long b = 10;
        // the corresponding number x has c digits
        int c = 1;
        while (k >= (b-a) * c) {
            k -= (b-a) * c;
            a *= 10; b*= 10;
            c++;
        }
        long long x = a + k / c;
        char str[20];
        sprintf(str, "%lld", x);
        char digit = str[k % c];
        printf("%c\n", digit);
    }

    return EXIT_SUCCESS;
}
