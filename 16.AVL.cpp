/*************************************************************************
	> File Name: 0.demo.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年04月26日 星期日 10时45分24秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
using namespace std;

#define K(root) (root)->data
#define H(root) (root)->h
#define L(root) (root)->lchild
#define R(root) (root)->rchild

typedef struct Node {
    int data, h;
    struct Node *lchild, *rchild;
} Node;

Node __NIL;
#define NIL (&__NIL)
__attribute__((constructor))
void init_NIL() {
    NIL->lchild = NIL->rchild = NIL;
    NIL->data = 0;
    NIL->h = 0;
}

Node *getNewNode(int val) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = val;
    node->h = 1;
    node->lchild = node->rchild = NIL;
    return node;
}

void update_height(Node *root) {
    H(root) = (H(L(root)) > H(R(root)) ? H(L(root)) : H(R(root))) + 1;
}

Node *left_rotate(Node *root) {
    Node *tmp = root->rchild;
    root->rchild = tmp->lchild;
    tmp->lchild = root;
    update_height(root);
    update_height(tmp);
    return tmp;
}

Node *right_rotate(Node *root) {
    Node *tmp = root->lchild;
    root->lchild = tmp->rchild;
    tmp->rchild = root;
    update_height(root);
    update_height(tmp);
    return tmp;
}

Node *maintain(Node *root) {
    if (abs(H(L(root)) - H(R(root))) <= 1) return root;
    if (H(L(root)) > H(R(root))) {
        if (H(L(L(root))) < H(R(L(root)))) {
            root->lchild = left_rotate(root->lchild);
        }
        root = right_rotate(root);
    } else {
        if (H(R(R(root))) < H(L(R(root)))) {
            root->rchild = right_rotate(root->rchild);
        }
        root = left_rotate(root);
    }
    return root;
}

Node *insert(Node *root, int val) {
    if (root == NIL) return getNewNode(val);
    if (root->data == val) return root;
    else if (root->data < val) {
        root->rchild = insert(root->rchild, val);
    } else {
        root->lchild = insert(root->lchild, val);
    } 
    update_height(root);
    return maintain(root);
}

Node *predeccessor(Node *root) {
    Node *tmp = root->lchild;
    while (tmp->rchild != NIL) tmp = tmp->rchild;
    return tmp;
}

Node *erase(Node *root, int val) {
    if (root == NIL) return NIL;
    if (root->data < val) {
        root->rchild = erase(root->rchild, val);
    } else if (root->data > val) {
        root->lchild = erase(root->lchild, val);
    } else {
        if (root->lchild == NIL || root->rchild == NIL) {
            Node *tmp = (L(root) == NIL ? R(root) : L(root));
            free(root);
            return tmp;
        } else {
            Node *tmp = predeccessor(root);
            root->data = tmp->data;
            root->lchild = erase(root->lchild, tmp->data);
        }
    }
    update_height(root);
    return maintain(root);
}

void in_order(Node *root) {
    if (root == NIL) return ;
    in_order(root->lchild);
    printf("%d ", root->data);
    in_order(root->rchild);
}

void output(Node *root) {
    if (root == NIL) return ;
    printf("(%d, %d, %d)\n", K(root), K(L(root)), K(R(root)));
    output(root->lchild);
    output(root->rchild);
}

void clear(Node *root) {
    if (root == NIL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
}

int main() {
    srand(time(0));
    #define MAX_OP 20
    Node *root = NIL;
    for (int i = 0; i < MAX_OP; i++) {
        int val = rand() % 100;
        root = insert(root, val);
        printf("insert %d into AVL Tree\n", val);
    }
    output(root);
    in_order(root);
    printf("\n");

    int tmp = 0;
    while (~scanf("%d", &tmp)) {
        root = erase(root, tmp);
        output(root);
        in_order(root);
        printf("\n");
    }
    clear(root);
    return 0;
}


