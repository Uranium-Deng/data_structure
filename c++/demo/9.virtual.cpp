/*************************************************************************
	> File Name: 9.virtual.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年09月24日 星期四 09时38分29秒
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

// 子类继承父类，可以重写父类中的成员函数 
// 采用父类指针指向子类对象，并使用指针调用普通成员函数，
// 此时调用的函数是跟着类走的，也就是调用的成员函数是父类中的成员函数 
// 若调用的函数是virtual修饰的虚函数，
// 则此时调用的函数是跟着对象走的，也就是调用响应对象中的成员函数


// 重载和重写的区别
// 重载overload 函数名称和返回值相同，但是函数参数不同
// 编译器编译时，会根据函数的参数，对函数名进行修改，从而生成不同名称的函数
// 故overload不体现多态性，或者说 是编译期多态性

// 重写override
// 主要用于多态中类的多态性，函数名称、返回值、参数完全一致，遵循“普通成员函数跟类走，虚函数跟对象走”
// 程序在运行时才确定将要调用的函数，所以override是 运行期多态


// 父类的析构函数一定是 虚函数

string rand_name(int n) {
    string name = "";
    for (int i = 0; i < n; i++) {
        name += (char)(rand() % 26 + 'A');
    }
    return name;
}

class Animal {
public : 
    Animal(string name) : name(name) {}
    string tell_me_your_name() { return this->name; }
    virtual void run() {
        cout << "I don't know how to run" << endl;
    }
    virtual void say() = 0; // 纯虚函数
    virtual ~Animal() {
        cout << "Animal destructor" << endl;
    }

private :
    string name;

};


class Cat : public Animal {
public :
    Cat() : Animal(rand_name(5) + "_Cat") {}
    void run() override {
        cout << "I anc run with four legs" << endl;
    }
    void say() override {
        cout << "miao~ miao~ miao~" << endl;
    }
    ~Cat() override {
        cout << "Cat destructor" << endl;
    }
private : 

};


class Bat :public Animal {
public : 
    Bat() : Animal(rand_name(5) + "_Bat") {}
    void run() override {
        cout << "I can fly" << endl;
    }
    void say() override {
        cout << "zzz zzz zzz" << endl;
    }
    ~Bat() override {
        cout << "Bat destructor" << endl;
    }
private : 

};

int main() {
    Cat a;
    Bat b;
    cout << a.tell_me_your_name() << endl;
    a.run();
    cout << b.tell_me_your_name() << endl;
    b.run();

    Animal **arr = new Animal*[10];
    for (int i = 0; i < 10; i++) {
        if (rand() % 2) {
            arr[i] = new Cat();
        } else {
            arr[i] = new Bat();
        }
    }
    for (int i = 0; i < 10; i++) {
        cout << arr[i]->tell_me_your_name() << endl;
        arr[i]->run();
        arr[i]->say();
    }

    for (int i = 0; i < 10; i++) {
        delete arr[i];
    }
    delete arr;

    return 0;
}
