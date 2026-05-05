//Problem Statement: Implement a Min Heap using an array where the smallest element is always at the root.
#include <stdio.h>
#define MAX 100

int heap[MAX];
int size = 0;

// Swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify Up (for insert)
void heapifyUp(int i) {
    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Insert
void insert(int val) {
    if (size == MAX) return;

    heap[size] = val;
    heapifyUp(size);
    size++;
}

// Heapify Down (for delete)
void heapifyDown(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;

    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

// Delete Min
void deleteMin() {
    if (size == 0) {
        printf("Heap is empty\n");
        return;
    }

    printf("%d\n", heap[0]); // print min

    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
}

// Display
void display() {
    for (int i = 0; i < size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main() {
    insert(30);
    insert(10);
    insert(20);
    insert(5);

    display();     // heap array

    deleteMin();   // remove smallest
    display();

    return 0;
}
