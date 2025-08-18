#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char board[8][8];
int perm[8];
int perm_len = 0;
int count = 0;
bool chosen[8] = {false};

int valid_perm(void) {
    for (int i = 0; i < 8; i++) {
        if (board[i][perm[i]] == '*') return 0;
    }
    for (int i = 0; i < 8; i++) {
        for (int j = i+1; j < 8; j++) {
            // check if the queen on lign i attacks the queen on lign j
            if (perm[i]+j-i == perm[j] || perm[i]+i-j == perm[j]) return 0;
        }
    }
    return 1;
}

void perm_search(void) {
    if (perm_len == 8) {
        count += valid_perm();
    } else {
        for (int i = 0; i < 8; i++) {
            if (chosen[i]) continue;
            chosen[i] = true;
            perm[perm_len++] = i;
            perm_search();
            chosen[i]=false;
            perm_len--;
        }
    }
}

int main(){
    for (int i=0;i<8;i++) {
        for (int j=0;j<8;j++) {
            scanf(" %c", &(board[i][j]));
        }
    }

    perm_search();
    printf("%d\n", count);
    return EXIT_SUCCESS;
}
