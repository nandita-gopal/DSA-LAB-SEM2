#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    int level; 
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->level = 0;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void rightViewUtil(struct TreeNode* root, int currentLevel, int* maxLevel) {
    if (root == NULL) {
        return;
    }

    if (currentLevel > *maxLevel) {
        printf("%d ", root->data);
        *maxLevel = currentLevel;
    }

    rightViewUtil(root->right, currentLevel + 1, maxLevel);
    rightViewUtil(root->left, currentLevel + 1, maxLevel);
}

void rightView(struct TreeNode* root) {
    int maxLevel = 0;
    rightViewUtil(root, 1, &maxLevel);
}

int main() {
    struct TreeNode* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);
    root->left->left = createNode(3);
    root->left->right = createNode(7);
    root->right->left = createNode(12);

    printf("Right View of Binary Tree: ");
    rightView(root);

    return 0;
}
