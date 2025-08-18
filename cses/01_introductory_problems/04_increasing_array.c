#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d", &n);

    long long moves = 0;
    int last;
    int current;
    scanf("%d", &last);
    for (int i = 1; i<n; i++){
        scanf("%d", &current);
        if (current < last){
            moves += last - current;
        } else{
            last = current;
        }
    }
    printf("%lld\n", moves);
    return EXIT_SUCCESS;
}
