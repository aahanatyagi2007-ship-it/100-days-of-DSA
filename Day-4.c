// Problem: Given an array of n integers, reverse the array in-place using two-pointer approach.

#include <stdio.h>

void reverseArray(int arr[], int n) {
    int i = 0, j = n - 1;

    while(i < j) {
        // Swap
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;

        i++;
        j--;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    reverseArray(arr, n);

    printf("Reversed array:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
