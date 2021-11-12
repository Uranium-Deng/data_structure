/*************************************************************************
	> File Name: 2.deep_copy.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年08月02日 星期日 07时53分53秒
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
#include <cstring>
#include <vector>
using namespace std;

class A {
public :
    A() {
        this->arr = new int[100];
    }
    A(const A &obj) {
        this->arr = new int[100];
        memcpy(this->arr, obj.arr, sizeof(int) * 100);
        this->x = obj.x;
        this->y = obj.y;
    }
    int *arr;
    int x, y;
};


int main() {
    A a;
    a.x = 3, a.y = 6;
    A b = a;

    cout << a.arr[0] << " " << b.arr[0] << endl;
    a.arr[0] = 100;
    cout << a.arr[0] << " " << b.arr[0] << endl;
    b.arr[0] = 111;
    cout << a.arr[0] << " " << b.arr[0] << endl;

    cout << b.x << " " << b.y << endl;
    b.x = 6;
    cout << b.x << " " << b.y << endl;
    cout << a.x << " " << a.y << endl;

    return 0;
}
