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

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, int node1, int node2) {
    if (root == NULL) {
        return NULL;
    }

    if (root->data == node1 || root->data == node2) {
        return root;
    }

    struct TreeNode* leftLCA = lowestCommonAncestor(root->left, node1, node2);
    struct TreeNode* rightLCA = lowestCommonAncestor(root->right, node1, node2);

    if (leftLCA != NULL && rightLCA != NULL) {
        return root;
    }

    return (leftLCA != NULL) ? leftLCA : rightLCA;
}

int main() {
    struct TreeNode* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);
    root->left->left = createNode(3);
    root->left->right = createNode(7);
    root->right->left = createNode(12);

    int node1 = 3;
    int node2 = 7;

    struct TreeNode* lca = lowestCommonAncestor(root, node1, node2);

    if (lca != NULL) {
        printf("Lowest Common Ancestor of %d and %d is: %d\n", node1, node2, lca->data);
    } else {
        printf("Lowest Common Ancestor of %d and %d not found\n", node1, node2);
    }

    return 0;
}
