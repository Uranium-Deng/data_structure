/*************************************************************************
	> File Name: 7.class_method.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年07月26日 星期日 19时43分41秒
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
public :
    Point() {
        Point::total_cnt += 1;
    }
    Point(int x, int y) : Point() {
        this->x = x;
        this->y = y;
    }
    static int T() {
        return Point::total_cnt;
    }

    ~Point() {
        Point::total_cnt -= 1;
    }

private :
    int x, y;
    static int total_cnt;
};


int Point::total_cnt = 0;

void test() {
    Point a;
    cout << Point::T() << endl;
}

int main() {
    Point a;
    cout << a.T() << endl;
    test();
    Point b;
    cout << b.T() << endl;


    return 0;
}
