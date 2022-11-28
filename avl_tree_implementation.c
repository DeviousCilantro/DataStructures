#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    int height;
    struct Node *left;
    struct Node *right;
} Node;

int height(Node *node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

int balance_factor(Node *node) {
    if (node == NULL) {
        return 0;
    }
    return height(node->left) - height(node->right);
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

Node *newNode(int data) {
    Node *node = malloc(sizeof(Node));
    if (node == NULL) {
        fprintf(stderr, "Error: out of memory\n");
        exit(1);
    }
    
    node->data = data;
    node->height = 1;  
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node *rotate_left(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

Node *rotate_right(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node *search(Node *node, int key) {
    if (node == NULL) {
        return NULL;
    }
    if (key == node->data) {
        return node;
    }
    if (key < node->data) {
        return search(node->left, key);
    }
    return search(node->right, key);
}

Node *insert(Node *node, int key) {
    if (node == NULL) {
        return newNode(key);
    }
    if (key < node->data) {
        node->left = insert(node->left, key);
    } 
    else if (key > node->data) {
        node->right = insert(node->right, key);
    } 
    else {
        printf("Dplicates not allowed\n");
        exit(1);
    }

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = balance_factor(node);

    if (balance > 1 && key < node->left->data) {
        return rotate_right(node);
    }

    if (balance < -1 && key > node->right->data) {
        return rotate_left(node);
    }

    if (balance > 1 && key > node->left->data) {
        node->left = rotate_left(node->left);
        return rotate_right(node);
    }

    if (balance < -1 && key < node->right->data) {
        node->right = rotate_right(node->right);
        return rotate_left(node);
    }

    return node;
}

void display(Node *node) {
    if (node == NULL) {
        return;
    }
    display(node->left);
    printf("%d ", node->data);
    display(node->right);
}

int main() {
    Node *root = NULL;

    while (1) {
        int key;
        printf("Enter value to be inserted into AVL tree, -1 stops reading input: ");
        scanf("%d", &key);
        if (key == -1) {
            break;
        }
        root = insert(root, key);
    }

    printf("\nAVL tree: ");
    display(root);
    printf("\n");

    int key;
    printf("\nEnter value to be searched for: ");
    scanf("%d", &key);

    Node *result = search(root, key);
    if (result != NULL) {
        printf("%d found\n", result->data);
    } 
    else {
        printf("Value not found\n");
    }

    return 0;
}
