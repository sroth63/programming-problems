#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int compare_function(const void *a,const void *b) {
    if (*(char*)a > *(char*)b) return 1;
    else return -1;
}

int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n-1);
}

int main(){
    char s[8];
    scanf("%s", s);

    int n = strlen(s);

    // count the number of distinct permutations
    int occ[26];
    for (int i = 0; i < 26; i++) { occ[i]=0; }
    for (int i = 0; i < n; i++) {
        occ[s[i]-'a']++;
    }
    int count = factorial(n);
    for (int i = 0; i < 26; i++) {
        count /= factorial(occ[i]);
    }
    printf("%d\n", count);

    // sort the string
    qsort(s, n, sizeof(s[0]), compare_function);

    // generate all distinct permutations
    // https://en.wikipedia.org/wiki/Permutation#Generation_in_lexicographic_order
    while (true) {
        printf("%s\n", s);

        int k = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] < s[i+1]) {k = i;}
        }
        if (k == -1) {return EXIT_SUCCESS;}

        int l = k + 1;
        for (int i = k+1; i < n; i++) {
            if (s[k] < s[i]) {l = i;}
        }

        char temp = s[k];
        s[k] = s[l];
        s[l] = temp;

        int i = k + 1;
        int j = n - 1;
        while (i<j) {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
    }

}
