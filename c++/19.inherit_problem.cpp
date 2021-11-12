/*************************************************************************
	> File Name: 19.inherit_problem.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年08月01日 星期六 15时13分32秒
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

struct A {
    int x;
};


//  virtual 虚拟继承，合并有可能产生父类的重复
struct B : virtual public A {
    void set(int x) {
        this->x = x;
        cout << "set : " << &this->x << endl;
    }
};

struct C : virtual public A {
    int get() { 
        cout << "get : " << &this->x << endl;
        return this->x;
    } 
};

struct D : public B, public C {
    

};

int main() {
    D d;
    d.set(53);
    cout << d.get() << endl;
    cout << sizeof(d) << endl;

    return 0;
}
