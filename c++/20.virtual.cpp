/*************************************************************************
	> File Name: 20.virtual.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年08月01日 星期六 15时51分11秒
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


class Animal {
public :
    virtual void run() {
        cout << "I don't how to run" << endl;
    }

private :

};

// 将运行时错误 转换为 编译时错误
// 不加overide关键字 不会影响函数功能
class Cat : public Animal {
public : 
    void run() override {
        cout << "I can run with four legs" << endl;
    }
private :

};

class Dog : public Animal {
public : 
    void run() override {
        cout << "I can run with four legs, tail yao a yao" << endl;
    }
private :

};

class Bat : public Animal {
public : 
    void run() override {
        cout << "I can fly" << endl;
    }
private :

};

// 此时存储的是 虚函数表vtable的首地址
class A {
public :
    int x;
    virtual void say(int xx) {
        cout << this << endl;
        cout << "Class A: I can say, xx = " << xx << ", this->x = " << x << endl;
    }

private : 
};

class Base {
public :
    Base() {
        cout << "Base constructor" << endl;
        this->x = new int;
    }

    virtual ~Base() {
        cout << "Base destructor" << endl;
        delete this->x;
    }

private :
    int *x;
};

class Base_A : public Base {
public : 
    Base_A() {
        cout << "Base_A constructor" << endl;
        this->y = new int;
    }

    ~Base_A() {
        cout << "Base_A destructor" << endl;
        delete this->y;
    }

private :    
    int *y;
};


typedef void (*func)(void *, int);

int main() {
    Base *ba = new Base_A(); 
    delete ba;



    cout << sizeof(A) << endl;

    A tmp_a, tmp_b;
    tmp_a.x = 9973;
    tmp_b.x = 10000;
    (*(((func **)(&tmp_a))[0]))(&tmp_b, 6);

    cout << "\n\n" << endl;

    srand(time(0));
    Cat a;
    Animal &b = a;
    cout << "sizeof(Cat) : " << sizeof(Cat) << endl;
    // 注意c数组中 存储的是对象指针
    Animal *c[10];

    for (int i = 0; i < 10; i++) {
        int op = rand() % 3;
        switch (op) {
            case 0: c[i] = new Cat(); break;
            case 1: c[i] = new Dog(); break;
            case 2: c[i] = new Bat(); break;
        }
    }
    for (int i = 0; i < 10; i++) {
        c[i]->run();
    }

    return 0;
}

// 普通成员函数 服从class
// 虚函数 服从 对象
