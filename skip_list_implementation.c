#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#define MAXIMUM_LEVEL 7

typedef struct Node {
    int key;
    int value;
    struct Node *forward[MAXIMUM_LEVEL + 1];
} Node;

typedef struct SkipList {
    int level;
    int size;
    Node *head;
} SkipList;

Node *newNode(int level, int key, int value) {
    Node *node = malloc(sizeof(Node));
    if (node == NULL) {
        fprintf(stderr, "Out of memory\n");
        exit(1);
    }
    node->key = key;
    node->value = value;
    for (int i = 0; i <= level; i++) {
        node->forward[i] = NULL;
    }
    return node;
}

SkipList *newSkipList() {
    SkipList *list = malloc(sizeof(SkipList));
    if (list == NULL) {
        fprintf(stderr, "Out of memory\n");
        exit(1);
    }
    list->level = 0;
    list->size = 0;
    list->head = newNode(MAXIMUM_LEVEL, INT_MIN, INT_MIN);
    return list;
}

int rand_level() {
    int level = 0;
    while (rand() < RAND_MAX / 2 && level < MAXIMUM_LEVEL) {
        level++;
    }
    return level;
}

void insert(SkipList *list, int key, int value) {
    Node *update[MAXIMUM_LEVEL + 1];
    Node *current = list->head;

    for (int i = list->level; i >= 0; i--) {
        while (current->forward[i] != NULL && current->forward[i]->key < key) {
            current = current->forward[i];
        }
        update[i] = current;
    }
    current = current->forward[0];

    if (current != NULL && current->key == key) {
        current->value = value;
        return;
    }

    int level = rand_level();

    if (level > list->level) {
        for (int i = list->level + 1; i <= level; i++) {
            update[i] = list->head;
        }
        list->level = level;
    }

    Node *node = newNode(level, key, value);

    for (int i = 0; i <= level; i++) {
        node->forward[i] = update[i]->forward[i];
        update[i]->forward[i] = node;
    }
    list->size++;
}

int searchList(SkipList *list, int key) {
    Node *current = list->head;
    for (int i = list->level; i >= 0; i--) {
        while (current->forward[i] != NULL && current->forward[i]->key < key) {
            current = current->forward[i];
        }
    }
    current = current->forward[0];
    if (current != NULL && current->key == key) {
        return current->value;
    }
    return INT_MIN;
}

int size(SkipList *list) {
    return list->size;
}

int checkIfEmpty(SkipList *list) {
    return size(list) == 0;
}

int main() {
    SkipList *list = newSkipList();

    insert(list, 1, 56);
    insert(list, 2, 48);
    insert(list, 3, 29);
    insert(list, 4, 83);
    insert(list, 5, 77);
    insert(list, 6, 23);
    insert(list, 7, 18);

    int key = 7;

    int value = searchList(list, key);

    if (value != INT_MIN) {
        printf("Key %d contains the value %d\n", key, value);
    } else {
        printf("Key %d was not found\n", key);
    }

    return 0;
}
