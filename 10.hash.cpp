/*************************************************************************
	> File Name: 10.hash.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年02月22日 星期六 21时42分27秒
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

typedef struct Node {
    char *str;
    struct Node *next;
} Node;

typedef struct HashTable {
    Node **num;
    int size;
} HashTable;

Node *insert_node(char *str, Node *head) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->str = strdup(str);
    node->next = head;
    return node;
}
HashTable *init(int size) {
    HashTable *h = (HashTable *)malloc(sizeof(HashTable));
    h->size = size << 1;
    h->num = (Node **)calloc(h->size, sizeof(Node *));
    return h;
}

int BKDR_hash(char *str) {
    int seed = 31, ret = 0;
    for (int i = 0; str[i]; i++) ret = ret * seed + str[i];
    return ret & 0x7fffffff;
}

int insert(HashTable *h, char *str) {
    if (!h) return 0;
    int ind = BKDR_hash(str) % (h->size);
    h->num[ind] = insert_node(str, h->num[ind]);
    return 1;
}

int search(HashTable *h, char *str) {
    if (!h) return 0;
    int ind = BKDR_hash(str) % (h->size);
    Node *head = h->num[ind];
    while (head && strcmp(str, head->str)) head = head->next;
    return head != NULL;
}


void clear_node(Node *node) {
    if (!node) return ;
    Node *head = node, *delete_node = NULL;
    while (head) {
        delete_node = head;
        head = head->next;
        free(delete_node->str);
        free(delete_node);
    }
}
void clear_hashTable(HashTable *h) {
    if (!h) return ;
    for (int i = 0; i < h->size; i++) {
        clear_node(h->num[i]);
    }
    free(h->num);
    free(h);
}


int main() {
    HashTable *h = init(1000);
    int op;
    char *str;
    while (scanf("%d %s", &op, str) != EOF) {
        switch (op) {
            case 1: printf("insert %s into hashTable = %d\n", str, insert(h, str)); break;
            case 2: printf("search %s from hashTable = %d\n", str, search(h, str)); break;
            default: printf("input wrong\n");
        }
    }
    clear_hashTable(h);
    return 0;
}
