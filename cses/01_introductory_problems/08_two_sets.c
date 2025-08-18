#include <stdio.h>
#include <stdlib.h>

void print_array(int *arr, int len) {
    printf("%d\n", len);
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int n;
    scanf("%d", &n);

    if (n % 4 == 1 || n % 4 == 2) {
        printf("NO\n");
        return EXIT_SUCCESS;
    }

    int A[n];
    int B[n];
    int A_len = 0;
    int B_len = 0;
    int start = 1;

    if (n % 4 == 3) {
        A[A_len++] = 1;
        A[A_len++] = 2;
        B[B_len++] = 3;
        start = 4;
    }

    for (int i = start; i <= n; i += 4) {
        A[A_len++] = i;
        A[A_len++] = i+3;
        B[B_len++] = i+1;
        B[B_len++] = i+2;
    }
    printf("YES\n");
    print_array(A, A_len);
    print_array(B, B_len);

    return EXIT_SUCCESS;
}
