/*************************************************************************
	> File Name: 32.thread.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年08月13日 星期四 11时48分52秒
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
#include <thread>
using namespace std;

void func() {
    cout << "hello world" << endl;
}

void func2(int x) {
    cout << x << " hello world" << endl;
}

// 多线程编程，需要明确哪些资源再在临界区中
void func3(int &x) {
    // 多个线程都操作了x, 所以此处就是临界区
    x += 1;
    cout << x << "reference " << endl;
}

int main() {
    // 创建一个线程
    thread t1(func);
    // 等待线程结束
    t1.join();

    thread t4(func2, 56);
    t4.join();

    int n = 0;
    // ref(n) 表示传递的是一个引用
    thread t5(func3, ref(n));
    thread t6(func3, ref(n));
    thread t7(func3, ref(n));
    t5.join();
    t6.join();
    t7.join();
    cout << n << endl;

    return 0;
}
