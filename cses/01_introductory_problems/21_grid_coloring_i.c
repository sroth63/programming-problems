#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    char grid[n][m];

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf(" %c", &grid[i][j]);
            for (char c = 'A'; c <= 'D'; c++) {
                if (grid[i][j]==c) continue;
                if (i>0 && grid[i-1][j]==c) continue;
                if (j>0 && grid[i][j-1]==c) continue;
                grid[i][j]=c;
                printf("%c", c);
                break;
            }
        }
        printf("\n");
    }

    return EXIT_SUCCESS;
}
