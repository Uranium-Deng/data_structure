/*************************************************************************
	> File Name: tree.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年02月18日 星期二 09时04分32秒
 ************************************************************************/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

#define NORMAL 0
#define THREAD 1

typedef struct Node {
    char data;
    struct Node *lchild, *rchild;
    int ltag, rtag;
} Node;

Node *getNewNode(char val) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = val;
    node->lchild = node->rchild = NULL;
    node->ltag = node->rtag = NORMAL;
    return node;
}

Node *insert(Node *root, char val) {
    if (!root) return getNewNode(val);
    if (val == root->data) return root;
    if (val < root->data) root->lchild = insert(root->lchild, val);
    else if (val > root->data) root->rchild = insert(root->rchild, val);
    return root;
}

void in_order(Node *root, vector<char>& v) {
    if (!root) return ;
    if (root->ltag == NORMAL) in_order(root->lchild, v);
    v.push_back(root->data);
    if (root->rtag == NORMAL) in_order(root->rchild, v);
}

Node *most_left(Node *root) {
    Node *p = root;
    while (p && p->ltag == NORMAL && p->lchild) p = p->lchild;
    return p;
}

void build_thread(Node *root) {
    if (!root) return ;
    static Node *pre = NULL;
    build_thread(root->lchild);
    if (!root->lchild) {
        root->lchild = pre;
        root->ltag = THREAD;
    }
    if (pre && !pre->rchild) {
        pre->rchild = root;
        pre->rtag = THREAD;
    }
    pre = root;
    build_thread(root->rchild);
}

void output(Node *root) {
    if (!root) return ;
    Node *p = most_left(root);
    while (p) {
        printf("%c ", p->data);
        if (p->rtag == THREAD) {
            p = p->rchild;
        } else {
            p = most_left(p->rchild);
        }
    }
    printf("\n");
}

void clear(Node *root) {
    if (!root) return ;
    if (root->ltag == NORMAL) clear(root->lchild);
    if (root->rtag == NORMAL) clear(root->rchild);
    free(root);
}

int depth_of_tree(Node *root) {
    if (!root) return 0;
    else {
        int n = 0, m = 0;
        if (root->ltag == NORMAL) n = depth_of_tree(root->lchild);
        if (root->rtag == NORMAL) m = depth_of_tree(root->rchild);
        if (m > n) return (m + 1);
        else return (n + 1);
    }
}

int node_num(Node *root) {
    if (!root) return 0;
    else {
        int n = 0, m = 0;
        if (root->ltag == NORMAL) n = node_num(root->lchild);
        if (root->rtag == NORMAL) m = node_num(root->rchild);
        return n + m + 1;
    }
}

int leaf_num(Node *root) {
    if (!root) return 0;
    if (!root->lchild && !root->ltag && !root->rchild && !root->rtag) return 1;
    else {
        int n = 0, m = 0;
        if (!root->ltag) n = leaf_num(root->lchild);
        if (!root->rtag) m = leaf_num(root->rchild);
        return n + m;
    }
    
}


int main() {
    int n;
    scanf("%d", &n);
    getchar();
    Node *root = NULL;
    for (int i = 0; i < n; i++) {
        char c;
        scanf("%c", &c);
        root = insert(root, c);
    }
    Node *tmp = most_left(root);
    printf("tmp->data = %c\n", tmp->data);

    vector<char> v;
    in_order(root, v);
    vector<char>::iterator it;
    printf("in_order: ");
    for (it  = v.begin(); it != v.end(); it++) {
        if (it != v.begin()) printf(" ");
        printf("%c", *it);
    }
    printf("\n");

    printf("in_order thread: ");
    build_thread(root);
    output(root);

    printf("depth_of_tree = %d\n", depth_of_tree(root));
    printf("node_num = %d\n", node_num(root));
    printf("leaf_num = %d\n", leaf_num(root));

    clear(root);
    return 0;
}
