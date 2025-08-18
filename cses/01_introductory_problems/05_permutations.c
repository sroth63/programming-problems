#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d", &n);

    if (n == 2 || n == 3) {
        printf("NO SOLUTION\n");
    } else if (n == 4) {
        printf("2 4 1 3\n");
    } else {
        for (int i = 1; i <= n; i += 2) {
            printf("%d ", i);
        }
        for (int i = 2; i <= n; i += 2) {
            printf("%d ", i);
        }
    }

    return EXIT_SUCCESS;
}
