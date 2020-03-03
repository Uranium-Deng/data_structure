/*************************************************************************
	> File Name: 0.demo.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年02月22日 星期六 10时54分01秒
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

typedef struct Node {
    char data;
    struct Node *lchild, *rchild;
} Node;

Node *getNewNode(char val) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = val;
    node->lchild = node->rchild = NULL;
    return node;
}

Node *build(char *pre_str, char *in_str, int len) {
    Node *root = getNewNode(pre_str[0]);
    int ind = strchr(in_str, root->data) - in_str;
    if (ind > 0) {
        root->lchild = build(pre_str + 1, in_str, ind);
    }
    if (len - ind - 1 > 0) {
        root->rchild = build(pre_str + ind + 1, in_str + ind + 1, len - ind - 1);
    }
    return root;
}

void in_order(Node *root) {
    if (!root) return ;
    in_order(root->lchild);
    printf("%c ", root->data);
    in_order(root->rchild);
}


void clear(Node *root) {
    if (!root) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
}

int main() {
    char pre_str[20] = "ABDEHCFIG";
    char in_str[20] = "DBHEAIFCG";
    Node *root = NULL;
    root = build(pre_str, in_str, strlen(pre_str));
    printf("in_order: ");
    in_order(root);
    printf("\n");
    clear(root);
    return 0;
}
