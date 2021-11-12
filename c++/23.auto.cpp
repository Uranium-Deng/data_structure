/*************************************************************************
	> File Name: 23.auto.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年08月02日 星期日 18时46分07秒
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


void func(auto x, auto y) {
    cout << x << " " << y << endl;
} 

int main() {
    auto a = 123;
    map<int, int> arr;
    arr[11212] = 12566513;
    arr[56156] = 4545;
    arr[24168] = 84868;
    for (auto iter = arr.begin(); iter != arr.end(); iter++) {
        cout << iter->first << " " << iter->second << endl;
    }
    for (auto a : arr) {
        cout << a.first << " " << a.second << endl;
    }
    int x = 2, y = 5;
    func(x, y);



    return 0;
}
