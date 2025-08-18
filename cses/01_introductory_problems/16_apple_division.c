#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int n;
int subset[20];
int subset_length = 0;
long long weights[20];
long long total_sum = 0;
long long min_diff = LLONG_MAX;

void subsets(int k) {
    if (k==n) {
        long long subset_sum = 0;
        for (int i = 0; i < subset_length; i++) {
            subset_sum += subset[i];
        }
        long long diff = llabs(total_sum - 2*subset_sum);
        if (diff < min_diff) min_diff = diff;
    } else {
        subsets(k+1);
        subset[subset_length++] = weights[k];
        subsets(k+1);
        subset_length--;
    }
}

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", weights+i);
        total_sum += weights[i];
    }
    subsets(0);
    printf("%lld\n", min_diff);
    return EXIT_SUCCESS;
}
