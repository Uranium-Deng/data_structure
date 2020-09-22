/*************************************************************************
	> File Name: 0.demo.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年09月22日 星期二 17时02分26秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;


struct Node {
    int key, value;
    Node *next, *pre;
    Node() : key(0), value(0), next(nullptr), pre(nullptr) {}
    Node(int x, int y) : key(x), value(y), next(nullptr), pre(nullptr) {}
};


class LRUCache {
public :
    LRUCache(int _size) : size(_size), cnt(0), head(nullptr), tail(nullptr) {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->pre = head;
    }

    void get(int key) {
        if (mmap.find(key) == mmap.end()) {
            cout << -1 << endl;
            return ;
        }
        Node *node = mmap[key];
        cout << node->value << endl;
        linkTwoNodes(node);
        addNodeToHead(node);
    }

    void put(int key, int value) {
        if (mmap.find(key) == mmap.end()) {
            Node *node = new Node(key, value);
            mmap[key] = node;

            addNodeToHead(node);
            cnt++;
            if (cnt > size) {
                removeTailNode(); cnt--;
            }
        } else {
            Node *node = mmap[key];
            node->value = value;
            addNodeToHead(node);
        }
    }

    void addNodeToHead(Node *node) {
        node->next = head->next;
        node->pre = head->next->pre;
        head->next = node;
        node->next->pre = node;
    }

    void linkTwoNodes(Node *node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }
    
    void removeTailNode() {
        Node *node = tail->pre;
        linkTwoNodes(node);
        mmap.erase(node->key);
        delete node;
    }

private :
    int size, cnt;
    Node *head, *tail;
    unordered_map<int, Node *> mmap;
};


int main() {
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cache.get(1);
    cache.put(3, 3);
    cache.get(2);
    cache.put(4, 4);
    cache.get(1);
    cache.get(3);
    cache.get(4);

    return 0;
}
