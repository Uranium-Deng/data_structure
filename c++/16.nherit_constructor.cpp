/*************************************************************************
	> File Name: 16.nherit_constructor.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年07月28日 星期二 19时55分30秒
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

class D {
public:
    D() {cout << "D consturtcor" << endl;}

    ~D() {
        cout << "D destructor" << endl;
    }
};


class A {
public:
    A() = delete;
    A(int x, int y) {cout << "A constructor" << endl;}

    ~A() {
        cout << "A destructor" << endl;
    }
    
};

class B {
public:
    B() {cout << "B constructor" << endl; }
    
    ~B() {
        cout << "B destructor" << endl;
    }
};

class C : public D {
public:
    C() : a(3, 4) {cout << "C constructor" << endl;}

    ~C() {
        cout << "C desconstructor" << endl;
    }
private:
    B b;
    A a;
};

int main() {
    C c;

    return 0;
}
