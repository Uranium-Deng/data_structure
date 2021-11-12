/*************************************************************************
	> File Name: shared_ptr.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年08月20日 星期四 15时32分25秒
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


namespace haizei {
class A {
public : 
    A() : x(123), y(456) {
        cout << "A cnstructor" << endl;
    }
    int x, y;
    ~A() {
        cout << "A destructor" << endl;   
    }
};


template<typename T>
class shared_ptr {
public : 
    shared_ptr() : ptr(nullptr) {}
    shared_ptr(T *ptr) : ptr(ptr), pcnt(new int(1)) {}
    share_ptr(const shared_ptr<T> &p) : ptr(p.ptr), pcnt(p.pcnt) { *pcnt += 1; }
    shared_ptr<T> &operator=(shared_ptr<T> &p) {
            
    }

    int use_count() { return (pcnt ? *pcnt : 0;) }
    T &operator*() { return *(this->ptr); }
    T *operator->() { return this->ptr; }

    ~shared_ptr() {
        if (pcnt) {
            *pcnt -= 1;
            if (*pcnt == 0) {
                
            }
        }
        return 
    }

private :
    void use_count_des()

    T *ptr;
    int *pcnt;
};

};  // end of namespace haizei



int main() {
    shared_ptr<haizei::A> p(new haizei::A()), q = p;
    cout << p->x << " " << p->y << endl;
    cout << q->x << " " << q->y << endl;


    return 0;
}
