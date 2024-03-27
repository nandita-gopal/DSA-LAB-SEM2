#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode* insertNode(struct TreeNode* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    } else if (data <= root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

int height(struct TreeNode* root) {
    if (root == NULL) {
        return -1; 
    } else {
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        
        return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
    }
}

int main() {
    struct TreeNode* root = NULL;

    root = insertNode(root, 10);
    root = insertNode(root, 5);
    root = insertNode(root, 15);
    root = insertNode(root, 7);
    root = insertNode(root, 3);
    root = insertNode(root, 12);

    int treeHeight = height(root);
    printf("Height of the binary tree: %d\n", treeHeight);

    return 0;
}
