//Problem: Level Order Traversal

//Implement the solution for this problem.

//Input:
//- Input specifications

//Output:
//- Output specifications
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Create node
struct node* createNode(int val) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Queue for nodes
struct node* queue[100];
int front = 0, rear = -1;

void enqueue(struct node* temp) {
    queue[++rear] = temp;
}

struct node* dequeue() {
    return queue[front++];
}

// Level Order Traversal
void levelOrder(struct node* root) {
    if (root == NULL) return;

    enqueue(root);

    while (front <= rear) {
        struct node* current = dequeue();
        printf("%d ", current->data);

        if (current->left != NULL)
            enqueue(current->left);

        if (current->right != NULL)
            enqueue(current->right);
    }
}

int main() {
    // Example tree
    struct node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    levelOrder(root);

    return 0;
}
