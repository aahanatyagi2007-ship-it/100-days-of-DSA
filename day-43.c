//Problem Statement:Construct a Binary Tree from the given level-order traversal.
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

// Queue for tree nodes
struct node* queue[100];
int front = 0, rear = -1;

void enqueue(struct node* temp) {
    queue[++rear] = temp;
}

struct node* dequeue() {
    return queue[front++];
}

// Build tree from level order
struct node* buildTree(int arr[], int n) {
    if (n == 0) return NULL;

    struct node* root = createNode(arr[0]);
    enqueue(root);

    int i = 1;

    while (i < n) {
        struct node* current = dequeue();

        // Left child
        current->left = createNode(arr[i++]);
        enqueue(current->left);

        if (i < n) {
            // Right child
            current->right = createNode(arr[i++]);
            enqueue(current->right);
        }
    }

    return root;
}

// Inorder traversal (to verify)
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    int arr[] = {1,2,3,4,5,6,7};
    int n = 7;

    struct node* root = buildTree(arr, n);

    inorder(root);  // check tree

    return 0;
}
