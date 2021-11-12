/*************************************************************************
	> File Name: 10.operator2.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年07月27日 星期一 19时20分39秒
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
    Point() : __x(0), __y(0) {}
    Point(int x, int y) : __x(x), __y(y) {}
    int x() const {return __x;}
    int y() const {return __y;}
    
    Point operator+(const Point &a) {
        return Point(x() + a.x(), y() + a.y());
    }

    Point &operator+=(const Point &b) {
        this->__x += b.x();
        this->__y += b.y();
        return *this;
    }
    // 前++
    Point &operator++() {
        this->__x += 1;
        this->__y += 1;
        return *this;
    }
    // 后++
    Point operator++(int) {
        Point tmp(*this);
        this->__x += 1;
        this->__y += 1;
        return tmp;
    }

private:
    int __x, __y;
};

ostream &operator<<(ostream &out, const Point &a) {
    out << "Point (" << a.x() << ", " << a.y() << ")";
    return out;
}


int main() {
    Point a(4, 5), b(3, 4), c(1, 1);
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << a + b << endl;
    
    cout << "before incr: " << ++(c += b) << endl;
    cout << c << endl;
    cout << "after incr: "  << c++ << endl;
    cout << c << endl;
    
    int n = 6, m = 7;
    (n += m)++;
    cout << n << endl;
        
    return 0;
}
