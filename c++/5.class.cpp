/*************************************************************************
	> File Name: 5.class.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年07月25日 星期六 16时21分15秒
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

class People {
    // 声明友元函数，友元函数可以访问private的属性和方法
    friend int mian();
    int x, y;
public :
    void set(int x); 
    void say();
};

struct People2 {
    int x, y;
};

void People::set(int x) {
    cout << "set function : " << this << endl;
    this->x = x;
}

void People::say() {
    cout << x << " " << y << endl;
}

int main() {
    People a;
    People2 b;
    cout << "a object : " << &a << endl;
    a.set(3);
    a.y = 6;
    b.x = 4;
    a.say();
    cout << b.x << endl;




    return 0;
}
