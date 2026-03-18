// A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. Your task is to create a single chronological log that preserves the correct order of arrivals.

#include <stdio.h>

void mergeLogs(int log1[], int n1, int log2[], int n2, int merged[]) {
    int i = 0, j = 0, k = 0;

    // Compare elements and merge
    while (i < n1 && j < n2) {
        if (log1[i] <= log2[j]) {
            merged[k++] = log1[i++];
        } else {
            merged[k++] = log2[j++];
        }
    }

    // Copy remaining elements of log1
    while (i < n1) {
        merged[k++] = log1[i++];
    }

    // Copy remaining elements of log2
    while (j < n2) {
        merged[k++] = log2[j++];
    }
}

int main() {
    int log1[] = {1, 3, 5, 7};
    int log2[] = {2, 4, 6, 8};

    int n1 = 4, n2 = 4;
    int merged[8];

    mergeLogs(log1, n1, log2, n2, merged);

    printf("Merged Log: ");
    for (int i = 0; i < n1 + n2; i++) {
        printf("%d ", merged[i]);
    }

    return 0;
}
