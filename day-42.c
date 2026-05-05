//Problem Statement:Given a queue of integers, reverse the queue using a stack.
#include <stdio.h>
#define MAX 100

int queue[MAX], stack[MAX];
int front = 0, rear = -1;
int top = -1;

// Enqueue
void enqueue(int val) {
    queue[++rear] = val;
}

// Dequeue
int dequeue() {
    return queue[front++];
}

// Push
void push(int val) {
    stack[++top] = val;
}

// Pop
int pop() {
    return stack[top--];
}

// Reverse Queue
void reverseQueue() {
    // Step 1: Queue → Stack
    while (front <= rear) {
        push(dequeue());
    }

    // Reset queue
    front = 0;
    rear = -1;

    // Step 2: Stack → Queue
    while (top != -1) {
        enqueue(pop());
    }
}

// Display
void display() {
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    reverseQueue();

    display();

    return 0;
}
