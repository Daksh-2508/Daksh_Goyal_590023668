#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int array[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    int min_sum = abs(array[0] + array[1]);
    int first = array[0], second = array[1];

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = array[i] + array[j];

            if (abs(sum) < min_sum) {
                min_sum = abs(sum);
                first = array[i];
                second = array[j];
            }
        }
    }

    printf("%d %d\n", first, second);

    return 0;
}
