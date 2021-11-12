/*************************************************************************
	> File Name: 1.demo.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年08月17日 星期一 10时57分52秒
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



int a = 2;

int mian() {
    auto inc = [&a]() {
        a++;
    };
    inc();
    inc();
    cout << a << endl;


    return 0;
}
