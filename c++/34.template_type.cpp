/*************************************************************************
	> File Name: 34.template_type.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年08月12日 星期三 15时17分06秒
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

template<typename T> struct my_remove_reference { typedef T type; };
template<typename T> struct my_remove_reference<T &> { typedef T type; };
template<typename T> struct my_remove_reference<T &&> { typedef T type; };

// 引用折叠
// 修改数据类型的方法 remove_reference()

template<typename T>
void my_swap(T &&a, T &&b) {
    typename my_remove_reference<T>::type c; //代表去掉引用之后的类型
    c = a;
    a = b;
    b = c;
}

// 模板函数中，&&表示传递引用，而不是右值引用
template<typename T>
void add(T &&a, T &&b) {
    a += 3;
    b += 4;
}



void func(void (*p)(int &, int &), int &a, int &b) {
    p(a, b);
}

int main() {
    int a = 123, b = 456;
    cout << a << " " << b << endl;
    my_swap(a, b);
    cout << a << " " << b << endl;
    my_swap(move(a), move(b));
    cout << a << " " << b << endl;

    // function<void(int &, int &)> func; 
    // func就是函数指针，指向返回值为void,参数为int &, int &的函数
    
    func(add, a, b);
    cout << a << " " << b << endl;
    
    return 0;
}
