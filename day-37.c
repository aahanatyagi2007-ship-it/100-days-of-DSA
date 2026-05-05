//Problem Statement: Implement a Priority Queue using an array. An element with smaller value has higher priority.
#include <stdio.h>
#define MAX 100

int pq[MAX];
int size = 0;

// Insert
void insert(int x) {
    if (size == MAX) return;
    pq[size++] = x;
}

// Find index of minimum element
int findMinIndex() {
    if (size == 0) return -1;

    int minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (pq[i] < pq[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

// Delete (remove min)
void deleteMin() {
    int index = findMinIndex();

    if (index == -1) {
        printf("-1\n");
        return;
    }

    printf("%d\n", pq[index]);

    // Shift elements left
    for (int i = index; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }
    size--;
}

// Peek (get min without deleting)
void peek() {
    int index = findMinIndex();

    if (index == -1) {
        printf("-1\n");
    } else {
        printf("%d\n", pq[index]);
    }
}

int main() {
    int N, x;
    char op[10];

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%s", op);

        if (op[0] == 'i') {  // insert
            scanf("%d", &x);
            insert(x);
        }
        else if (op[0] == 'd') {  // delete
            deleteMin();
        }
        else if (op[0] == 'p') {  // peek
            peek();
        }
    }

    return 0;
}
