#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

node *root = NULL;

void createTree(int data) {
    node *tempA = (node *)malloc(sizeof(node));
    tempA->data = data;
    tempA->left = NULL;
    tempA->right = NULL;
    if (root == NULL) {
        root = tempA;
    } else {
        node *tempB = root;
        while(1) {
            if (data < tempB->data) {
                if (tempB->left == NULL) {
                    tempB->left = tempA;
                    break;
                } else {
                    tempB = tempB->left;
                }
            } else {
                if (tempB->right == NULL) {
                    tempB->right = tempA;
                    break;
                } else {
                    tempB = tempB->right;
                }
            }
        }
    }
}


void printTree(node *temp) {
    if (temp != NULL) {
        printTree(temp->left);
        printf("%d ", temp->data);
        printTree(temp->right);
    }
}

int main() {
    int arr[] = {34, 76, 1, 9, 8, 1002, 42, 723, 80};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++) {
        createTree(arr[i]);
    }
    printTree(root);
    return 0;
}
