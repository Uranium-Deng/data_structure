/*************************************************************************
	> File Name: 15.inherit_permission.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年07月28日 星期二 18时53分36秒
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
    Animal(string name, int age) : __name(name), age(age) {}
    void say() {
        cout << "my name is: " << __name << endl;
    }

protected :
    string __name;

private :
    int age;

};

// public 继承权限
class Cat : public Animal {
public :
    Cat() = delete;
    Cat(string name, int age) : Animal(name, age) {}

};

// protected 继承权限
class Bat : protected Animal {
public :
    Bat() = delete;
    Bat(string name, int age) : Animal(name, age) {}
    /*
    void say() {
        this->Animal::say();
        cout << "class Bat: " << __name << endl;
    }*/

private :
    
};

int main() {
    Cat a("Kitty", 10);
    a.say();

    Bat b("BatMan", 6651);
    
    // 此时从外部来看, b中的say函数为protected类型的，所以外部无法直接.访问
    // b.say();

    return 0;
}
