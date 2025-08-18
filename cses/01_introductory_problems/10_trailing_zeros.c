#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d", &n);

    int k = 5; int sum = 0;
    while (n / k != 0) {
        sum += n / k;
        k *= 5;
    }
    printf("%d\n", sum);

    return EXIT_SUCCESS;
}
