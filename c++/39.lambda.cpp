/*************************************************************************
	> File Name: 39.lambda.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年08月17日 星期一 09时57分49秒
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
#include <typeinfo>
using namespace std;


int main() {
    // lambda 表达式最后莫忘记;
    // []理解为装入变量的口袋（捕获）
    // 捕获分为：值捕获和引用捕获
    // [=]：以值捕获的方式，捕获外部的所有变量
    // [&]：以引用捕获的方式，捕获外部的所有变量
    int n = 10000;
    int m, x, y;

    // 匿名函数函数体中使用的变量，要么为()中声明的函数参数，要么()进行捕获
    auto a = [&](int a, int b) { 
        return a + b + n; 
    };
    n = 1000000;
    auto b = [&n](int a, int b) { return a + b + n; };

    auto c = [](function<int(int, int)> a, function<int(int, int)> b) {
        return [=](int x) {
            return a(x, x) + b(x, x);
        };
    };

    cout << typeid(a).name() << endl;
    cout << typeid(b).name() << endl;

    cout << a(1, 2) << endl;
    cout << b(1, 2) << endl;

    auto d = c(a, b);
    cout << d(12) << endl;

    



    return 0;
}



