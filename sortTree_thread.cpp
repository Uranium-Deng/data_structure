/*************************************************************************
	> File Name: 0.demo.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年02月22日 星期六 11时37分03秒
 ************************************************************************/

#include <iostream>
using namespace std;

#define NORMAL 0
#define THREAD 1

typedef struct Node {
    int data;
    struct Node *lchild, *rchild;
    int ltag, rtag;
} Node;

Node *getNewNode(int val) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = val;
    node->lchild = node->rchild = NULL;
    node->ltag = node->rtag = NORMAL;
    return node;
}

Node *build_sort_tree(Node *root, int val) {
    if (!root) return getNewNode(val);
    if (root->data == val) return root;
    else if (val < root->data) {
        root->lchild = build_sort_tree(root->lchild, val);
    } else {
        root->rchild = build_sort_tree(root->rchild, val);
    }
    return root;
}

Node *get_most_left(Node *root) {
    Node *ret = root;
    while (ret && ret->lchild && ret->ltag == NORMAL) ret = ret->lchild;
    return ret;
}

void build_thread(Node *root) {
    if (!root) return ;
    static Node *pre = NULL;
    build_thread(root->lchild);
    if (root && !root->lchild) {
        root->lchild = pre;
        root->ltag = THREAD;
    } else if (pre && !pre->rchild) {
        pre->rchild = root;
        pre->rtag = THREAD;
    }
    pre = root;
    build_thread(root->rchild);
}

void output(Node *root) {
    if (!root) return ;
    printf("thread_outut: ");
    Node *start = get_most_left(root);
    while (start) {
        printf("%d ", start->data);
        if (start->rtag == THREAD) {
            start = start->rchild;
        } else if (start->rtag == NORMAL) {
            start = get_most_left(start->rchild);
        }
    }
    printf("\n");
}


void in_order(Node *root) {
    if (!root) return ;
    in_order(root->lchild);
    printf("%d ", root->data);
    in_order(root->rchild);
}


void clear(Node *root) {
    if (!root) return ;
    if (root->ltag == NORMAL) clear(root->lchild);
    if (root->rtag == NORMAL) clear(root->rchild);
    free(root);
}

int main() {
    #define MAX_OP 20
    srand(time(0));
    Node *root = NULL;
    printf("random number: ");
    for (int i = 0; i < MAX_OP; i++) {
        int val = rand() % 100;
        printf("%d ", val);
        root = build_sort_tree(root, val);
    }
    printf("\n");

    printf("in_order: ");
    in_order(root);
    printf("\n");

    build_thread(root);
    output(root);

    clear(root);
    return 0;
}
