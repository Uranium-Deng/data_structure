/*************************************************************************
	> File Name: 36.bind.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年08月13日 星期四 11时18分12秒
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

int add(int a, int b) {
    cout << "a = " << a << ", " << "b = " << b << endl;
    return a + b;
}

int add2(int a, int b, int c) {
    cout << "a = " << a << ", b = " << b << ", c = " << c;
    return a + b + c;
}

int add_cnt(function<int(int, int)> func, int &n, int a, int b) {
    n += 1;
    return func(a, b);
}

int main() {
    cout << add(3, 4) << endl;
    function<int(int)> f1 = bind(add, 5, placeholders::_1);
    // cout << f(3) << endl;
    // cout << f(4) << endl;
    f1(3), f1(4);
    // placeholders::num 中的num表示 placegolder绑定了前面哪个参数
    /*
    function<int(int, int)> f2 = bind(add, placeholders::_2, placeholders::_1);
    f2(3, 4), f2(4, 5);
    

    function<int(int, int, int)> f3 = bind(add2, placeholders::_2, 6, placeholders::_1);
    f3(9, 10);
    
    function<int(int, int, int)> f4 = bind(add2, placeholders::_1, placeholders::_3, placeholders::_2)
    */

    // 绑定一个可以统计函数执行次数的方法
    // bind 是一个模板方法,
    int n = 0;
    function<int(int, int)> f5 = bind(add_cnt, add, ref(n), placeholders::_1, placeholders::_2);
    f5(99, 88);
    f5(92, 80);
    f5(95, 78);
    cout << n << endl;
    
    

    return 0;
}
