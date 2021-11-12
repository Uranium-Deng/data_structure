/*************************************************************************
	> File Name: 24.constexpr.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年08月02日 星期日 18时57分01秒
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

// C++11 对于constexpr修饰的函数 不支持递归实现

// 编译期常量
constexpr int func(int x) {
    return  3 * x * x + x;
}

class A {
public : 
    constexpr A(int x, int y) : x(x), y(y) {}
    int x, y;
};


int main() {
    int n;
    cin >> n;
    cout << func(n) << endl;
    constexpr int m = func(12);
    cout << m << endl;
    
    constexpr A a(2, 3);

    return 0;
}
