#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    int t, n, a, b;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        scanf("%d %d %d", &n, &a, &b);
        if ((a>0 && b==0) || (a==0 && b>0) || (a+b>n)) {
            printf("NO\n");
        } else {
            printf("YES\n");
            for (int j=1; j<=n-a-b; j++) printf("%d ", j);
            for (int j=n-a+1; j<=n; j++) printf("%d ", j);
            for (int j=n-a-b+1; j<=n-a; j++) printf("%d ", j);
            printf("\n");
            for (int j=1; j<=n; j++) printf("%d ", j);
            printf("\n");
        }
    }

    return EXIT_SUCCESS;
}
