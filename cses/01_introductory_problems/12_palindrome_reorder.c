#include <stdio.h>
#include <stdlib.h>

int main(){
    char s[1000000];
    scanf("%[^\n]s", s);

    int occ[26];
    for (int i = 0; i < 26; i++) { occ[i] = 0; }
    int s_len = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        occ[s[i]-65] += 1;
        s_len++;
    }

    char pal[s_len];
    int pal_len = 0;
    char mid = '0';
    for (int i = 0; i < 26; i++) {
        if (occ[i] % 2 == 1) {
            if (mid != '0') {
                printf("NO SOLUTION\n");
                return EXIT_SUCCESS;
            }
            mid = i+65;
        }
        for (int j = 0; j < occ[i]/2; j++) {
            pal[pal_len++] = i+65;
        }
    }

    if (mid != '0') { pal[pal_len++] = mid; }
    for (int i = s_len/2 - 1; i >= 0; i--) {
        pal[pal_len++] = pal[i];
    }
    pal[pal_len++] = '\0';
    printf("%s\n",pal);
    return EXIT_SUCCESS;
}
