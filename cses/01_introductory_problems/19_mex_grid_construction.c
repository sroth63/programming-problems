#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    int n;
    scanf("%d", &n);
    int grid[100][100] = {{0}};

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            bool seen[200] = {false};
            for (int k=0; k<i; k++) seen[grid[k][j]] = true;
            for (int k=0; k<j; k++) seen[grid[i][k]] = true;
            while (seen[grid[i][j]]) grid[i][j]++;
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    return EXIT_SUCCESS;
}
