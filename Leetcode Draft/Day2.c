/*You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.*/

#include <stdio.h>

int main() {
    int n;
    scanf("%d",&n);

    int array[n];
    for (int i=0 ; i<n ; i++) {
        scanf("%d",&array[i]);
    }
    int profit = 0;
    for (int i=0 ; i<n-1 ; i++) {
        for (int j=i+1 ; j<n ; j++) {
            if ((array[j]-array[i]) > profit ) {
                profit = array[j]-array[i];
            }
        }
    }
    printf("%d",profit);
    return 0;
}
