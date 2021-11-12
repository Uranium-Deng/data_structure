/*************************************************************************
	> File Name: array.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年08月20日 星期四 09时24分05秒
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


struct A {
public :
    int x;
};


struct B : public A {
public :
    int y;
};

// 这样的代码是有问题的
// 原因就是sizeof(A)和sizeof(B)的大小不一致
// 声明可知arr指针是A *类型的，所以arr[i] = arr + sizeof(A) * i;
// 但是sizeof(A)为sizeof(B)的一半
// 所以在访问时，肯定会错误

int mian() {
    A *arr = new B[10];
    arr[0];
    arr[1];
    return 0;
}
