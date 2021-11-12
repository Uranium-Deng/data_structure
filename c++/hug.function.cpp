/*************************************************************************
	> File Name: hug.function.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年08月13日 星期四 10时54分47秒
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
#include <functional>
using namespace std;

namespace haizei {

template<typename RT, typename ...PARAMS> 
class base {
public :
    virtual RT operator()(PARAMS...) = 0;
    virtual base<RT, PARAMS...> *getCopy() = 0;
    virtual ~base() {}
};

template<typename RT, typename ...PARAMS> 
class normal_func : public base<RT, PARAMS...> {
public :
    typedef RT (*func_type)(PARAMS...);
    normal_func(func_type func) : ptr(func) {}
    virtual RT operator()(PARAMS...args) override {
        return this->ptr(args...);
    }
    virtual base<RT, PARAMS...> *getCopy() override {
        return new normal_func<RT, PARAMS...>(ptr);
    }

private:
    func_type ptr;
};


template<typename C, typename RT, typename ...PARAMS> 
class functor : public base<RT, PARAMS...> {
public :
    functor(C &func) : ptr(func) {}
    virtual RT operator()(PARAMS...args) override {
        return this->ptr(args...);
    }
    virtual base<RT, PARAMS...> *getCopy() override {
        return new functor<C, RT, PARAMS...>(ptr);
    }

private:
    C &ptr;
};

template<typename RT, typename ...PARAMS> class function;
template<typename RT, typename ...PARAMS>
class function<RT(PARAMS...)> {
public :
    function(RT (*func)(PARAMS...)) 
    : ptr(new normal_func<RT, PARAMS...>(func)) {}

    template<typename T>
    function(T a) 
    : ptr(new functor<typename remove_reference<T>::type, RT, PARAMS...>(a)){}
    
    function(const function &f) {
        this->ptr = f.ptr->getCopy();
    }
    function(function &&f) {
        this->ptr = f.ptr;
        f.ptr = nullptr;
    }
    
    RT operator()(PARAMS... args) {
        return this->ptr->operator()(args...);
    }
    ~function() {
        if (ptr != nullptr) delete ptr;
    }

private:
    base<RT, PARAMS...> *ptr;
};

} // end of haizei


// function<int(int, int)> g 可调用函数对象
void f(function<int(int, int)> g) {
    cout << g(3, 4) << endl;
    return ;
}

int add(int a, int b) {
    return a + b;
}

int add2(int a, int b, int c) {
    return a + b + c;
}

struct MaxClass {
    int operator()(int a, int b) {
        return a > b ? a : b;
    }
};

template<typename T, typename ...ARGS> class FunctionCnt;
template<typename T, typename ...ARGS>
class FunctionCnt<T(ARGS...)> {
public :
    FunctionCnt(haizei::function<T(ARGS...)> g) : g(g), __cnt(0) {}
    int operator()(ARGS... args) {
        __cnt += 1;
        return g(args...);
    }
    int cnt() { return __cnt; }

private:
    haizei::function<T(ARGS...)> g;
    int __cnt;
};

int main() {
    function<int(int, int)> test_p;
    MaxClass max;
    test_p = add;
    cout << test_p(4, 10) << endl;
    test_p = max;
    cout << test_p(5, 10) << endl;
    f(add);
    f(max);
    haizei::function<int(int, int)> g1(add);
    haizei::function<int(int, int)> g2(max);
    cout << g1(3, 4) << endl;
    cout << g2(3, 4) << endl;
    
    FunctionCnt<int(int, int)> add_cnt(add);
    add_cnt(3, 4);
    add_cnt(4, 5);
    add_cnt(7, 9);
    cout << add_cnt.cnt() << endl;
    FunctionCnt<int(int, int, int)> add_cnt2(add2);
    add_cnt2(1, 2, 3);
    add_cnt2(4, 5, 6);
    cout << add_cnt2.cnt() << endl;
    return 0;
}
