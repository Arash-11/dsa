#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* create_node(int data) {
    Node* new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert(Node** rootptr, int data) {
    if (*rootptr == NULL) {
        *rootptr = create_node(data);
        return;
    }

    if (data <= (*rootptr)->data) {
        insert(&((*rootptr)->left), data);
        return;
    }

    insert(&((*rootptr)->right), data);
}

bool search(Node* root, int data) {
    if (root == NULL) return false;

    if (data == root->data) return true;

    if (data < root->data)
        return search(root->left, data);

    return search(root->right, data);
}

int get_min(Node* root) {
    if (root == NULL) return 0;

    if (root->left == NULL)
        return root->data;

    return get_min(root->left);
}

int get_max(Node* root) {
    if (root == NULL) return 0;

    if (root->right == NULL)
        return root->data;

    return get_max(root->right);
}

int main() {
    Node* root = NULL; // create an empty tree

    insert(&root, 15);
    insert(&root, 10);
    insert(&root, 20);
    insert(&root, 25);
    insert(&root, 8);
    insert(&root, 12);

    printf("after insert..\n");
    printf("20: %d\n", search(root, 20));
    printf("8: %d\n", search(root, 8));
    printf("0: %d\n", search(root, 0));
    printf("11: %d\n", search(root, 11));

    printf("get_min: %d\n", get_min(root));
    printf("get_max: %d\n", get_max(root));

    return 0;
}
