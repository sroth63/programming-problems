#include <stdio.h>
#include <stdlib.h>

void hanoi(int n, int a, int b) {
    if (n == 0) {return;}
    hanoi(n-1, a, 6-a-b);
    printf("%d %d\n", a, b);
    hanoi(n-1, 6-a-b, b);
}

int main(){
    int n;
    scanf("%d", &n);
    printf("%d\n", (1 << n) - 1);
    hanoi(n, 1, 3);
    return EXIT_SUCCESS;
}
