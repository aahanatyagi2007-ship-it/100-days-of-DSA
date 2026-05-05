//Problem: Deque (Double-Ended Queue) A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack. Common Operations: 1. push_front(value): Insert an element at the front of the deque. 2. push_back(value): Insert an element at the rear of the deque. 3. pop_front(): Remove an element from the front of the deque. 4. pop_back(): Remove an element from the rear of the deque. 5. front(): Return the front element of the deque. 6. back(): Return the rear element of the deque. 7. empty(): Check whether the deque is empty. 8. size(): Return the number of elements in the deque.
#include <stdio.h>
#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

// Check empty
int empty() {
    return (front == -1);
}

// Push front
void push_front(int val) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Overflow\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    }
    else if (front == 0) {
        front = MAX - 1;
    }
    else {
        front--;
    }

    deque[front] = val;
}

// Push back
void push_back(int val) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Overflow\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    }
    else if (rear == MAX - 1) {
        rear = 0;
    }
    else {
        rear++;
    }

    deque[rear] = val;
}

// Pop front
void pop_front() {
    if (empty()) {
        printf("Underflow\n");
        return;
    }

    printf("%d\n", deque[front]);

    if (front == rear) {
        front = rear = -1;
    }
    else if (front == MAX - 1) {
        front = 0;
    }
    else {
        front++;
    }
}

// Pop back
void pop_back() {
    if (empty()) {
        printf("Underflow\n");
        return;
    }

    printf("%d\n", deque[rear]);

    if (front == rear) {
        front = rear = -1;
    }
    else if (rear == 0) {
        rear = MAX - 1;
    }
    else {
        rear--;
    }
}

// Display
void display() {
    if (empty()) return;

    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    // Example usage
    push_back(10);
    push_back(20);
    push_front(5);
    push_back(30);

    display();     // 5 10 20 30

    pop_front();   // 5
    pop_back();    // 30

    display();     // 10 20

    return 0;
}
