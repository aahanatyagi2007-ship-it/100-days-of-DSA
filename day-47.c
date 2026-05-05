//Problem: Height of Binary Tree

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
    if (val == -1) return NULL;

    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Queue for building tree
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
    if (n == 0 || arr[0] == -1) return NULL;

    struct node* root = createNode(arr[0]);
    enqueue(root);

    int i = 1;

    while (i < n) {
        struct node* current = dequeue();

        // Left child
        if (arr[i] != -1) {
            current->left = createNode(arr[i]);
            enqueue(current->left);
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            current->right = createNode(arr[i]);
            enqueue(current->right);
        }
        i++;
    }

    return root;
}

// Height function
int height(struct node* root) {
    if (root == NULL)
        return 0;

    int left = height(root->left);
    int right = height(root->right);

    return 1 + (left > right ? left : right);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[100];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct node* root = buildTree(arr, n);

    printf("%d", height(root));

    return 0;
}
