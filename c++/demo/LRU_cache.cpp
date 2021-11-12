/*************************************************************************
	> File Name: 0.demo.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年09月22日 星期二 15时00分50秒
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
    LRUCache(int size) : size(size), cnt(0), head(nullptr), tail(nullptr) {
        H.key = -1, H.value = -1, H.next = nullptr, H.pre = nullptr;
    }

    void removeTailNode() {
        // 删除尾结点
        if (tail == nullptr) return ;
        mmap.erase(tail->key);
        Node *delete_node = tail;
        tail = tail->pre;
        delete delete_node;
    }

    void addNodeToHead(Node *tmp) {
        // 将结点移到链表头部
        if (head == nullptr) {
            H.next = tmp;
            tmp->pre = &H;
            head = tmp;
            tail = tmp;
        }
        tmp->next = head;
        head->pre = tmp;
        H.next = tmp;
        tmp->pre = &H;
        head = tmp;
    }

    void linkTwoNodes(Node *tmp) {
        // 将tmp前后两个结点相连
        if (tmp == tail) {
            tmp->pre->next = tmp->next;
            tail = tmp->pre;
            return ;
        } else if (tmp == head) {
            // tmp->next->pre = tmp->pre;
            return ;
        }
        tmp->pre->next = tmp->next;
        tmp->next->pre = tmp->pre;
    }

    void put(int key, int value) {
        // 向内存中调入页面
        if (mmap.find(key) == mmap.end()) {
            Node *tmp = new Node(key, value);
            mmap[key] = tmp;

            if (cnt == size) removeTailNode();
            else cnt++;
            
            addNodeToHead(tmp); 
        } else {
            Node *tmp = mmap[key];
            tmp->value = value;
            addNodeToHead(tmp);
        }
    }

    void get(int key) {
        // 从内存中访问页面
        if (mmap.find(key) == mmap.end()) {
            // cout << "Cache中没有该页面" << endl;
            cout << "-1" << endl;
            return ;
        }
        Node *tmp = mmap[key];
        // cout << "Get: key = " << tmp->key << ", value = " << tmp->value << endl;
        cout << tmp->value << endl;
        linkTwoNodes(tmp);
        if (tmp != head) addNodeToHead(tmp);
    }

    void printAllNodes() {
        cout << "linkedlist is as follow: " << endl;
        for (Node *tmp = head; tmp != nullptr; tmp = tmp->next) {
            cout << "key: " << tmp->key << ", value: " << tmp->value << endl;
        }
    }


private :
    int size, cnt;
    Node *head, *tail;
    Node H;
    unordered_map<int, Node *> mmap;
};


int main() {

    LRUCache tmp(2);
    tmp.put(1, 1);
    // tmp.printAllNodes();
    tmp.put(2, 2);
    // tmp.printAllNodes();
    tmp.get(1);
    tmp.put(3, 3);
    tmp.get(2);
    // tmp.printAllNodes();
    tmp.put(4, 4);
    // tmp.printAllNodes();
    tmp.get(1);
    tmp.get(3);
    tmp.get(4);


    return 0;
}
