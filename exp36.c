#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    int hd; 
    struct TreeNode* left;
    struct TreeNode* right;
};

struct QueueNode {
    struct TreeNode* treeNode;
    int hd;
    int next;
};

struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->hd = 0;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void enqueue(struct QueueNode** queue, struct TreeNode* treeNode, int hd) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->treeNode = treeNode;
    newNode->hd = hd;
    newNode->next = NULL;

    if (*queue == NULL) {
        *queue = newNode;
    } else {
        struct QueueNode* temp = *queue;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

struct QueueNode* dequeue(struct QueueNode** queue) {
    if (*queue == NULL) {
        return NULL;
    } else {
        struct QueueNode* temp = *queue;
        *queue = (*queue)->next;
        return temp;
    }
}

void topView(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }

    struct QueueNode* queue = NULL;

    enqueue(&queue, root, 0);

    int arr[100] = {0}; 

    while (queue != NULL) {
        struct QueueNode* current = dequeue(&queue);
        int hd = current->hd;
        struct TreeNode* node = current->treeNode;
        free(current);

        if (arr[hd] == 0) {
            arr[hd] = node->data;
        }

        if (node->left != NULL) {
            enqueue(&queue, node->left, hd - 1);
        }
        if (node->right != NULL) {
            enqueue(&queue, node->right, hd + 1);
        }
    }

    printf("Top View of Binary Tree: ");
    for (int i = 0; i < 100; i++) {
        if (arr[i] != 0) {
            printf("%d ", arr[i]);
        }
    }
}

int main() {
    struct TreeNode* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);
    root->left->left = createNode(3);
    root->left->right = createNode(7);
    root->right->left = createNode(12);

    topView(root);

    return 0;
}
