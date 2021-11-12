/*************************************************************************
	> File Name: 3.static_const_method.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年07月29日 星期三 16时39分15秒
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


class Point {
public:
    Point();
    Point(int x, int y);

    int x();
    int y();
    void set_x(int x);
    void set_y(int y);

    static int output_cnt();

private:
    static int point_cnt;
    int __x, __y;
};

// 类属性的定义
int Point::point_cnt = 0;

int Point::output_cnt() {
    return Point::point_cnt;
}

Point::Point() {
    Point::point_cnt += 1;
}

Point::Point(int x, int y) : __x(x), __y(y) {
    Point::point_cnt += 1;
}

int Point::x() {
    return this->__x;
}

int Point::y() {
    return this->__y;
}

void Point::set_x(int x) {
    this->__x = x;
}

void Point::set_y(int y) {
    this->__y = y;
}


int main() {
    Point a(2, 3);
    cout << a.x() << " " << a.y() << endl;


    return 0;
}
