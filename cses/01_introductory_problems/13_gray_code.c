#include <stdio.h>
#include <stdlib.h>

char gray[(1 << 16) + 1][16 + 1];

char comp(char c) {
    switch (c) {
        case '0': return '1';
        case '1': return '0';
        default: return EXIT_FAILURE;
    }
}

void printGray(int length, int offset) {
    for (int i = 0; i < 1<< length; i++) {
        for (int j = 0; j < length; j++) {
            printf("%c", gray[offset+i][j]);
        }
        printf("\n");
    }
}

void grayCode(int length, int offset) {
    if (length == 0) {
        return;
    }
    grayCode(length-1, offset);
    int new_offset = offset + (1 << (length-1));
    for (int i = 0; i < new_offset; i++) {
        for (int j = 0; j < length-1; j++) {
            gray[new_offset+i][j] = gray[new_offset-1-i][j];
        }
    }
    for (int i = offset + 1; i < new_offset; i++) {
        gray[i][length-1] = gray[offset][length-1];
    }
    for (int i = new_offset; i < 2*new_offset; i++){
        gray[i][length-1] = comp(gray[offset][length-1]);
    }
}

int main(){
    int length;
    scanf("%d", &length);
    for (int i = 0; i < length; i++) {
        gray[0][i] = '0';
    }
    grayCode(length, 0);
    printGray(length, 0);

    return EXIT_SUCCESS;
}
