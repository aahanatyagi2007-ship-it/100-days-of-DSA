//Problem: Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

struct node {
    int coeff;
    int exp;
    struct node* next;
};

// Function to create a new node
struct node* createNode(int c, int e) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
struct node* insert(struct node* head, int c, int e) {
    struct node* temp = createNode(c, e);

    if (head == NULL) {
        return temp;
    }

    struct node* ptr = head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = temp;

    return head;
}

// Display polynomial
void display(struct node* head) {
    struct node* ptr = head;

    while (ptr != NULL) {
        if (ptr->exp == 0)
            printf("%d", ptr->coeff);
        else if (ptr->exp == 1)
            printf("%dx", ptr->coeff);
        else
            printf("%dx^%d", ptr->coeff, ptr->exp);

        if (ptr->next != NULL)
            printf(" + ");

        ptr = ptr->next;
    }
}

int main() {
    int n, c, e;
    struct node* head = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &c, &e);
        head = insert(head, c, e);
    }

    display(head);

    return 0;
}
