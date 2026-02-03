#include <stdio.h>

int main() {
    int n,target;
    printf("Enter number of elements: ");
    scanf("%d",&n);

    int nums[n];
    printf("num = ");
    for (int i=0 ; i<n ; i++) {
        scanf("%d",&nums[i]);
    }
    printf("Target = ");
    scanf("%d",&target);

    for (int i=0 ; i<(n-1) ; i++) {
        for (int j= i+1 ; j<n ; j++) {
            if (nums[i] + nums[j] == target) {
                printf("[%d,%d]",i,j);
                return 0;
            }
        }
    }
    return 0;
}
