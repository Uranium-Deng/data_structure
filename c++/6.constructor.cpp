/*************************************************************************
	> File Name: 6.constructor.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年07月26日 星期日 18时14分58秒
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
#include <vector>
using namespace std;

class People {
private :
    string name;
    int *arr;

public :
    People() = default;
    // People() = delete; // 删除默认构造函数
    People() {
        arr = new int[10];
        cout << "default constructor" << endl;
    }
    People(string name) {
        cout << "param constructor" << endl;
        this->name = name;
    }
    People(int x) {
        cout << "int param constructor" << endl;
        this->x = x;
    }
    // 此处为何需要使用引用
    People(const People &a) {
        cout << "copy constructor" << endl;
        this->name = a.name;
        this->x = a.x;
    }
    int x;
    

    ~People() {
        // delete arr;
        cout << "destructor" << endl;
    }

};

int add(People a, People b) {
    return a.x + b.x;
}

/*
void increase(int &a) {
    a += 1;
    return ;
}*/


int main() {
    // int a = 7;
    // increase(a);
    // cout << a << endl;
    // People a = string("tom");
    cout << add(3, 4) <<  endl;
    // cout << "this is main function" << endl;
    // People b = 5;

    return 0;
}
