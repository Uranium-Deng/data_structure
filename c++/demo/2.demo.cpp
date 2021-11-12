/*************************************************************************
	> File Name: 2.demo.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年09月28日 星期一 21时42分02秒
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


int main() {
    string s1 = "hello world";
    string s2 = move(s1);
    cout << s1 << endl;
        
    vector<int> v;
    v.push_back(10);
    vector<int> v1 = move(v);
    cout << v1[0] << endl;
        
    int a = 111;
    int b = move(a);
    cout << a << endl;

    map<int, int> mmap;
    for (int i = 0; i < 5; i++) {
        mmap[i] = i + 10;
    }
    map<int, int> m1;
    m1 = move(mmap);
    for (int i = 0; i < 5; i++) {
        cout << mmap[i] << " ";
    }
    cout << endl;

    return 0;
}



