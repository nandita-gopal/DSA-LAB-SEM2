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

struct TreeNode* constructTree(int preorder[], int* preIndex, int min, int max, int size) {
    if (*preIndex >= size) {
        return NULL;
    }

    struct TreeNode* root = NULL;
    int current = preorder[*preIndex];
    if (current > min && current < max) {
        root = createNode(current);
        (*preIndex)++;

        root->left = constructTree(preorder, preIndex, min, current, size);
        root->right = constructTree(preorder, preIndex, current, max, size);
    }

    return root;
}

void postorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    int preorder[] = {10, 5, 3, 7, 15, 12};
    int size = sizeof(preorder) / sizeof(preorder[0]);
    int preIndex = 0;

    struct TreeNode* root = constructTree(preorder, &preIndex, intmin, intmax,size);

    printf("Postorder Traversal of Constructed Binary Tree: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}
