/*************************************************************************
	> File Name: 0.demo.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年08月17日 星期一 14时32分11秒
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


bool cmp(int a, int b) {
    return a > b;
}

struct CMP {
    bool operator()(int a ,int b) {
        return a > b;
    }
};

namespace haizei {

template<typename T>
struct greater {
    bool operator()(const T &a, const T &b) {
        return a > b;
    }
};    


template<typename T>
struct less {
    bool operator()(const T &a, const T &b) {
        return a < b;
    }
};    
} // end of haizei


int main() {
    srand(time(0));
    int arr[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 100;
    }
    // sort函数第三个参数是一个可调用对象
    // 包含: 普通函数, 函数对象, lambda表达式
    // sort(arr, arr + 10, [](int a, int b) {return a > b; });
    // sort(arr, arr + 10, CMP());
    sort(arr, arr + 10, haizei::greater<int>());
    sort(arr, arr + 10, haizei::less<int>());
    for (int i = 0; i < 10; i++) {
        i == 0 || cout << " ";
        cout << arr[i];
    }
    cout << endl;

    return 0;
}
