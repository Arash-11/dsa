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

    Node* min = root;
    while (min->left != NULL)
        min = min->left;

    return min->data;
}

int get_max(Node* root) {
    if (root == NULL) return 0;

    Node* max = root;
    while (max->right != NULL)
        max = max->right;

    return max->data;
}

int get_height(Node* root) {
    if (root == NULL) return -1;

    int left_height = get_height(root->left);
    int right_height = get_height(root->right);

    int max_subtree_height = left_height >= right_height ? left_height : right_height;
    return max_subtree_height + 1;
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
    printf("search(20): %d\n", search(root, 20));
    printf("search(8): %d\n", search(root, 8));
    printf("search(0): %d\n", search(root, 0));
    printf("search(11): %d\n", search(root, 11));

    printf("\n");
    printf("get_min: %d\n", get_min(root));
    printf("get_max: %d\n", get_max(root));

    printf("\n");
    printf("get_height: %d\n", get_height(root));

    return 0;
}
