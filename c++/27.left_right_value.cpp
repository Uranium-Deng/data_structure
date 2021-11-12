/*************************************************************************
	> File Name: 27.left_right_value.cpp
	> Author: huguang
	> Mail: hug@haizeix.com
	> Created Time: 日  8/ 2 20:23:56 2020
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
#define TEST(a, f) { \
    cout << #a <<  " : " << #f << " "; \
    f(a); \
}

void f2(int &x) {
    cout << "left value" << endl;
}

void f2(int &&x) {
    cout << "right value" << endl;
}

void f(int &x) {
    cout << "left value" << endl;
    TEST(x, f2);
}

void f(int &&x) {
    cout << "right value" << endl;
    TEST(move(x), f2);
    TEST(forward<int &&>(x), f2);
}

int test_func(const int &&x) {
    cout << x << endl;
    return 0;
}

int main() {
    int a, b = 1, c = 3;
    (++a) = b + c;
    cout << a << endl;
    (a++);
    (a = b) = c;
    cout << a << " " << b << endl;
    int arr[10];
    arr[3] = 12;
    (a += 3) = 67;
    cout << a << endl;
    TEST(a += 3, f);
    TEST(1 + 4, f);
    TEST(b + c, f);
    TEST(a++, f);
    TEST(++a, f);
    // 将右值绑定到const修饰的左值是可以的
    // 将左值绑定到const修饰的右值，是不可以的
    // 右值引用意味着这个变量是临时的，即将销毁
    // move()将左值转换为右值
    // forward 和 move
    test_func(move(a));
    return 0;
}
