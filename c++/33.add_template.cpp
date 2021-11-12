/*************************************************************************
	> File Name: 33.add_template.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年08月12日 星期三 14时37分25秒
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

// decltype 推导表达式的结果类型，但是不计算表达式的值，用于返回值类型推导
// 和模板作用在同一阶段


struct A {
    A() = delete;
    A(int x) : x(x) {}
    double operator+(int x) {
        return x + this->x + 0.001;
    }
    int x;
};

// 要求T和U 有默认构造函数
// 返回值后置
/*
template<typename T, typename U>
decltype(T() + U()) add(T a, U b) {
    return a + b;
}*/

template<typename T, typename U>
auto add(T a, U b) -> decltype(a + b) {
    return a + b;
}


template<typename T, typename U>
auto add(T *a, U *b) -> decltype(add(*a, *b)) {
    return add(*a, *b);
}

// 返回值后置，将函数返回值放在后面
auto func(int x) -> int {
    return 2 * x;
}

int main() {
    cout << add(2, 3) << endl;
    cout << add(2, 3.5) << endl;
    cout << add(3.5, 2) << endl;
    
    int a = 12;
    double b = 45.7;
    decltype(a + b) c;
    cout << sizeof(c) << endl;

    A d(6);
    cout << add(d, 4) << endl;
    // cout << func(4) << endl;
    cout << add(&a, &b) << endl;
    return 0;
}
