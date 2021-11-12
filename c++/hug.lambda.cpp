/*************************************************************************
	> File Name: hug.lambda.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年08月17日 星期一 10时50分13秒
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

int mul(int a, int b) {
    return a * b;
}

int add(int a, int b) {
    return a + b;
}

int main() {
    int n = 10000, m, x, y;
    auto a = [&](int a, int b) { return a + b + n; };
    n = 1000000;
    auto b = [&n](int a, int b) { return a + b + n; };
    auto c = [](function<int(int, int)> a, function<int(int, int)> b) {
        return [=](int x){
            return a(x, x) + b(x, x);
        };
    };
    cout << typeid(a).name() << endl;
    cout << typeid(b).name() << endl;
    cout << a(1, 2) << endl;
    cout << b(1, 2) << endl;
    auto d = c(a, b);
    auto e = c(add, mul);
    cout << d(12) << endl;
    cout << e(12) << endl;
    return 0;
}
