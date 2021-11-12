/*************************************************************************
	> File Name: 22.dynamic.cast.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年08月01日 星期六 20时26分43秒
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

class A {
public : 
    virtual ~A() {}
};

class B : public A {
public :
    int x;
    void sayB() {
        cout << "this is class B" << endl;
    }
};
class C : public A {
public : 
    void sayC() {
        cout << "this is class C, x = " << x << endl;
    }
    double x;
};
class D : public A {
public :
    void sayD() {
        cout << "this is class D, x = " << x << endl;
    }
    string x;
};
class E : public A {};


// 要求父类是多态的
// 不同派生类对应不同的虚函数表
int my_dynamic_cast(A *ta) {
    char **pa = (char **)ta;
    char **pb = (char **)new B();
    char **pc = (char **)new C();
    char **pd = (char **)new D();

    int ret = -1;
    if (pa[0] == pb[0]) ret = 0;
    else if (pa[0] == pc[0]) ret = 1;
    else if (pa[0] == pd[0]) ret = 2;

    return ret;
}


int main() {
    A a;
    cout << sizeof(a) << endl;
    srand(time(0));
    A *pa;
    B *pb;
    C *pc;
    D *pd;
    switch (rand() % 3) {
        case 0: pa = new B(); pa = pb; pb->x = 123; break;
        case 1: pa = new C(); pa = pc; pc->x = 45.1; break;
        case 2: pa = new D(); pa = pd; pd->x = "hello world"; break;
    }
    if ((pb = dynamic_cast<B *>(pa))) {
        cout << "Class B : ";
        pb->sayB();
    } else if ((pc = dynamic_cast<C *>(pa))) {
        cout << "Class C : ";
        pc->sayC();

    } else if ((pd = dynamic_cast<D *>(pa))) {
        cout << "Class D : ";
        pd->sayD();   
    }

    switch (my_dynamic_cast(pa)) {
        case 0: (B *)(pa)->sayB(); break;
        case 1: (C *)(pa)->sayC(); break;
        case 2: (D *)(pa)->sayD(); break;
    }



    return 0;
}
