//Problem: Count Leaf NodesImplement the solution for this problem.
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

// Build tree
struct node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct node* root = createNode(arr[0]);
    enqueue(root);

    int i = 1;

    while (i < n) {
        struct node* current = dequeue();

        if (arr[i] != -1) {
            current->left = createNode(arr[i]);
            enqueue(current->left);
        }
        i++;

        if (i < n && arr[i] != -1) {
            current->right = createNode(arr[i]);
            enqueue(current->right);
        }
        i++;
    }

    return root;
}

// Count leaf nodes
int countLeaves(struct node* root) {
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    return countLeaves(root->left) + countLeaves(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[100];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct node* root = buildTree(arr, n);

    printf("%d", countLeaves(root));

    return 0;
}
