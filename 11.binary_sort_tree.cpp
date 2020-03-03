/*************************************************************************
	> File Name: 11.binary_sort_tree.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年02月22日 星期六 22时23分58秒
 ************************************************************************/

#include <iostream>
using namespace std;

typedef struct Node {
    int data;
    struct Node *lchild, *rchild;
} Node;

Node *getNewNode(int val) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = val;
    node->lchild = node->rchild = NULL;
    return node;
}

Node *insert(Node *root, int val) {
    if (!root) return getNewNode(val);
    if (val == root->data) return root;
    else if (val < root->data) {
        root->lchild = insert(root->lchild, val);
    } else {
        root->rchild = insert(root->rchild, val);
    }
    return root;
}

Node *get_pre_node(Node *root) {
    Node *ret = root->lchild;
    while (ret->rchild) ret = ret->rchild;
    return ret;
}

Node *erase(Node *root, int val) {
    if (!root) return root;
    if (val < root->data) root->lchild = erase(root->lchild, val);
    else if (val > root->data) root->rchild = erase(root->rchild, val);
    else {
        if (!root->lchild || !root->rchild) {
            Node *tmp = root->lchild ? root->lchild : root->rchild;
            free(root);
            return tmp;
        } else {
            Node *tmp = get_pre_node(root);
            root->data = tmp->data;
            root->lchild = erase(root->lchild, tmp->data);
        }
    }
    return root;
}

void in_order_1(Node *root) {
    if (!root) return ;
    in_order_1(root->lchild);
    printf("%d ", root->data);
    in_order_1(root->rchild);
}
void in_order(Node *root) {
    if (!root) return ;
    printf("in_order: ");
    in_order_1(root);
    printf("\n");
}


void clear(Node *root) {
    if (!root) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
}


int main() {
    Node *root = NULL;
    int op, data;
    while (~scanf("%d %d", &op, &data)) {
        switch (op) {
            case 1: {
                printf("insert %d into binary_sort_tree\n", data);
                root = insert(root, data);
                break;
            }
            case 2: {
                printf("erase %d from binary_search_tree\n", data);
                root = erase(root, data);
                break;
            }
            default: printf("input wrong\n");
        }
        in_order(root);
    }
    clear(root);
    return 0;
}
