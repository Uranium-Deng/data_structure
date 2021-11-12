/*************************************************************************
	> File Name: 3.visitor.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年09月29日 星期二 11时32分19秒
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


class A;
class B;
class C;
class D;
class E;

int cnt[4];

class A {
public :
    class IVisitor {
    public :
        virtual void visit(B *) = 0;
        virtual void visit(C *) = 0;
        virtual void visit(D *) = 0;
        virtual void visit(E *) = 0;
    };
    virtual void Accept(IVisitor *) = 0;
    virtual ~A() {}
};

class B : public A {
public :
    virtual void Accept(IVisitor *vis) {
        vis->visit(this);
    }
};

class C : public A {
public : 
    virtual void Accept(IVisitor *vis) {
        vis->visit(this);
    }
};

class D : public A {
public :
    virtual void Accept(IVisitor *vis) {
        vis->visit(this);
    }
};

class E : public A {
    virtual void Accept(IVisitor *vis) {
        vis->visit(this);
    }
};


class FunctionVisitor : public A::IVisitor {
public :
    virtual void visit(B *b) {
        cnt[0]++;
        cout << "this is class B" << endl;
    }
    virtual void visit(C *c) {
        cnt[1]++;
        cout << "this is class C" << endl;
    }
    virtual void visit(D *d) {
        cnt[2]++;
        cout << "this is class D" << endl;
    }
    virtual void visit(E *e) {
        cnt[3]++;
        cout << "this is class E" << endl;
    }
};

// 在基类中声明虚函数，由父类指针调用，由于虚函数特性，调用的是对象中的函数
// 这样相当于得到了对象的类型，之后在调用访问者类，并将该对象的指针类行传入，
// 在访问着类中整对不同类型的对象，执行相应的功能。

int main() {
    srand(1);
    A *arr[10];
    for (int i = 0; i < 10; i++) {
        switch (rand() % 4) {
            case 0: arr[i] = new B(); break;
            case 1: arr[i] = new C(); break;
            case 2: arr[i] = new D(); break;
            case 3: arr[i] = new E(); break;
        }
    }
    FunctionVisitor output;
    for (int i = 0; i < 10; i++) {
        arr[i]->Accept(&output);
    }
    for (int i = 0; i < 4; i++) {
        cout << cnt[i] << " ";
    }
    cout << endl;
    /*
    for (int i = 0; i <10; i++) {
        if (dynamic_cast<B *>(arr[i])) {
            cout << "this is class B" << endl;
        } else if (dynamic_cast<C *>(arr[i])) {
            cout << "this is class C" << endl;
        } else if (dynamic_cast<D *>(arr[i])) {
            cout << "this is class D" << endl;
        } else {
            cout << "this is an error class" << endl;
        }
    }
    */
    return 0;
}
