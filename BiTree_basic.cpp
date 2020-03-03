/*************************************************************************
	> File Name: 0.demo.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年02月22日 星期六 09时25分39秒
 ************************************************************************/

#include <iostream>
#include <stack>
#include <vector>
#include <queue>
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


Node *build(char *str, int *node_num) {  //根据字符串建树，返回根结点
    Node *tmp = NULL, *top_p = NULL;
    int flag = 0;
    stack<Node *> s;
    while (str[0]) {
        switch (str[0]) {
            case '(': {
                flag = 0;
                s.push(tmp);
                tmp = NULL;
                break;
            }
            case ')': {
                top_p = s.top();
                s.pop();
                break;
            }
            case ',': {
                flag = 1;
                tmp = NULL;
                break;
            }
            case ' ': {
                break;
            }
            default: {
                tmp = getNewNode(str[0]);
                if (!s.empty() && !flag) {
                    s.top()->lchild = tmp;
                } else if (!s.empty() && flag) {
                    s.top()->rchild = tmp;
                }
                (*node_num)++;
            }
        }
        str++;
    }
    if (tmp && !top_p) top_p = tmp;
    return top_p;
}

void in_order(Node *root, vector<char>& v) {
    if (!root) return ;
    in_order(root->lchild, v);
    v.push_back(root->data);
    in_order(root->rchild, v);
}

void BFS(Node *root, vector<char>& v) {
    if (!root) return ;
    queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
        Node *tmp = q.front();
        v.push_back(tmp->data);
        q.pop();
        if (tmp->lchild) q.push(tmp->lchild);
        if (tmp->rchild) q.push(tmp->rchild);
    }
}

void tree_to_table(Node *root) {
    if (!root) return ;
    printf("%c", root->data);
    if (root->lchild == NULL && root->rchild == NULL) return ;
    printf("(");
    tree_to_table(root->lchild);
    printf(",");
    tree_to_table(root->rchild);
    printf(")");
}

int get_node_num(Node *root) {
    if (!root) return 0;
    return get_node_num(root->lchild) + get_node_num(root->rchild) + 1;
}
int get_tree_depth(Node *root) {
    if (!root) return 0;
    int n = 0, m = 0;
    m = get_tree_depth(root->rchild);
    return max(n, m) + 1;
}
int get_leaf_num(Node *root) {
    if (!root) return 0;
    if (root->lchild == NULL && root->rchild == NULL) return 1;
    return get_leaf_num(root->lchild) + get_leaf_num(root->rchild);
}


void clear(Node *root) {
    if (!root) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
}

int main() {
    char str[100] = {0};
    scanf("%[^\n]s", str);
    int node_num = 0;
    Node *root = build(str, &node_num);
    printf("node_num = %d\n", get_node_num(root));

    vector<char> v;
    in_order(root, v);
    vector<char>::iterator it;
    printf("in_order: [");
    for (it = v.begin(); it != v.end(); it++) {
        if (it != v.begin()) printf(" ");
        printf("%c", *it);
    }
    printf("]\n");
    
    printf("tree_to_table: ");
    tree_to_table(root);
    printf("\n");

    printf("tree's depth = %d\n", get_tree_depth(root));
    printf("tree's leaf node number = %d\n", get_leaf_num(root));

    vector<char> v2;
    BFS(root, v2);
    vector<char>::iterator it2;
    printf("BFS: [");
    for (it2 = v2.begin(); it2 != v2.end(); it2++) {
        if (it2 != v2.begin()) printf(" ");
        printf("%c", *it2);
    }
    printf("]\n");

    return 0;
}
