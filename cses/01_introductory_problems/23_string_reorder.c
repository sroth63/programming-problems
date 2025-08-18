#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    char string[1000000];
    scanf("%s", string);

    int occ[26];
    int length = 0;
    int max_occ = 0;
    char char_max_occ;
    while (string[length] != '\0') {
        occ[string[length]-'A']++;
        if (occ[string[length]-'A'] > max_occ) {
            max_occ = occ[string[length]-'A'];
            char_max_occ = string[length];
        }
        length++;
    }

    char answer[length+1];
    int len_ans = 0;

    while (max_occ > 0) {
        if (length % 2 == 1 && max_occ == (length+1)/2) {
            for (int i=0; i<length; i++) {
                if (i%2 == 0) {
                    answer[len_ans++] = char_max_occ;
                } else {
                    int j = 0;
                    while (occ[j] == 0 || j == char_max_occ - 'A') j++;
                    answer[len_ans++] = 'A' + (char) j;
                    occ[j]--;
                }
            }
            break;
        }

        else if (max_occ >= length/2 + 1) {
            printf("-1\n");
            return EXIT_SUCCESS;
        }

        else {
            int j = 0;
            while (occ[j] == 0 || (len_ans > 0 && j == answer[len_ans-1] - 'A')) j++;
            answer[len_ans++] = 'A' + (char) j;
            occ[j]--;
            length--;
            if ('A' + (char) j == char_max_occ) {
                max_occ--;
                for (int k=0; k<26; k++) {
                    if (occ[k] > max_occ) {
                        max_occ = occ[k];
                        char_max_occ = (char) k + 'A';
                    }
                }
            }
        }
    }

    for (int i = 0; i < len_ans ; i++) {
        printf("%c", answer[i]);
    }
    printf("\n");

    return EXIT_SUCCESS;
}
