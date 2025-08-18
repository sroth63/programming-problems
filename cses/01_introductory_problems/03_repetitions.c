#include <stdio.h>
#include <stdlib.h>

int main(){
    char sequence[1000000];
    scanf("%[^\n]s", sequence);
    int max = 1;
    int current = 1;
    int i = 1;
    while (sequence[i] != '\0'){
        if (sequence[i] == sequence[i-1]){
            current += 1;
            if (current > max) {
                max = current;
            }
        } else {
            current = 1;
        }
        i += 1;
    }
    printf("%d\n", max);
    return EXIT_SUCCESS;
}
