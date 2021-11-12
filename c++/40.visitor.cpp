/*************************************************************************
	> File Name: 0.demo.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年09月29日 星期二 16时23分56秒
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

class B;  //  *3
class C;  //  /2
class D;  //  +5
class E;  //  -7

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
    virtual ~A () {}
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
public :
    virtual void Accept(IVisitor *vis) {
        vis->visit(this);
    }
};

class CalcVisitor : public A::IVisitor {
public :
    CalcVisitor(int val = 1) : val(val) {}
    virtual void visit(B *obj) {
        val *= 3;
        cout << "val: " << val << endl;
        cout << "this is class B" << endl;    
    }
    virtual void visit(C *obj) {
        val /= 2;
        cout << "val: " << val << endl;
        cout << "this is class C" << endl;
    }
    virtual void visit(D *obj) {
        val += 5;
        cout << "val: " << val << endl;
        cout << "this is class D" << endl;
    }
    virtual void visit(E *obj) {
        val -= 7;
        cout << "val: " << val << endl;
        cout << "this is class E" << endl;
    }
    int val;
};

int main() {
    A *arr[10];
    for (int i = 0; i < 10; i++) {
        switch (rand() % 4) {
            case 0: arr[i] = new B(); break;
            case 1: arr[i] = new C(); break;
            case 2: arr[i] = new D(); break;
            case 3: arr[i] = new E(); break;
        }
    }
    CalcVisitor calc;
    for (int i = 0; i < 10; i++) {
        arr[i]->Accept(&calc);
    }
    cout << "ans = " << calc.val << endl;


    return 0;
}
