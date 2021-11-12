/*************************************************************************
	> File Name: 35.template_turing.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年08月12日 星期三 15时51分00秒
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

template<int x>
struct IsOdd {
    constexpr static int r = x % 2;
};

// 模板在编译期无法实现循环，但是可以实现递归展开
// 循环和递归可以相互实现
template<int i, int x>
struct getNextK {
    constexpr static int r = (i * i > x ? 0 : (x % i == 0 ? 1 : 2));
};


template<int i, int x, int k> 
struct Test {
    constexpr static int r = Test<i + 1, x, getNextK<i, x>::r >::r;
};

template<int i, int x>
struct Test<i, x, 0> {
    constexpr static int r = 1;
};

template<int i, int x>
struct Test<i, x, 1> {
    constexpr static int r = 0;
};

template<int x> 
struct Is_prime {
    constexpr static int r = Test<2, x, 2>::r;
};


bool is_prime2(int i, int x) {
    if (i * i > x) return true; // k = 0
    if (x % i == 0) return false; // k = 1
    else return is_prime2(i + 1, x); // k = 2
}

bool is_prime(int x) {
    /*
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;*/
    return is_prime2(2, x);
}


int main() {
    cout << IsOdd<5>::r << endl;
    cout << IsOdd<6>::r << endl;

    cout << Is_prime<9973>::r << endl;
    cout << Is_prime<10000>::r << endl;
    
    return 0;
}
