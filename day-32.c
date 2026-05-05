//Problem: Implement push and pop operations on a stack and verify stack operations.


#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

// Push function
void push(int val) {
    if (top == MAX - 1) {
        return;
    }
    stack[++top] = val;
}

// Pop function
void pop() {
    if (top == -1) {
        return;
    }
    top--;
}

// Display stack
void display() {
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
}

int main() {
    int n, m, val;

    scanf("%d", &n);

    // Push n elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        push(val);
    }

    // Number of pops
    scanf("%d", &m);

    // Perform m pops
    for (int i = 0; i < m; i++) {
        pop();
    }

    // Display remaining stack
    display();

    return 0;
}
