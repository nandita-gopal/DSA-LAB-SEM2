#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    int hd;
    int level; 
    struct TreeNode* left;
    struct TreeNode* right;
};


struct QueueNode {
    struct TreeNode* treeNode;
    int hd;
    int level;
    struct QueueNode* next;
};

struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->hd = 0;
    newNode->level = 0;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void enqueue(struct QueueNode** queue, struct TreeNode* treeNode, int hd, int level) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->treeNode = treeNode;
    newNode->hd = hd;
    newNode->level = level;
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

// Function to dequeue a node from the queue
struct QueueNode* dequeue(struct QueueNode** queue) {
    if (*queue == NULL) {
        return NULL;
    } else {
        struct QueueNode* temp = *queue;
        *queue = (*queue)->next;
        return temp;
    }
}


void bottomView(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }

    struct QueueNode* queue = NULL;
    enqueue(&queue, root, 0, 0);

    int arr[100][2] = {0}; 

    while (queue != NULL) {
        struct QueueNode* current = dequeue(&queue);
        int hd = current->hd;
        int level = current->level;
        struct TreeNode* node = current->treeNode;
        free(current);

        arr[hd][0] = node->data; 
        arr[hd][1] = level; 

        if (node->left != NULL) {
            enqueue(&queue, node->left, hd - 1, level + 1);
        }
        if (node->right != NULL) {
            enqueue(&queue, node->right, hd + 1, level + 1);
        }
    }

    printf("Bottom View of Binary Tree: ");
    for (int i = 0; i < 100; i++) {
        if (arr[i][0] != 0) {
            printf("%d ", arr[i][0]);
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

    bottomView(root);

    return 0;
}

