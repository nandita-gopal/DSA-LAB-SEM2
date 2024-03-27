#include <stdio.h>
#include <stdlib.h>
#define intmin 0
#define intmax 100

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

struct TreeNode* constructTree(int postorder[], int* postIndex, int min, int max, int size) {
    
    if (*postIndex < 0) {
        return NULL;
    }

    struct TreeNode* root = NULL;
    int current = postorder[*postIndex];
    if (current > min && current < max) {
        root = createNode(current);
        (*postIndex)--;

        root->right = constructTree(postorder, postIndex, current, max, size);
        root->left = constructTree(postorder, postIndex, min, current, size);
    }

    return root;
}

void preorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

int main() {
    int postorder[] = {3, 7, 5, 12, 15, 10};
    int size = sizeof(postorder) / sizeof(postorder[0]);
    int postIndex = size - 1;

    struct TreeNode* root = constructTree(postorder, &postIndex, intmin, intmax, size);

    printf("Preorder Traversal of Constructed Binary Tree: ");
    preorderTraversal(root);
    printf("\n");

    return 0;
}
